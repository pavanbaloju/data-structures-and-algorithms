#include <iostream>
#include <vector>
using namespace std;

int maximalSquareUtil(int r, int c, int &maxi, vector<vector<char>> &matrix, vector<vector<int>> &dp)
{
    if (r < 0 || c < 0)
        return 0;

    if (dp[r][c] != -1)
        return dp[r][c];

    int right = maximalSquareUtil(r - 1, c, maxi, matrix, dp);
    int down = maximalSquareUtil(r, c - 1, maxi, matrix, dp);
    int diag = maximalSquareUtil(r - 1, c - 1, maxi, matrix, dp);

    if (matrix[r][c] == '1')
    {
        int ans = 1 + (min(right, min(down, diag)));
        maxi = max(maxi, ans);
        return dp[r][c] = ans;
    }
    return dp[r][c] = 0;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;
    vector<vector<int>> dp(R, vector<int>(C, -1));
    maximalSquareUtil(R - 1, C - 1, maxi, matrix, dp);
    return maxi * maxi;
}

int maximalSquareTable(vector<vector<char>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;
    vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));

    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            if (matrix[r - 1][c - 1] == '1')
            {
                dp[r][c] = 1 + (min(dp[r - 1][c], min(dp[r][c - 1], dp[r - 1][c - 1])));
                maxi = max(maxi, dp[r][c]);
            }
        }
    }
    return maxi * maxi;
}

int maximalSquareOpt(vector<vector<char>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;
    vector<int> prev(C + 1, 0), curr(C + 1, 0);

    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            if (matrix[r - 1][c - 1] == '1')
            {
                curr[c] = 1 + (min(prev[c], min(curr[c - 1], prev[c - 1])));
                maxi = max(maxi, curr[c]);
            }
            else
            {
                curr[c] = 0;
            }
        }
        prev = curr;
    }
    return maxi * maxi;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}};

    cout << maximalSquare(matrix) << endl;
    cout << maximalSquareTable(matrix) << endl;
    cout << maximalSquareOpt(matrix) << endl;
    return 0;
}