#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Solve the Sudoku puzzle by filling the empty cells with digits from 1 to 9 such that each row, column, and 3x3 subgrid contains all the digits from 1 to 9 without any repetition.

// Intuition:
// We can use backtracking to explore all possible configurations of filling digits in the Sudoku puzzle. At each empty cell, we try placing digits from '1' to '9' and recursively solve the remaining puzzle.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Implement a function 'canPlace' to check if a digit can be placed at a given position (row, col) on the Sudoku board.
//    a. Check for conflicts in the same row and same column.
//    b. Check for conflicts in the same 3x3 subgrid.
// 2. Implement a recursive function 'solve' to solve the Sudoku puzzle.
//    a. Iterate through each cell of the board.
//    b. If the cell is empty, try placing digits from '1' to '9' and check if the placement is valid using the 'canPlace' function.
//    c. If a valid digit can be placed, recursively solve the remaining puzzle.
//    d. If no valid digit can be placed, backtrack and try a different digit.
//    e. If all cells are filled, the puzzle is solved.
// 3. Implement a function 'solveSudoku' to invoke the solver function.
// 4. In the main function, initialize the Sudoku board and call the 'solveSudoku' function to solve the puzzle.

// Time Complexity: Exponential, but typically very fast for standard 9x9 Sudoku puzzles.
// Space Complexity: O(1), constant extra space used apart from the input board.

// Function to check if a digit can be placed at a given position (row, col) on the Sudoku board.
bool canPlace(vector<vector<char>> &board, int row, int col, char d)
{
    int n = board.size();

    // Check for conflicts in the same row and same column.
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == d || board[row][i] == d)
            return false;
    }

    // Calculate the starting row and column indices of the 3x3 subgrid.
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    // Check for conflicts in the same 3x3 subgrid.
    for (int r = sr; r < sr + 3; r++)
    {
        for (int c = sc; c < sc + 3; c++)
        {
            if (board[r][c] == d)
                return false;
        }
    }
    return true; // No conflicts found, 'd' can be placed at (row, col).
}

// Recursive function to solve the Sudoku puzzle.
bool solve(vector<vector<char>> &board)
{
    int n = board.size(); // Size of the board (assuming it's a square Sudoku board).
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] == '.') // If the cell is empty.
            {
                for (char ch = '1'; ch <= '9'; ch++) // Try placing digits from '1' to '9'.
                {
                    if (canPlace(board, r, c, ch)) // Check if 'ch' can be placed at (r, c).
                    {
                        board[r][c] = ch; // Place 'ch' at (r, c).
                        if (solve(board)) // Recursively solve the remaining puzzle.
                            return true;
                        board[r][c] = '.'; // Backtrack: Remove the digit and try a different one.
                    }
                }
                return false; // If no digit can be placed at (r, c), the current configuration is invalid.
            }
        }
    }
    return true; // If all cells are filled, the puzzle is solved.
}

// Function to solve the Sudoku puzzle.
void solveSudoku(vector<vector<char>> &board)
{
    solve(board); // Call the solver function to solve the Sudoku puzzle.
}

// Function to print the Sudoku board.
void print(vector<vector<char>> &board)
{
    for (auto row : board)
    {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board); // Solve the Sudoku puzzle.
    print(board);       // Print the solved Sudoku board.
    return 0;
}
