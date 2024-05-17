#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement:
// Given an m x n grid filled with non-negative numbers, find a path from the top left to the bottom right
// which minimizes the sum of all numbers along its path. You can only move either down or right at any point in time.

// Intuition:
// The problem can be solved by breaking it into subproblems where the minimum path sum to a cell is the minimum of
// the path sum from the cell directly above or the cell directly to the left, plus the value of the current cell.

// DSA Strategy/Pattern: Dynamic Programming

// Approach 1: Simple Recursion
// 1. Use a recursive function to explore all possible paths to the destination.
// 2. Base cases: If we reach the top-left corner, return its value. If out of bounds, return a large value (INT_MAX).
// 3. Recursive case: Add the value of the current cell to the minimum of the path sums from the cell above and the cell to the left.
int minPathSum(int m, int n, vector<vector<int>> &weights)
{
    // Base case: If we are at the top-left corner, return its value
    if (m == 0 && n == 0)
        return weights[0][0];
    // Base case: If we are out of bounds, return a large value
    if (m < 0 || n < 0)
        return INT_MAX;
    // Recursive calls to the cell above and the cell to the left
    return weights[m][n] + min(minPathSum(m - 1, n, weights), minPathSum(m, n - 1, weights));
}

// Approach 2: Recursion with Memoization
// 1. Use a DP table to store the results of subproblems and avoid recomputation.
// 2. Initialize the DP table with -1 to indicate uncomputed cells.
// 3. Use a helper function to implement the memoized recursion.
int solveMemo(int m, int n, vector<vector<int>> &dp, vector<vector<int>> weights)
{
    // Base case: If we are at the top-left corner, return its value
    if (m == 0 && n == 0)
        return weights[0][0];
    // Base case: If we are out of bounds, return a large value
    if (m < 0 || n < 0)
        return INT_MAX;
    // If the result is already computed, return it
    if (dp[m][n] != -1)
        return dp[m][n];
    // Store the result in the DP table and return it
    return dp[m][n] = weights[m][n] + min(solveMemo(m - 1, n, dp, weights), solveMemo(m, n - 1, dp, weights));
}

int minPathSumMemo(int m, int n, vector<vector<int>> weights)
{
    // Initialize the DP table with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the memoized function
    return solveMemo(m - 1, n - 1, dp, weights);
}

// Approach 3: Dynamic Programming Table
// 1. Use a DP table to store the minimum path sum to each cell.
// 2. Initialize the first cell with its value since it's the starting point.
// 3. Fill the DP table based on the minimum path sum from the cell above and the cell to the left.
int solveTable(int m, int n, vector<vector<int>> &dp, vector<vector<int>> weights)
{
    // Iterate over each cell in the DP table
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                // Starting point
                dp[i][j] = weights[0][0];
            }
            else
            {
                // Minimum path sum to the current cell is the value of the current cell plus the minimum of the path sums from the cell above and the cell to the left
                int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = weights[i][j] + min(up, left);
            }
        }
    }
    // Return the minimum path sum to the bottom-right corner
    return dp[m - 1][n - 1];
}

int minPathSumTable(int m, int n, vector<vector<int>> weights)
{
    // Initialize the DP table
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the table-based DP function
    return solveTable(m, n, dp, weights);
}

// Approach 4: Optimized Dynamic Programming (Space Optimization)
// 1. Use two 1D arrays to store the minimum path sum for the current and previous rows.
// 2. Update the current row based on the previous row and the current row values.
int minPathSumOpt(int m, int n, vector<vector<int>> weights)
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
            if (i == 0 && j == 0)
            {
                // Starting point
                currRow[j] = weights[0][0];
            }
            else
            {
                // Minimum path sum to the current cell is the value of the current cell plus the minimum of the path sums from the cell above and the cell to the left
                int up = (i > 0) ? prevRow[j] : INT_MAX;
                int left = (j > 0) ? currRow[j - 1] : INT_MAX;
                currRow[j] = weights[i][j] + min(up, left);
            }
        }
        // Update the previous row for the next iteration
        prevRow = currRow;
    }
    // Return the minimum path sum to the bottom-right corner
    return prevRow[n - 1];
}

int main()
{
    vector<vector<int>> weights{
        {5, 9, 6},
        {11, 5, 2}};
    int m = weights.size(), n = weights[0].size();
    cout << "Simple Recursion: " << minPathSum(m - 1, n - 1, weights) << endl;
    cout << "Recursion with Memoization: " << minPathSumMemo(m, n, weights) << endl;
    cout << "Dynamic Programming Table: " << minPathSumTable(m, n, weights) << endl;
    cout << "Optimized Dynamic Programming: " << minPathSumOpt(m, n, weights) << endl;

    return 0;
}
