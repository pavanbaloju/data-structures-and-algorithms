#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the number of unique paths from top-left to bottom-right using simple recursion.
// Intuition:
// - At each cell, there are two choices: either go right or go down.
// - Recursive calls are made for each choice until reaching the destination.
// - Base cases are when either of the dimensions becomes 0.
// Approach:
// - If either of the dimensions is 0, return 1.
// - If both dimensions are negative, return 0.
// - Recursively calculate the number of unique paths by considering the sum of paths from the cell above and the cell to the left.
// Time complexity: O(2^(m+n)), where m and n are the dimensions of the grid.
// Space complexity: O(m+n) due to the recursive call stack.
int uniquePaths(int m, int n)
{
    if (m == 0 || n == 0)
        return 1; // Base case: If either dimension is 0, there is only one path.
    if (m < 0 || n < 0)
        return 0; // Base case: If both dimensions are negative, no path exists.

    // Recursive calls for the two choices: going right and going down.
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

// Function to calculate the number of unique paths using recursion with memoization.
// Intuition:
// - Memoization is used to store the results of overlapping subproblems to avoid redundant calculations.
// - The memoization table dp is initialized with -1 and updated with calculated values.
// Approach:
// - If either of the dimensions is 0, return 1.
// - If both dimensions are negative, return 0.
// - Check if the result for the current cell is already calculated in the memoization table.
// - Recursively calculate the number of unique paths by considering the sum of paths from the cell above and the cell to the left.
// Time complexity: O(m*n), where m and n are the dimensions of the grid.
// Space complexity: O(m*n) for the memoization table.
int solveMemo(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 1; // Base case: If either dimension is 0, there is only one path.
    if (m < 0 || n < 0)
        return 0; // Base case: If both dimensions are negative, no path exists.
    if (dp[m][n] != -1)
        return dp[m][n]; // Return the memoized result if available.

    // Recursively calculate the number of unique paths and store the result in the memoization table.
    return dp[m][n] = (solveMemo(m - 1, n, dp) + solveMemo(m, n - 1, dp));
}

int uniquePathsMemo(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize the memoization table.
    return solveMemo(m - 1, n - 1, dp);
}

// Function to calculate the number of unique paths using dynamic programming (tabulation).
// Intuition:
// - The DP table dp[m][n] stores the number of unique paths to reach cell (m,n).
// - Each cell (i,j) can be reached from either above (i-1,j) or left (i,j-1) cell.
// - The base cases are the top row (i=0) and leftmost column (j=0), where there's only one path.
// Approach:
// - Initialize a DP table with dimensions m x n and set base cases for the top row and leftmost column.
// - Iterate through the grid, updating each cell with the sum of paths from the cell above and the cell to the left.
// Time complexity: O(m*n), where m and n are the dimensions of the grid.
// Space complexity: O(m*n) for the DP table.
int solveTable(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1; // Base case: There is only one path in the top row and leftmost column.
            }
            else
            {
                // Update the current cell with the sum of paths from the cell above and the cell to the left.
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1]; // Return the number of unique paths to reach the bottom-right cell.
}

int uniquePathsTable(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize the DP table.
    return solveTable(m, n, dp);
}

// Function to calculate the number of unique paths using optimized dynamic programming.
// Intuition:
// - Instead of using a 2D DP table, a 1D array prevRow is used to store the previous row's values.
// - At each iteration, the current row's values are calculated based on the previous row's values.
// Approach:
// - Initialize a 1D array prevRow with size n and set the base case for the starting cell.
// - Iterate through each row, updating the current row's values based on the previous row.
// - Use the previous row's values to calculate the sum of paths from the cell above and the cell to the left.
// Time complexity: O(m*n), where m and n are the dimensions of the grid.
// Space complexity: O(n) for the previous row array.
int uniquePathsOpt(int m, int n)
{
    vector<int> prevRow(n, 0); // Initialize the array to store the previous row's values.
    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0); // Initialize the current row's values.
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                currRow[j] = 1; // Base case: There is only one path to the starting cell.
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prevRow[j]; // Get the value from the cell above.
                if (j > 0)
                    left = currRow[j - 1]; // Get the value from the cell to the left.

                currRow[j] = up + left; // Update the current cell with the sum of paths.
            }
        }
        prevRow = currRow; // Update the previous row's values.
    }
    return prevRow[n - 1]; // Return the number of unique paths to reach the bottom-right cell.
}

// Function to calculate the number of unique paths using the combinatorial formula (nCr).
// Intuition:
// - The total number of steps to reach the destination is (m-1) + (n-1) = m + n - 2.
// - Out of these steps, m-1 steps are right (R) and n-1 steps are down (D).
// - The total number of unique paths is the number of combinations of choosing m-1 R's or n-1 D's.
// Approach:
// - Calculate the total number of steps (N) and the number of steps to the right (r).
// - Use the combinatorial formula (nCr) to compute the total number of unique paths.
// Time complexity: O(min(m, n)), since it involves computing factorials.
// Space complexity: O(1).
int uniquePathsNCR(int m, int n)
{
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res; // Return the total number of unique paths.
}

int main()
{
    cout << uniquePaths(2, 6) << endl;      // Output: 10
    cout << uniquePathsMemo(3, 7) << endl;  // Output: 28
    cout << uniquePathsTable(3, 7) << endl; // Output: 28
    cout << uniquePathsOpt(3, 7) << endl;   // Output: 28
    cout << uniquePathsNCR(3, 7) << endl;   // Output: 28
    return 0;
}
