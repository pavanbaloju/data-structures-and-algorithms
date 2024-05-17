#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a 2D board representing the Game of Life,
// implement a function to simulate one step of the game.

// Intuition:
// The problem requires updating the board according to the rules of the Game of Life,
// where each cell can either be dead (0) or alive (1), based on its current state and
// the number of live neighbors it has.

// DSA Strategy/Pattern:
// Simulation

// Approach:
// 1. Create a function to count the number of live neighbors for a given cell.
// 2. Iterate through each cell in the board and update its state based on the following rules:
//    - Any live cell with fewer than two live neighbors dies (underpopulation).
//    - Any live cell with two or three live neighbors remains alive.
//    - Any live cell with more than three live neighbors dies (overpopulation).
//    - Any dead cell with exactly three live neighbors becomes alive (reproduction).
// 3. Update the board based on the new states of cells.

// Time Complexity:
// O(m * n), where m is the number of rows and n is the number of columns in the board.

// Space Complexity:
// O(1) (excluding input and output space)

// Function to count the number of live neighbors of a cell at position (r, c)
int neighbors(int r, int c, vector<vector<int>> &board)
{
    int count = 0;
    for (int i = r - 1; i <= r + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            // Skip the current cell and out-of-bounds cells
            if ((i == r && j == c) || i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
                continue;
            // Increment count if the neighbor cell is live (1) or transitioning to live (3)
            if (board[i][j] == 1 || board[i][j] == 3)
                count++;
        }
    }
    return count;
}

// Function to simulate one step of the Game of Life
void gameOfLife(vector<vector<int>> &board)
{
    int R = board.size(), C = board[0].size();
    // Iterate through each cell in the board
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int nbrs = neighbors(r, c, board); // Count live neighbors
            int &cell = board[r][c];           // Reference to the current cell's value
            if (cell)
            {
                // If the cell is live
                if (nbrs == 2 || nbrs == 3)
                    cell = 3; // Mark as live (1) or staying live (3)
            }
            else
            {
                // If the cell is dead
                if (nbrs == 3)
                    cell = 2; // Mark as transitioning to live
            }
        }
    }
    // Update the board based on the new states of cells
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int &cell = board[r][c];
            if (cell == 1) // Live cell
                cell = 0;  // Mark as dead
            else if (cell == 2 || cell == 3)
                cell = 1; // Mark as live
        }
    }
}

// Function to print the board
void print(vector<vector<int>> board)
{
    for (auto row : board)
    {
        for (auto cell : row)
            cout << cell << " "; // Print each cell's value
        cout << endl;            // Move to the next row
    }
    cout << endl; // Add a newline after printing the board
}

int main()
{
    // Initialize the board with initial cell states
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    cout << "Initial Board:" << endl;
    print(board);      // Print the initial board
    gameOfLife(board); // Simulate one step of the Game of Life
    cout << "After one step:" << endl;
    print(board); // Print the board after one step
    return 0;     // Exit the program
}
