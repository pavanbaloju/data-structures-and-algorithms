#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>> &board)
{
    for (auto row : board)
    {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

// Function to check if a digit can be placed at a given position in the Sudoku board.
// Interview Revision Notes:
// This function checks if the digit 'd' can be placed at position (row, col) on the board.
// It checks for conflicts in the same row, same column, and same 3x3 subgrid.
// Time Complexity: O(1) since the board size is fixed (9x9).
// Space Complexity: O(1), constant extra space used.

bool canPlace(vector<vector<char>> &board, int row, int col, char d)
{
    // Check for conflicts in the same row and same column.
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == d || board[row][i] == d)
        {
            return false;
        }
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

// Function to recursively solve the Sudoku puzzle.
// Interview Revision Notes:
// This function uses backtracking to solve the Sudoku puzzle.
// It iterates through each cell of the board and tries to place digits from '1' to '9'.
// If a digit can be placed at a cell, it proceeds to solve the remaining puzzle recursively.
// If no digit can be placed at a cell, it backtracks and tries a different digit.
// Time Complexity: Exponential, but typically very fast for standard 9x9 Sudoku puzzles.
// Space Complexity: O(1), constant extra space used apart from the input board.

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
                        board[r][c] = '.'; // If no solution found, backtrack and try a different digit.
                    }
                }
                return false; // If no digit can be placed at (r, c), the current configuration is invalid.
            }
        }
    }
    return true; // If all cells are filled, the puzzle is solved.
}

// Function to solve the Sudoku puzzle.
// Interview Revision Notes:
// This function invokes the solver function to solve the Sudoku puzzle using backtracking.
// Time Complexity: Exponential, but typically very fast for standard 9x9 Sudoku puzzles.
// Space Complexity: O(1), constant extra space used apart from the input board.

void solveSudoku(vector<vector<char>> &board)
{
    solve(board); // Call the solver function to solve the Sudoku puzzle.
}


int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    print(board);
}