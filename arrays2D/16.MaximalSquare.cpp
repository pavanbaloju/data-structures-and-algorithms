#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Intuition:
// The problem can be solved using dynamic programming, where we maintain a DP table to store the size of the largest square ending at each cell.
// We iterate through the matrix, and for each cell, we consider the previous row, previous column, and previous diagonal cells to compute the size of the square ending at that cell.

// DSA Strategy/Pattern: Dynamic Programming

// Approach 1: Memoization (Top-Down DP)
// - Use recursion with memoization to calculate the size of the largest square containing only 1's.
// - Maintain a memoization table to store computed results and avoid redundant calculations.

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n) for the memoization table.

// Function to recursively calculate the size of the largest square containing only 1's using memoization
int maximalSquareUtil(int r, int c, int &maxi, vector<vector<char>> &matrix, vector<vector<int>> &dp) {
    // Base case: If out of bounds, return 0
    if (r < 0 || c < 0)
        return 0;

    // If the result is already calculated, return it from the dp table
    if (dp[r][c] != -1)
        return dp[r][c];

    // Recursively find the size of the largest square considering three directions: right, down, and diagonal
    int right = maximalSquareUtil(r - 1, c, maxi, matrix, dp);
    int down = maximalSquareUtil(r, c - 1, maxi, matrix, dp);
    int diag = maximalSquareUtil(r - 1, c - 1, maxi, matrix, dp);

    // If the current cell is '1', calculate the size of the square and update the maximum size
    if (matrix[r][c] == '1') {
        int ans = 1 + (min(right, min(down, diag)));
        maxi = max(maxi, ans);
        return dp[r][c] = ans;
    }
    return dp[r][c] = 0;
}

// Function to find the size of the largest square containing only 1's using memoization approach
int maximalSquare(vector<vector<char>> &matrix) {
    // Get the dimensions of the matrix
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;

    // Create a memoization table to store computed results
    vector<vector<int>> dp(R, vector<int>(C, -1));

    // Call the utility function to find the size of the largest square
    maximalSquareUtil(R - 1, C - 1, maxi, matrix, dp);
    
    // Return the area of the largest square
    return maxi * maxi;
}

// Approach 2: Tabulation (Bottom-Up DP)
// - Use a bottom-up approach to fill a DP table where dp[i][j] represents the size of the largest square ending at position (i, j).
// - Iterate through the matrix and update the DP table based on the values of the previous row, previous column, and previous diagonal cells.

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m * n) for the DP table.

// Function to find the size of the largest square containing only 1's using tabulation approach
int maximalSquareTable(vector<vector<char>> &matrix) {
    // Get the dimensions of the matrix
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;

    // Create a DP table to store the size of the largest square ending at each cell
    vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));

    // Iterate through the matrix to fill the DP table
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            // If the current cell is '1', update the DP table
            if (matrix[r - 1][c - 1] == '1') {
                dp[r][c] = 1 + (min(dp[r - 1][c], min(dp[r][c - 1], dp[r - 1][c - 1])));
                maxi = max(maxi, dp[r][c]);
            }
        }
    }

    // Return the area of the largest square
    return maxi * maxi;
}

// Approach 3: Optimized Space (Space-Optimized DP)
// - Use two arrays to store the size of the largest square ending at the previous and current rows.
// - Update the current row array based on the previous row array, which reduces space complexity.

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(n) for the two arrays.

// Function to find the size of the largest square containing only 1's using optimized space approach
int maximalSquareOpt(vector<vector<char>> &matrix) {
    // Get the dimensions of the matrix
    int R = matrix.size(), C = matrix[0].size();
    int maxi = 0;

    // Create two arrays to store the size of the largest square ending at the previous and current rows
    vector<int> prev(C + 1, 0), curr(C + 1, 0);

    // Iterate through the matrix to update the current row array based on the previous row array
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            // If the current cell is '1', update the current row array
            if (matrix[r - 1][c - 1] == '1') {
               
                curr[c] = 1 + (min(prev[c], min(curr[c - 1], prev[c - 1])));
                maxi = max(maxi, curr[c]);
            } else {
                curr[c] = 0;
            }
        }
        // Update the previous row array for the next iteration
        prev = curr;
    }

    // Return the area of the largest square
    return maxi * maxi;
}

int main() {
    // Input binary matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}
    };

    // Output the size of the largest square using different approaches
    cout << "Maximal Square (Memoization): " << maximalSquare(matrix) << endl;
    cout << "Maximal Square (Tabulation): " << maximalSquareTable(matrix) << endl;
    cout << "Maximal Square (Optimized Space): " << maximalSquareOpt(matrix) << endl;

    return 0;
}
