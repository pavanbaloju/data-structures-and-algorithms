#include <vector>
#include <iostream>
using namespace std;

// recursion + memo
int cherryPickupUtil(int row, int colA, int colB, int n, int m, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    if (colA < 0 || colA >= m || colB < 0 || colB >= m)
        return INT_MIN;

    if (dp[row][colA][colB] != -1)
        return dp[row][colA][colB];

    int totalCherries = colA == colB ? matrix[row][colA] : matrix[row][colA] + matrix[row][colB];
    if (row == n - 1)
        return dp[row][colA][colB] = totalCherries;

    int maxi = INT_MIN;
    for (int cA : {-1, 0, 1})
    {
        for (int cB : {-1, 0, 1})
        {
            maxi = max(maxi, cherryPickupUtil(row + 1, colA + cA, colB + cB, n, m, matrix, dp));
        }
    }
    return dp[row][colA][colB] = maxi += totalCherries;
}

int cherryPickup(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return cherryPickupUtil(0, 0, m - 1, n, m, matrix, dp);
}

int cherryPickupUtilTable(int n, int m, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    for (int colA = 0; colA < m; colA++)
    {
        for (int colB = 0; colB < m; colB++)
        {
            dp[n - 1][colA][colB] = colA == colB ? matrix[n - 1][colA] : matrix[n - 1][colA] + matrix[n - 1][colB];
        }
    }

    for (int row = n - 2; row >= 0; row--)
    {
        for (int colA = 0; colA < m; colA++)
        {
            for (int colB = 0; colB < m; colB++)
            {
                int maxi = INT_MIN;
                int totalCherries = colA == colB ? matrix[row][colA] : matrix[row][colA] + matrix[row][colB];
                for (int cA : {-1, 0, 1})
                {
                    for (int cB : {-1, 0, 1})
                    {
                        int ans;
                        if ((colA + cA < 0 || colA + cA >= m) || (colB + cB < 0 || colB + cB >= m))
                            ans = INT_MIN;
                        else
                            ans = dp[row + 1][colA + cA][colB + cB];
                        maxi = max(maxi, ans);
                    }
                }
                dp[row][colA][colB] = maxi += totalCherries;
            }
        }
    }
    return dp[0][0][m - 1];
}

int cherryPickupTable(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return cherryPickupUtilTable(n, m, matrix, dp);
}

int cherryPickupOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));
    for (int colA = 0; colA < m; colA++)
    {
        for (int colB = 0; colB < m; colB++)
        {
            front[colA][colB] = colA == colB ? matrix[n - 1][colA] : matrix[n - 1][colA] + matrix[n - 1][colB];
        }
    }

    for (int row = n - 2; row >= 0; row--)
    {
        for (int colA = 0; colA < m; colA++)
        {
            for (int colB = 0; colB < m; colB++)
            {
                int maxi = INT_MIN;
                int totalCherries = colA == colB ? matrix[row][colA] : matrix[row][colA] + matrix[row][colB];
                for (int cA : {-1, 0, 1})
                {
                    for (int cB : {-1, 0, 1})
                    {
                        int ans;
                        if ((colA + cA < 0 || colA + cA >= m) || (colB + cB < 0 || colB + cB >= m))
                            ans = INT_MIN;
                        else
                            ans = front[colA + cA][colB + cB];
                        maxi = max(maxi, ans);
                    }
                }
                cur[colA][colB] = maxi += totalCherries;
            }
        }
        front = cur;
    }
    return front[0][m - 1];
}

int main()
{
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };
    cout << cherryPickup(matrix) << endl;
    cout << cherryPickupTable(matrix) << endl;
    cout << cherryPickupOpt(matrix) << endl;
    return 0;
}
