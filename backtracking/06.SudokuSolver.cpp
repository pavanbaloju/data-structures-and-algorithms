#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Solve the Sudoku puzzle, where a 9x9 grid must be filled with digits from 1 to 9 such that each column, each row,
// and each of the nine 3x3 subgrids that compose the grid contain all of the digits from 1 to 9 without repetition.

// Intuition:
// We can solve the Sudoku puzzle using backtracking. We'll recursively explore all possible placements of digits
// from '1' to '9' in empty cells, ensuring that each placement is valid according to Sudoku rules.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// 1. Define a function 'canPlace' to check if a digit can be placed at a given position (row, col) on the Sudoku board.
//    - Check for conflicts in the same row and same column.
//    - Check for conflicts in the same 3x3 subgrid.
// 2. Define a recursive function 'solve' to solve the Sudoku puzzle.
//    - Iterate through each cell in the board.
//    - If the cell is empty ('.'), try placing digits from '1' to '9'.
//    - Check if the digit can be placed at the current position using the 'canPlace' function.
//    - If valid, place the digit and recursively solve the remaining puzzle.
//    - If the puzzle is solved successfully, return true.
//    - If no digit can be placed at the current position, backtrack by removing the digit and try a different one.
// 3. Call the 'solve' function to solve the Sudoku puzzle.
// 4. Print the solved Sudoku board.

// Time Complexity: O(9^(N*N)) where N is the size of the Sudoku board (9 in this case). The time complexity arises from
//                  the exponential growth in the number of configurations to explore.
// Space Complexity: O(N*N) where N is the size of the Sudoku board (9 in this case). The space complexity is
//                   dominated by the storage of the Sudoku board.

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
