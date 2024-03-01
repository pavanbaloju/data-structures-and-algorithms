#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Problem Statement:
// Given a grid where each cell represents an orange, determine the minimum number of minutes required to rot all oranges.
// Oranges adjacent to rotten oranges rot in one minute, and this rotting process continues until no more oranges can rot.

// Intuition:
// We can simulate the rotting process using breadth-first search (BFS). We start by adding the coordinates of all rotten oranges to a queue.
// Then, we perform BFS, exploring neighboring cells of each rotten orange and marking fresh oranges as rotten.
// We repeat this process until no more fresh oranges can be rotten. The number of BFS iterations represents the minutes required.

// DSA Strategy:
// Breadth-First Search (BFS)

// Approach:
// 1. Initialize a queue to store the coordinates of rotten oranges and a variable to count the number of fresh oranges.
// 2. Iterate through the grid, adding rotten oranges' coordinates to the queue and counting fresh oranges.
// 3. If there are no fresh oranges, return 0 (no need to rot).
// 4. Define directions to explore neighboring cells: up, down, left, and right.
// 5. Perform BFS:
//    a. While the queue is not empty:
//       i.   Get the current level size (number of rotten oranges in the current minute).
//       ii.  For each rotten orange in the current level:
//            - Explore neighboring cells in all directions.
//            - If a neighboring cell contains a fresh orange:
//                * Mark it as rotten.
//                * Add its coordinates to the queue.
//                * Decrement the count of fresh oranges.
//       iii. Increment minutes after each level of BFS.
// 6. After BFS, if there are still fresh oranges left, return -1 (impossible to rot all oranges).
// 7. Otherwise, return the total minutes taken to rot all oranges.

// Time Complexity: O(rows * cols) where rows and cols are the dimensions of the grid.
//                  Each cell is processed at most once during BFS.
// Space Complexity: O(rows * cols) for the queue and grid.
//                   In the worst case, all cells may be rotten, and the queue may store all cell coordinates.

int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a queue to store the coordinates of rotten oranges
    queue<pair<int, int>> rottenQueue;

    // Count of fresh oranges
    int freshCount = 0;

    // Initialize the queue and count the fresh oranges
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                rottenQueue.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges, return 0
    if (freshCount == 0)
    {
        return 0;
    }

    // Define the directions for exploring neighboring cells
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minutes = 0;

    // Perform BFS to rot the oranges
    while (!rottenQueue.empty())
    {
        int currentLevelSize = rottenQueue.size();

        for (int i = 0; i < currentLevelSize; i++)
        {
            int x = rottenQueue.front().first;
            int y = rottenQueue.front().second;
            rottenQueue.pop();

            for (auto dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check if the neighboring cell is within the grid and has a fresh orange
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;           // Mark the orange as rotten
                    rottenQueue.push({newX, newY}); // Add the newly rotten orange to the queue
                    freshCount--;                   // Decrement the count of fresh oranges
                }
            }
        }

        if (!rottenQueue.empty())
        {
            minutes++; // Increment the minutes after each level of BFS
        }
    }

    // If there are still fresh oranges left, return -1
    if (freshCount > 0)
    {
        return -1;
    }

    return minutes;
}

int main()
{
    // Example usage
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int minutes = orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << minutes << endl;

    return 0;
}
