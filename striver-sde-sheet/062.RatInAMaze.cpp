#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Constants to represent directions (up, down, left, right)
const char directions[4] = {'U', 'D', 'L', 'R'};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// Problem Statement:
// Given a maze represented by a 2D grid where 0 represents walls and 1 represents open cells,
// find all possible paths from the top-left corner to the bottom-right corner.

// Intuition:
// This problem can be solved using backtracking. We start from the top-left corner and explore
// all possible paths recursively. At each step, we try moving in all four directions and mark
// the visited cells. When we reach the bottom-right corner, we add the current path to the list
// of all paths.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a helper function 'isValid' to check if a cell is valid to move into.
//    It checks if the cell is within the maze boundaries and is an open cell.
// 2. Define a recursive function 'findAllPaths' to explore all possible paths from the current cell.
//    a. Base case: If the rat reaches the bottom-right corner, add the current path to the list of all paths.
//    b. Mark the current cell as visited by changing its value in the maze grid.
//    c. Try moving in all four directions.
//       i. If the next cell is valid, append the current direction to the path and recursively call 'findAllPaths'.
//      ii. After exploring all paths from the current cell, backtrack by removing the last direction from the path.
//    d. Mark the current cell as unvisited (backtrack) by restoring its original value in the maze grid.
// 3. Define the main function 'solveMaze' to initialize the path as an empty string and call 'findAllPaths'.
// 4. Print all paths obtained from the 'solveMaze' function.

// Time Complexity: O(3^(N^2)), where N is the size of the maze. In the worst case, we might explore all paths.
// Space Complexity: O(N^2 * M), where M is the average length of each path.

// Function to check if a cell is valid to move into
bool isValid(int x, int y, int rows, int cols, vector<vector<int>> &maze)
{
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1;
}

// Helper function to find all paths through the maze
void findAllPaths(int x, int y, int rows, int cols, vector<vector<int>> &maze, string &path, vector<string> &allPaths)
{
    // Base case: if the rat reaches the bottom-right corner
    if (x == rows - 1 && y == cols - 1)
    {
        allPaths.push_back(path); // Add the current path to the list of all paths
        return;
    }

    // Mark the current cell as visited by changing its value in the maze grid
    maze[x][y] = 0;

    // Try moving in all four directions
    for (int i = 0; i < 4; ++i)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, rows, cols, maze))
        {
            // Append the current direction to the path
            path.push_back(directions[i]);
            // Recursive call to explore the next cell
            findAllPaths(newX, newY, rows, cols, maze, path, allPaths);
            // Backtrack by removing the last direction from the path
            path.pop_back();
        }
    }

    // Mark the current cell as unvisited (backtrack) by restoring its original value in the maze grid
    maze[x][y] = 1;
}

// Function to solve the rat in a maze problem and return all paths
vector<string> solveMaze(vector<vector<int>> &maze)
{
    int rows = maze.size();
    int cols = maze[0].size();
    string path;             // Initialize path as an empty string
    vector<string> allPaths; // Vector to store all paths

    // Start from the top-left corner
    findAllPaths(0, 0, rows, cols, maze, path, allPaths);

    return allPaths;
}

// Main function to demonstrate the solveMaze function
int main()
{
    // Example maze represented by a 2D grid
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    // Call the solveMaze function
    vector<string> allPaths = solveMaze(maze);

    // Print all paths
    for (const auto &path : allPaths)
    {
        cout << path << endl;
    }

    return 0;
}
