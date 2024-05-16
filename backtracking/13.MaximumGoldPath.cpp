#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a 2D grid representing a gold mine, each cell in the grid contains a non-negative integer 
// representing the amount of gold in that cell. You start at the top-left corner and can move 
// horizontally or vertically to adjacent cells. You can collect gold from any cell, but you 
// cannot visit the same cell more than once. What is the maximum amount of gold you can collect?

// Intuition:
// We can use backtracking to explore all possible paths starting from each cell containing gold. 
// At each step, we choose to move in one of the four directions (up, down, left, or right) and 
// collect the gold in the current cell. We then recursively explore the next cells. We keep track 
// of the maximum amount of gold collected so far.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// 1. Define a recursive function 'backtrack' to explore all possible paths from a given cell.
//    - Base cases: If the cell is out of bounds or does not contain gold, return 0.
//    - Mark the current cell as visited and collect the gold in it.
//    - Explore all four directions (up, down, left, right) recursively and sum the gold collected.
//    - Restore the grid by marking the current cell as unvisited.
//    - Return the maximum amount of gold collected.
// 2. Define the 'getMaximumGold' function to find the maximum amount of gold that can be collected.
//    - Initialize maxGold to 0.
//    - Explore each cell in the grid.
//    - If the cell contains gold, call the 'backtrack' function to explore all possible paths 
//      starting from that cell and update maxGold accordingly.
//    - Return maxGold.
// 3. Example usage: Create a sample grid and call 'getMaximumGold' to find the maximum amount of gold.

// Time Complexity: O(m * n * 4^k) where m is the number of rows, n is the number of columns, 
//                  and k is the maximum amount of gold collected.
// Space Complexity: O(m * n) for the recursion stack.

// Function to perform backtracking to find the maximum amount of gold starting from a given cell
int backtrack(vector<vector<int>> &grid, int row, int col)
{
    int m = grid.size();
    int n = grid[0].size();

    // Base cases: out of bounds or no gold in this cell
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
    {
        return 0;
    }

    int gold = grid[row][col];
    grid[row][col] = 0; // Mark this cell as visited

    int maxGold = gold; // Initialize maxGold with the gold in the current cell

    // Explore all four directions
    maxGold += max({backtrack(grid, row - 1, col), backtrack(grid, row + 1, col),
                    backtrack(grid, row, col - 1), backtrack(grid, row, col + 1)});

    grid[row][col] = gold; // Restore the grid

    return maxGold;
}

// Function to find the maximum amount of gold that can be collected starting from any cell
int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxGold = 0;

    // Explore each cell in the grid
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] != 0)
            {                                                  // Start from cells containing gold
                maxGold = max(maxGold, backtrack(grid, i, j)); // Update maxGold
            }
        }
    }

    return maxGold;
}

int main()
{
    // Example usage
    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}};

    int maxGold = getMaximumGold(grid); // Find the maximum amount of gold
    cout << "Maximum amount of gold that can be collected: " << maxGold << endl;

    return 0;
}
