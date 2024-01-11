#include <vector>
#include <iostream>
using namespace std;

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return INT_MIN;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSumMemo(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int ans = getMaxUtil(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }
    return maxi;
}

int getMaxPathSumTable(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = dp[i - 1][j];
            int leftDiagonal;
            if (j - 1 >= 0)
            {
                leftDiagonal = dp[i - 1][j - 1];
            }
            else
            {
                leftDiagonal = INT_MIN;
            }

            int rightDiagonal;
            if (j + 1 < m)
            {
                rightDiagonal = dp[i - 1][j + 1];
            }
            else
            {
                rightDiagonal = INT_MIN;
            }
            dp[i][j] = matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}

int getMaxPathSumOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);
    vector<int> cur(m, 0);
    prev = matrix[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = prev[j];
            int leftDiagonal;
            if (j - 1 >= 0)
            {
                leftDiagonal = prev[j - 1];
            }
            else
            {
                leftDiagonal = INT_MIN;
            }

            int rightDiagonal;
            if (j + 1 < m)
            {
                rightDiagonal = prev[j + 1];
            }
            else
            {
                rightDiagonal = INT_MIN;
            }

            cur[j] = matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}

int main()
{

    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    cout << getMaxPathSumMemo(matrix) << endl;
    cout << getMaxPathSumTable(matrix) << endl;
    cout << getMaxPathSumOpt(matrix) << endl;

    return 0;
}
