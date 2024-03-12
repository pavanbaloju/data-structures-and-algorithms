#include <iostream>  // Include the input/output stream library
#include <vector>    // Include the vector library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given a 2D grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// Assume all four edges of the grid are all surrounded by water.

// Intuition:
// We can solve this problem using Depth-First Search (DFS).
// We iterate through each cell of the grid. When we encounter a cell with '1',
// we mark it as visited and recursively mark all adjacent '1's as visited too.
// Each connected group of '1's represents an island.

// DSA Strategy:
// 1. Create a function to mark visited cells of an island using Depth-First Search (DFS).
// 2. Traverse the grid. When encountering a cell with '1', mark the island visited and increment the island count.
// 3. In the DFS function, recursively mark all adjacent '1's as visited.
// 4. Return the island count.

// Approach:
// 1. Create a function markIslandVisited to mark visited cells of an island.
//    a. Base cases: Out of bounds or water cell ('0').
//    b. Mark the current cell as visited.
//    c. Visit adjacent cells recursively.
// 2. Create a function numIslands to count the number of islands.
//    a. Initialize the island count to 0.
//    b. Traverse the grid.
//       i. If land ('1') is found, mark the island visited and increment the island count.
// 3. Call the numIslands function in the main method with the given grid.
// 4. Print the number of islands.

// Time Complexity: O(M * N), where M is the number of rows and N is the number of columns in the grid.
// Space Complexity: O(M * N), where M is the number of rows and N is the number of columns in the grid.

// Function to mark visited cells of an island using Depth-First Search (DFS)
void markIslandVisited(vector<vector<char>> &grid, int i, int j)
{
    // Base cases: Out of bounds or water cell ('0')
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
        return;

    // Mark the current cell as visited
    grid[i][j] = '0';

    // Visit adjacent cells recursively
    markIslandVisited(grid, i - 1, j); // Up
    markIslandVisited(grid, i + 1, j); // Down
    markIslandVisited(grid, i, j - 1); // Left
    markIslandVisited(grid, i, j + 1); // Right
}

// Function to count the number of islands
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;

    // Traverse the grid
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            // If land ('1') is found, mark the island visited and increment the island count
            if (grid[i][j] == '1')
            {
                islands++;
                markIslandVisited(grid, i, j);
            }
        }
    }

    return islands;
}

int main()
{
    // Example grid representing islands
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    // Print the number of islands
    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}
