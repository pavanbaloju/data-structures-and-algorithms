#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an m x n grid, find the number of unique paths from the top-left corner to the bottom-right corner.
// The robot can only move either down or right at any point in time.

// Intuition:
// The problem can be broken down into smaller subproblems where the number of unique paths to a cell is the sum of the unique paths to the cell directly above it and the cell directly to the left of it.

// DSA Strategy/Pattern: Dynamic Programming

// Approach 1: Simple Recursion
// 1. Use a recursive function to explore all possible paths to the destination.
// 2. Base cases: If we reach the top row or leftmost column, return 1.
// 3. Recursive case: Sum the number of paths from the cell above and the cell to the left.

// Time Complexity: O(2^(m+n)) - Exponential
// Space Complexity: O(m+n) - Recursive stack space
int uniquePaths(int m, int n)
{
    // Base case: If we are at the top row or leftmost column, there is only 1 path
    if (m == 0 || n == 0)
        return 1;
    // Base case: If we are out of bounds, return 0
    if (m < 0 || n < 0)
        return 0;
    // Recursive calls to the cell above and the cell to the left
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

// Approach 2: Recursion with Memoization
// 1. Use a DP table to store the results of subproblems and avoid recomputation.
// 2. Initialize the DP table with -1 to indicate uncomputed cells.
// 3. Use a helper function to implement the memoized recursion.

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) - Memoization table
int solveMemo(int m, int n, vector<vector<int>> &dp)
{
    // Base case: If we are at the top row or leftmost column, there is only 1 path
    if (m == 0 || n == 0)
        return 1;
    // Base case: If we are out of bounds, return 0
    if (m < 0 || n < 0)
        return 0;
    // If the result is already computed, return it
    if (dp[m][n] != -1)
        return dp[m][n];
    // Store the result in the DP table and return it
    return dp[m][n] = solveMemo(m - 1, n, dp) + solveMemo(m, n - 1, dp);
}

int uniquePathsMemo(int m, int n)
{
    // Initialize the DP table with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the memoized function
    return solveMemo(m - 1, n - 1, dp);
}

// Approach 3: Dynamic Programming Table
// 1. Use a DP table to store the number of paths to each cell.
// 2. Initialize the first row and first column to 1 since there's only one way to get to those cells.
// 3. Fill the DP table based on the number of paths from the cell above and the cell to the left.

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) - DP table
int solveTable(int m, int n, vector<vector<int>> &dp)
{
    // Iterate over each cell in the DP table
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If we are at the top row or leftmost column, there is only 1 path
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                // Number of paths to the current cell is the sum of paths from the cell above and the cell to the left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    // Return the number of paths to the bottom-right corner
    return dp[m - 1][n - 1];
}

int uniquePathsTable(int m, int n)
{
    // Initialize the DP table
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Call the table-based DP function
    return solveTable(m, n, dp);
}

// Approach 4: Optimized Dynamic Programming (Space Optimization)
// 1. Use two 1D arrays to store the number of paths for the current and previous rows.
// 2. Update the current row based on the previous row and the current row values.

// Time Complexity: O(m*n)
// Space Complexity: O(n) - Space optimized
int uniquePathsOpt(int m, int n)
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
            // If we are at the top-left corner, there's only 1 path
            if (i == 0 && j == 0)
            {
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

// Approach 5: Combinatorial Solution
// 1. Use the combinatorial formula to compute the number of unique paths.
// 2. The number of unique paths from (0,0) to (m-1,n-1) is given by the binomial coefficient C(m+n-2, m-1) or C(m+n-2, n-1).

// Time Complexity: O(1)
// Space Complexity: O(1)
int uniquePathsNCR(int m, int n)
{
    int N = m + n - 2;         // Total steps to be taken
    int r = min(m - 1, n - 1); // Choose the smaller of (m-1) and (n-1)
    double res = 1;
    // Compute the binomial coefficient C(N, r)
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

int main()
{
    cout << "Simple Recursion: " << uniquePaths(2, 6) << endl;
    cout << "Recursion with Memoization: " << uniquePathsMemo(3, 7) << endl;
    cout << "Dynamic Programming Table: " << uniquePathsTable(3, 7) << endl;
    cout << "Optimized Dynamic Programming: " << uniquePathsOpt(3, 7) << endl;
    cout << "Combinatorial Solution: " << uniquePathsNCR(3, 7) << endl;

    return 0;
}
