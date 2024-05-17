#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement:
Given a 2D grid where 1 represents land and 0 represents water, find the perimeter of the island.
The grid is completely surrounded by water, and there is exactly one island (one or more connected land cells).

Intuition:
Each land cell contributes 4 to the perimeter. For each adjacent land cell, the perimeter contribution decreases by 1.

DSA Strategy/Pattern:
Simulation

Approach:
1. Initialize the perimeter as 0.
2. Iterate through each cell in the grid.
3. For each land cell, add 4 to the perimeter (maximum possible for the cell).
4. Check the adjacent cells (up, down, left, right):
    - If an adjacent cell is also land, decrease the perimeter by 1.
5. Return the total perimeter.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
O(1)

*/

// Function to calculate the perimeter of the island in the grid
int islandPerimeter(vector<vector<int>> &grid)
{
    int perimeter = 0;
    int m = grid.size();
    int n = grid[0].size();

    // Iterate through each cell in the grid
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
            {
                // If current cell is land, add its perimeter contribution
                perimeter += 4; // Initialize with the maximum possible perimeter

                // Check adjacent cells (up, down, left, right)
                if (i > 0 && grid[i - 1][j] == 1)
                    perimeter--; // Up
                if (i < m - 1 && grid[i + 1][j] == 1)
                    perimeter--; // Down
                if (j > 0 && grid[i][j - 1] == 1)
                    perimeter--; // Left
                if (j < n - 1 && grid[i][j + 1] == 1)
                    perimeter--; // Right
            }
        }
    }

    return perimeter;
}

// Function to print the grid
void printGrid(const vector<vector<int>> &grid)
{
    for (const auto &row : grid)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // Example usage
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};

    cout << "Initial Grid:" << endl;
    printGrid(grid); // Print the initial grid

    cout << "Perimeter of the island: " << islandPerimeter(grid) << endl;

    return 0; // Exit the program
}
