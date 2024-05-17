#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

// Problem Statement:
// Given a snakes and ladders board represented by a 2D array where -1 indicates no shortcut, 
// and positive numbers indicate the destination of a ladder or a snake's mouth,
// find the minimum number of moves required to reach the end of the board starting from position 1.

// Intuition:
// Use Breadth-First Search (BFS) to explore all possible moves from the starting position (1) 
// until reaching the end of the board.

// DSA Strategy/Pattern:
// Breadth-First Search (BFS)

// Approach:
// 1. Create a queue to perform BFS.
// 2. Initialize a vector to keep track of visited cells.
// 3. Start BFS from the first cell (position 1) with distance 0.
// 4. Iterate until the queue is empty:
//      a. Pop the front cell from the queue.
//      b. If the current cell is the last cell, return its distance from the start.
//      c. For each possible move (up to 6 steps ahead):
//         - Calculate the destination cell after taking the move.
//         - If the destination is not visited:
//              - Mark it as visited.
//              - Add it to the queue with updated distance.
// 5. If no possible way to reach the end, return -1.

// Time Complexity: O(N^2), where N is the size of the board.
// Space Complexity: O(N^2), where N is the size of the board.

// Function to find the shortest path from the start to the end of the board using BFS
int shortestPath(vector<vector<int>> &board, vector<pair<int, int>> cells) {
    int n = board.size(); // Size of the board
    vector<bool> visited(n * n + 1, false); // Array to keep track of visited cells
    visited[1] = true; // Start position is visited
    queue<pair<int, int>> q; // Queue to perform BFS
    q.push({1, 0}); // Starting position with distance 0

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int curr = p.first; // Current cell number
        int dist = p.second; // Current distance from the start
        q.pop();

        // If we reach the last cell, return the distance
        if (curr == n * n)
            return dist;

        // Check next possible moves (up to 6 steps ahead)
        for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
            auto [row, col] = cells[next];
            int dest = board[row][col] != -1 ? board[row][col] : next; // Destination cell after taking the move
            if (!visited[dest]) {
                visited[dest] = true; // Mark the destination as visited
                q.push({dest, dist + 1}); // Add the destination to the queue with updated distance
            }
        }
    }
    return -1; // If there is no possible way to reach the end, return -1
}

// Function to prepare the board and call the shortestPath function
int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size(), ind = 1;
    vector<pair<int, int>> cells(n * n + 1); // To store the board cells in 1D format
    vector<int> cols(n);

    // Initialize the cols vector with column indices
    iota(cols.begin(), cols.end(), 0);
    for (int row = n - 1; row >= 0; row--) {
        for (int col : cols) {
            cells[ind++] = {row, col}; // Store the cell with its corresponding row and column
        }
        reverse(cols.begin(), cols.end()); // Reverse the order for the next row
    }
    return shortestPath(board, cells); // Find the shortest path from start to end
}

int main() {
    // Example input board
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};
    
    // Print the result of the snakesAndLadders function
    cout << snakesAndLadders(board) << endl;
    return 0;
}
