#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Intuition:
Use Breadth-First Search (BFS) starting from all cells containing 0s simultaneously.
Each cell will be visited with the shortest distance to a 0 because BFS explores in layers.

DSA Strategy/Pattern:
Breadth-First Search (BFS)

Approach:
1. Initialize a result matrix `res` with -1 indicating unvisited cells.
2. Use a queue to perform BFS, starting with all cells containing 0s.
3. For each cell, add its unvisited adjacent cells to the queue, marking their distances.
4. Continue until all reachable cells are visited and updated.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
O(m * n) for storing the result and the queue.
*/

// Function to add adjacent cells to the queue if they haven't been visited yet
void addAdjacent(int r, int c, int rows, int cols, vector<vector<int>> &res, queue<pair<int, int>> &q, int dist)
{
    // Check if the cell is out of bounds or already visited
    if (r < 0 || r == rows || c < 0 || c == cols || res[r][c] != -1)
    {
        return;
    }
    // Mark the cell with the current distance
    res[r][c] = dist;
    // Add the cell to the queue
    q.push({r, c});
}

// Function to update the matrix with the distance of the nearest 0 for each cell
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    // Initialize result matrix with -1 indicating unvisited cells
    vector<vector<int>> res(rows, vector<int>(cols, -1));
    // Queue to perform BFS
    queue<pair<int, int>> q;

    // Initialize the queue with all 0 cells and mark their distance as 0 in the result matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }

    // Perform BFS from each 0 cell
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        int dist = res[r][c] + 1;

        // Add adjacent cells (up, down, left, right) to the queue
        addAdjacent(r + 1, c, rows, cols, res, q, dist);
        addAdjacent(r - 1, c, rows, cols, res, q, dist);
        addAdjacent(r, c + 1, rows, cols, res, q, dist);
        addAdjacent(r, c - 1, rows, cols, res, q, dist);
    }

    return res;
}

// Function to print the result matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const vector<int> &row : matrix)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example input matrix
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    // Call the function to update the matrix
    vector<vector<int>> res = updateMatrix(mat);

    // Print the result matrix
    cout << "Updated matrix with distances to nearest 0:" << endl;
    printMatrix(res);

    return 0;
}
