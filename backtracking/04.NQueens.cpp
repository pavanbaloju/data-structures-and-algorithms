#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// The N-Queens problem is to place N chess queens on an N×N chessboard so that no two queens attack each other.
// A queen can attack horizontally, vertically, or diagonally.
// This code aims to find all distinct solutions to the N-Queens problem for a given N.

// Intuition:
// To solve the N-Queens problem, we can use backtracking. We'll try to place a queen in each row of the chessboard,
// ensuring that no two queens attack each other. We'll recursively explore all possible placements.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// Use backtracking to generate all valid placements of queens.
// Approach:
// 1. Define a recursive function that places queens on the chessboard row by row.
// 2. In each row, iterate through each column to find a valid position for the queen.
// 3. Check if placing a queen at position (row, col) is valid by verifying no other queens attack it.
// 4. If a valid position is found, place the queen and recursively try the next row.
// 5. If all queens are placed successfully, add the configuration to the result.
// 6. Backtrack by removing the last queen placed and try the next column.
// 7. Return all valid configurations.
// Time Complexity: O(N!) where N is the size of the chessboard (number of rows/columns). The time complexity
//                  arises from the exponential growth in the number of configurations to explore.
// Space Complexity: O(N^2) where N is the size of the chessboard (number of rows/columns). The space complexity
//                   is dominated by the storage of the chessboard configurations.

// Function to check if placing a queen at position (row, col) is valid
bool isNotUnderAttack(vector<string> &board, int row, int col)
{
    int n = board.size();

    // Check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q') // If there is a queen in the same column
            return false;
    }

    // Check left diagonal (\)
    for (int i = 0; i < n; i++)
    {
        if (row - i >= 0 && col - i >= 0)
        {
            if (board[row - i][col - i] == 'Q') // If there is a queen in the left diagonal
                return false;
        }
    }

    // Check right diagonal (/)
    for (int i = 0; i < n; i++)
    {
        if (row - i >= 0 && col + i < n)
        {
            if (board[row - i][col + i] == 'Q') // If there is a queen in the right diagonal
                return false;
        }
    }

    return true;
}

// Recursive function to generate all valid placements of queens
void solve(vector<string> &board, int row, vector<vector<string>> &ans)
{
    int n = board.size();
    if (row == n)
    {
        ans.push_back(board); // Base case: Add the current configuration to the result if all queens are placed
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isNotUnderAttack(board, row, col)) // If placing a queen at position (row, col) is valid
        {
            board[row][col] = 'Q';      // Place a queen at position (row, col)
            solve(board, row + 1, ans); // Recursively try the next row
            board[row][col] = '.';      // Backtrack: Remove the queen and try the next position in the same row
        }
    }
}

// Function to generate all valid placements of queens on an N×N chessboard
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); // Initialize the chessboard with empty cells
    vector<vector<string>> ans;              // Vector to store all valid configurations
    solve(board, 0, ans);                    // Recursive queen placement
    return ans;
}

// Function to print a vector of strings representing the chessboard
void print(vector<string> board)
{
    for (string s : board)
    {
        cout << s << endl; // Print each row of the chessboard
    }
    cout << endl; // Separate different configurations
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4); // Solve the N-Queens problem for N = 4

    // Print all valid configurations of placing queens on the chessboard
    for (auto board : ans)
        print(board);

    return 0;
}
