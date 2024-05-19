#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function to add adjacent cells to the queue
void addAdjacent(int r, int c, int rows, int cols, vector<vector<char>> &grid, queue<pair<int, int>> &q)
{
    // Check if the cell is out of bounds or is water ('0')
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
    {
        return;
    }
    // Mark the cell as visited by setting it to '0'
    grid[r][c] = '0';
    // Add the cell to the queue
    q.push({r, c});
}

// Function to count the number of islands in the grid
int numIslands(vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;   // Queue for BFS
    int islands = 0;           // Count of islands
    int rows = grid.size();    // Number of rows in the grid
    int cols = grid[0].size(); // Number of columns in the grid

    // Traverse all cells in the grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // If a land cell ('1') is found
            if (grid[i][j] == '1')
            {
                // Increment the island count
                islands++;
                // Add the cell to the queue and mark it as visited
                q.push({i, j});
                grid[i][j] = '0';

                // Process all cells in the current island
                while (!q.empty())
                {
                    pair<int, int> cell = q.front();
                    q.pop();
                    int r = cell.first;
                    int c = cell.second;

                    // Add adjacent cells to the queue
                    addAdjacent(r - 1, c, rows, cols, grid, q); // Up
                    addAdjacent(r + 1, c, rows, cols, grid, q); // Down
                    addAdjacent(r, c - 1, rows, cols, grid, q); // Left
                    addAdjacent(r, c + 1, rows, cols, grid, q); // Right
                }
            }
        }
    }
    return islands;
}

int main()
{
    // Example grid
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    // Output the number of islands in the grid
    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}
