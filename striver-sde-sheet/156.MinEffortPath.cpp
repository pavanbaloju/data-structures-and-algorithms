#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Function to find the minimum effort path
int minimumEffortPath(vector<vector<int>> &heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    // Matrix to store the efforts required to reach each cell
    vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));

    // Directions for moving: right, left, down, up
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Priority queue to process cells with minimum effort first
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Start from the top-left cell
    pq.push({0, {0, 0}});
    efforts[0][0] = 0; // Effort to reach the start cell is 0

    // Perform Dijkstra's algorithm
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int currEffort = curr.first;
        int currRow = curr.second.first;
        int currCol = curr.second.second;

        // If reached the bottom-right cell, return the effort
        if (currRow == rows - 1 && currCol == cols - 1)
        {
            return currEffort;
        }

        // Explore all directions
        for (auto &dir : directions)
        {
            int newRow = currRow + dir.first;
            int newCol = currCol + dir.second;

            // Check if the new position is within bounds
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                // Calculate the new effort required
                int newEffort = max(currEffort, abs(heights[currRow][currCol] - heights[newRow][newCol]));

                // Update the effort if it's less than the previously calculated effort for this cell
                if (newEffort < efforts[newRow][newCol])
                {
                    efforts[newRow][newCol] = newEffort;
                    pq.push({newEffort, {newRow, newCol}});
                }
            }
        }
    }

    return -1; // No path found
}

int main()
{
    // Example usage
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << "Minimum effort required: " << minimumEffortPath(heights) << endl;
    return 0;
}
