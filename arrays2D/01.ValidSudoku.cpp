#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Problem Statement:
// Given a 9x9 Sudoku board, determine if it is valid according to the Sudoku rules.
// Each number (1-9) must appear exactly once in each row, column, and 3x3 sub-box.

// Intuition:
// To check if the board is valid, we need to ensure that each row, column, and 3x3 sub-box contains unique digits from 1 to 9 without repetition.

// DSA Strategy/Pattern: Hashing and Boolean Arrays

// Approach 1: Using Hashing to Check Sudoku Validity
// 1. Traverse each cell of the board.
// 2. Skip empty cells.
// 3. For each digit, generate unique identifiers for its row, column, and sub-box.
// 4. Use a hash set to keep track of these identifiers and check for duplicates.
// 5. If a duplicate is found, the board is invalid.
// 6. If no duplicates are found, the board is valid.

// Time Complexity: O(N^2), where N is the size of the board (9x9).
// Space Complexity: O(N^2), to store the hash set.

bool isValidSudoku2(vector<vector<char>> &board)
{
    unordered_set<string> visited; // Hash set to track visited elements

    for (int i = 0; i < 9; ++i)
    { // Iterate through each row
        for (int j = 0; j < 9; ++j)
        { // Iterate through each column
            // Skip empty cells
            if (board[i][j] == '.')
                continue;

            // Generate unique identifiers for rows, columns, and sub-boxes
            const string c(1, board[i][j]);                                               // Convert char to string
            if (!visited.insert(c + "@row" + to_string(i)).second ||                      // Check row
                !visited.insert(c + "@col" + to_string(j)).second ||                      // Check column
                !visited.insert(c + "@box" + to_string(i / 3) + to_string(j / 3)).second) // Check sub-box
                return false;                                                             // Duplicate found
        }
    }
    return true; // No duplicates found
}

// Approach 2: Using Boolean Arrays to Check Sudoku Validity
// 1. Initialize boolean arrays to track the presence of digits in rows, columns, and sub-boxes.
// 2. Traverse each cell of the board.
// 3. Skip empty cells.
// 4. For each digit, update the boolean arrays.
// 5. If a digit already exists in the current row, column, or sub-box, the board is invalid.
// 6. If no duplicates are found, the board is valid.

// Time Complexity: O(N^2), where N is the size of the board (9x9).
// Space Complexity: O(N), for the boolean arrays.

bool isValidSudoku3(vector<vector<char>> &board)
{
    bool iisdigit[9][9]{};     // Boolean array for rows
    bool jisdigit[9][9]{};     // Boolean array for columns
    bool ijisdigit[3][3][9]{}; // Boolean array for sub-boxes

    for (int i = 0; i < 9; i++)
    { // Iterate through each row
        for (int j = 0; j < 9; j++)
        { // Iterate through each column
            if (board[i][j] != '.')
            {                                  // Skip empty cells
                int d = board[i][j] - '0' - 1; // Convert char to int index

                // Check if the digit already exists in the current row
                if (iisdigit[i][d])
                {
                    return false; // Digit already exists in the row
                }
                iisdigit[i][d] = true; // Mark the digit as seen in the row

                // Check if the digit already exists in the current column
                if (jisdigit[j][d])
                {
                    return false; // Digit already exists in the column
                }
                jisdigit[j][d] = true; // Mark the digit as seen in the column

                // Check if the digit already exists in the current 3x3 sub-box
                if (ijisdigit[i / 3][j / 3][d])
                {
                    return false; // Digit already exists in the sub-box
                }
                ijisdigit[i / 3][j / 3][d] = true; // Mark the digit as seen in the sub-box
            }
        }
    }
    return true; // No duplicates found
}

// Approach 3: Without Hashing, Check Sudoku Validity Directly
// 1. Traverse each cell of the board.
// 2. Skip empty cells.
// 3. For each digit, check its row, column, and 3x3 sub-box for duplicates.
// 4. If a duplicate is found, the board is invalid.
// 5. If no duplicates are found, the board is valid.

// Time Complexity: O(N^2), where N is the size of the board (9x9).
// Space Complexity: O(1), no extra space used.

bool canPlace(vector<vector<char>> &board, int row, int col)
{
    char d = board[row][col]; // Get the current digit
    // Check row and column for duplicates
    for (int i = 0; i < 9; i++)
    {
        if ((board[i][col] == d && i != row) || (board[row][i] == d && i != col))
        {
            return false; // Duplicate found in row or column
        }
    }

    // Check the 3x3 sub-box for duplicates
    int sr = (row / 3) * 3; // Starting row of the sub-box
    int sc = (col / 3) * 3; // Starting column of the sub-box
    for (int r = sr; r < sr + 3; r++)
    {
        for (int c = sc; c < sc + 3; c++)
        {
            if (board[r][c] == d && r != row && c != col)
                return false; // Duplicate found in sub-box
        }
    }
    return true; // No duplicates found
}

bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size(); // Size of the board
    for (int r = 0; r < n; r++)
    { // Iterate through each row
        for (int c = 0; c < n; c++)
        { // Iterate through each column
            // If the cell is not empty and the value cannot be placed validly
            if (board[r][c] != '.' && !canPlace(board, r, c))
            {
                return false; // Invalid placement
            }
        }
    }
    return true; // Board is valid
}

int main()
{
    // Sample Sudoku board
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

    // Test each method of Sudoku validation
    cout << "Using direct checks: " << isValidSudoku(board) << endl;   // Output: 1 (true)
    cout << "Using hashing: " << isValidSudoku2(board) << endl;        // Output: 1 (true)
    cout << "Using boolean arrays: " << isValidSudoku3(board) << endl; // Output: 1 (true)

    return 0;
}
