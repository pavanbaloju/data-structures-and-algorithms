#include <iostream>
#include <vector>
using namespace std;

// simple recursion
int minPathSum(int m, int n, vector<vector<int>> &weights)
{
    if (m == 0 && n == 0)
        return weights[0][0];
    if (m < 0 || n < 0)
        return INT_MAX;

    return weights[m][n] + min(minPathSum(m - 1, n, weights), minPathSum(m, n - 1, weights));
}

// recursion + memo
int solveMemo(int m, int n, vector<vector<int>> &dp, vector<vector<int>> weights)
{
    if (m == 0 && n == 0)
        return weights[0][0];
    if (m < 0 || n < 0)
        return INT_MAX;
    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = weights[m][n] + min(solveMemo(m - 1, n, dp, weights), solveMemo(m, n - 1, dp, weights));
}
int minPathSumMemo(int m, int n, vector<vector<int>> weights)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveMemo(m - 1, n - 1, dp, weights);
}

// table
int solveTable(int m, int n, vector<vector<int>> &dp, vector<vector<int>> weights)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = weights[0][0];
            }
            else
            {
                int up = i > 0 ? dp[i - 1][j] : INT_MAX;
                int left = j > 0 ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = weights[i][j] + min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}
int minPathSumTable(int m, int n, vector<vector<int>> weights)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveTable(m, n, dp, weights);
}

// opt
int minPathSumOpt(int m, int n, vector<vector<int>> weights)
{
    vector<int> prevRow(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                currRow[j] = weights[0][0];
            }
            else
            {
                int up = i > 0 ? prevRow[j] : INT_MAX;
                int left = j > 0 ? currRow[j - 1] : INT_MAX;
                currRow[j] = weights[i][j] + min(up, left);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n - 1];
}

int main()
{
    vector<vector<int>> weights{
        {5, 9, 6},
        {11, 5, 2}};
    int m = weights.size(), n = weights[0].size();
    cout << minPathSum(m - 1, n - 1, weights) << endl;
    cout << minPathSumMemo(m, n, weights) << endl;
    cout << minPathSumTable(m, n, weights) << endl;
    cout << minPathSumOpt(m, n, weights) << endl;
}