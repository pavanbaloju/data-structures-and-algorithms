#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an m x n grid where some cells are obstacles, find the number of unique paths from the top-left corner to the bottom-right corner.
// The robot can only move either down or right at any point in time.

// Intuition:
// The problem can be broken down into smaller subproblems where the number of unique paths to a cell is the sum of the unique paths to the cell directly above it and the cell directly to the left of it.
// This is only valid if those cells are not obstacles.

// DSA Strategy/Pattern: Dynamic Programming

// Approach 1: Simple Recursion
// 1. Use a recursive function to explore all possible paths to the destination.
// 2. Base cases: If the current cell is an obstacle, return 0. If we reach the top-left corner, return 1.
// 3. Recursive case: Sum the number of paths from the cell above and the cell to the left.

// - Time Complexity: O(2^(m+n)) - Exponential
// - Space Complexity: O(m+n) - Recursive stack space
int uniquePathsWithObstacles(int m, int n, vector<vector<int>> obstacleGrid)
{
    // If the current cell is an obstacle, return 0
    if (m >= 0 && n >= 0 && obstacleGrid[m][n] == 1)
    {
        return 0;
    }
    // If we reach the top-left corner, return 1
    if (m == 0 && n == 0)
    {
        return 1;
    }
    // If we are out of bounds, return 0
    if (m < 0 || n < 0)
    {
        return 0;
    }
    // Recursive calls to the cell above and the cell to the left
    return uniquePathsWithObstacles(m - 1, n, obstacleGrid) + uniquePathsWithObstacles(m, n - 1, obstacleGrid);
}

// Approach 2: Recursion with Memoization
// 1. Use a DP table to store the results of subproblems and avoid recomputation.
// 2. Initialize the DP table with -1 to indicate uncomputed cells.
// 3. Use a helper function to implement the memoized recursion.
// - Time Complexity: O(m*n)
// - Space Complexity: O(m*n) - Memoization table
int solveMemo(int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    // If the current cell is an obstacle, return 0
    if (m >= 0 && n >= 0 && obstacleGrid[m][n] == 1)
    {
        return 0;
    }
    // If we reach the top-left corner, return 1
    if (m == 0 && n == 0)
    {
        return 1;
    }
    // If we are out of bounds, return 0
    if (m < 0 || n < 0)
    {
        return 0;
    }
    // If the result is already computed, return it
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    // Store the result in the DP table and return it
    return dp[m][n] = (solveMemo(m - 1, n, dp, obstacleGrid) + solveMemo(m, n - 1, dp, obstacleGrid));
}

int uniquePathsWithObstaclesMemo(int m, int n, vector<vector<int>> obstacleGrid)
{
    // Initialize the DP table with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the memoized function
    return solveMemo(m - 1, n - 1, dp, obstacleGrid);
}

// Approach 3: Dynamic Programming Table
// 1. Use a DP table to store the number of paths to each cell.
// 2. Initialize the first row and first column considering the obstacles.
// 3. Fill the DP table based on the number of paths from the cell above and the cell to the left.
// - Time Complexity: O(m*n)
// - Space Complexity: O(m*n) - DP table

int solveTable(int m, int n, vector<vector<int>> &dp, vector<vector<int>> obstacleGrid)
{
    // Initialize the DP table
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If the current cell is an obstacle, set paths to 0
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                // Starting point has 1 path
                dp[i][j] = 1;
            }
            else
            {
                // Number of paths to the current cell is the sum of paths from the cell above and the cell to the left
                dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
            }
        }
    }
    // Return the number of paths to the bottom-right corner
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstaclesTable(int m, int n, vector<vector<int>> obstacleGrid)
{
    // Initialize the DP table
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the table-based DP function
    return solveTable(m, n, dp, obstacleGrid);
}

// Approach 4: Optimized Dynamic Programming (Space Optimization)
// 1. Use two 1D arrays to store the number of paths for the current and previous rows.
// 2. Update the current row based on the previous row and the current row values.
// - Time Complexity: O(m*n)
// - Space Complexity: O(n) - Space optimized

int uniquePathsWithObstaclesOpt(int m, int n, vector<vector<int>> obstacleGrid)
{
    // Initialize the previous row
    vector<int> prevRow(n, 0);
    // Iterate over each row
    for (int i = 0; i < m; i++)
    {
        // Initialize the current row
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            // If the current cell is an obstacle, set paths to 0
            if (obstacleGrid[i][j] == 1)
            {
                currRow[j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                // Starting point has 1 path
                currRow[j] = 1;
            }
            else
            {
                // Number of paths to the current cell is the sum of paths from the cell above and the cell to the left
                int up = (i > 0) ? prevRow[j] : 0;
                int left = (j > 0) ? currRow[j - 1] : 0;
                currRow[j] = up + left;
            }
        }
        // Update the previous row for the next iteration
        prevRow = currRow;
    }
    // Return the number of paths to the bottom-right corner
    return prevRow[n - 1];
}

int main()
{
    // Sample obstacle grid
    vector<vector<int>> obstacleGrid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();

    // Test each method of finding unique paths with obstacles
    cout << "Simple Recursion: " << uniquePathsWithObstacles(n - 1, m - 1, obstacleGrid) << endl;
    cout << "Recursion with Memoization: " << uniquePathsWithObstaclesMemo(n, m, obstacleGrid) << endl;
    cout << "Dynamic Programming Table: " << uniquePathsWithObstaclesTable(n, m, obstacleGrid) << endl;
    cout << "Optimized Dynamic Programming: " << uniquePathsWithObstaclesOpt(n, m, obstacleGrid) << endl;

    return 0;
}
