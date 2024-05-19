#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Direction arrays to explore 8-directional neighbors
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Implementation using BFS and a separate visited array
int shortestPathBinaryMatrix1(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1; // Check if start or end cell is blocked

    vector<vector<bool>> visited(n, vector<bool>(n, false)); // Array to mark visited cells
    queue<pair<int, int>> q;                                 // Queue for BFS traversal
    q.push({0, 0});                                          // Start BFS from the top-left cell
    visited[0][0] = true;                                    // Mark the starting cell as visited
    int steps = 1;                                           // Length of the shortest path

    while (!q.empty())
    {
        int size = q.size(); // Size of the current level in BFS traversal
        for (int i = 0; i < size; ++i)
        {
            auto [x, y] = q.front(); // Current cell coordinates
            q.pop();                 // Remove the current cell from the queue
            if (x == n - 1 && y == n - 1)
                return steps; // Reached the destination

            // Explore all 8-directional neighbors of the current cell
            for (int k = 0; k < 8; ++k)
            {
                int nx = x + dx[k]; // Next cell x-coordinate
                int ny = y + dy[k]; // Next cell y-coordinate
                // Check if the next cell is within the grid and is not visited and is clear
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !visited[nx][ny])
                {
                    q.push({nx, ny});       // Push the next cell to the queue for traversal
                    visited[nx][ny] = true; // Mark the next cell as visited
                }
            }
        }
        steps++; // Increment the distance traveled
    }
    return -1; // No clear path found
}

// Implementation using BFS and a single distance array
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1; // Check if start or end cell is blocked

    vector<vector<int>> distances(n, vector<int>(n, INT_MAX)); // Array to store distances from the start cell
    queue<pair<int, int>> q;                                   // Queue for BFS traversal
    q.push({0, 0});                                            // Start BFS from the top-left cell
    distances[0][0] = 1;                                       // Distance to the start cell is 1

    while (!q.empty())
    {
        auto [x, y] = q.front(); // Current cell coordinates
        q.pop();                 // Remove the current cell from the queue

        // Explore all 8-directional neighbors of the current cell
        for (int k = 0; k < 8; ++k)
        {
            int nx = x + dx[k]; // Next cell x-coordinate
            int ny = y + dy[k]; // Next cell y-coordinate
            // Check if the next cell is within the grid and is clear and the distance is not calculated yet
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && distances[nx][ny] == INT_MAX)
            {
                q.push({nx, ny});                        // Push the next cell to the queue for traversal
                distances[nx][ny] = distances[x][y] + 1; // Update the distance to the next cell
            }
        }
    }
    return distances[n - 1][n - 1] == INT_MAX ? -1 : distances[n - 1][n - 1]; // Return the distance to the destination
}

int main()
{
    // Example usage
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Length of the shortest clear path: " << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
