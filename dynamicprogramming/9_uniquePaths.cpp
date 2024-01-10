#include <iostream>
#include <vector>
using namespace std;

// simple recursion
int uniquePaths(int m, int n)
{
    if (m == 0 || n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

// recursion + memo
int solveMemo(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = (solveMemo(m - 1, n, dp) + solveMemo(m, n - 1, dp));
}
int uniquePathsMemo(int m, int n)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveMemo(m - 1, n - 1, dp);
}

// table
int solveTable(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePathsTable(int m, int n)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveTable(m, n, dp);
}

// opt
int uniquePathsOpt(int m, int n)
{
    vector<int> prevRow(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                currRow[j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prevRow[j];

                if (j > 0)
                    left = currRow[j - 1];

                currRow[j] = up + left;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n - 1];
}

int main()
{
    cout << uniquePaths(2, 6) << endl;
    cout << uniquePathsMemo(3, 7) << endl;
    cout << uniquePathsTable(3, 7) << endl;
    cout << uniquePathsOpt(3, 7) << endl;
}