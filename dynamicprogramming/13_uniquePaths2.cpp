#include <iostream>
#include <vector>
using namespace std;

// simple recursion
int uniquePathsWithObstacles(int m, int n, vector<vector<int>> obstacleGrid)
{
    if (m > 0 && n > 0 && obstacleGrid[m][n] == 1)
        return 0;

    if (m == 0 || n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    return uniquePathsWithObstacles(m - 1, n, obstacleGrid) + uniquePathsWithObstacles(m, n - 1, obstacleGrid);
}

// recursion + memo
int solveMemo(int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    if (m > 0 && n > 0 && obstacleGrid[m][n] == 1)
        return 0;
    if (m == 0 || n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = (solveMemo(m - 1, n, dp, obstacleGrid) + solveMemo(m, n - 1, dp, obstacleGrid));
}
int uniquePathsWithObstaclesMemo(int m, int n, vector<vector<int>> obstacleGrid)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveMemo(m - 1, n - 1, dp, obstacleGrid);
}

// table
int solveTable(int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && i > 0 && obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 || j == 0)
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
int uniquePathsWithObstaclesTable(int m, int n, vector<vector<int>> obstacleGrid)
{
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, -1));
    return solveTable(m, n, dp, obstacleGrid);
}

// opt
int uniquePathsWithObstaclesOpt(int m, int n, vector<vector<int>> obstacleGrid)
{
    vector<int> prevRow(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            {
                currRow[j] = 0;
            }
            else if (i == 0 && j == 0)
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
    vector<vector<int>> obstacleGrid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    cout << uniquePathsWithObstacles(n - 1, m - 1, obstacleGrid) << endl;
    cout << uniquePathsWithObstaclesMemo(n, m, obstacleGrid) << endl;
    cout << uniquePathsWithObstaclesTable(n, m, obstacleGrid) << endl;
    cout << uniquePathsWithObstaclesOpt(n, m, obstacleGrid) << endl;
}