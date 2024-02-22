#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// The N-Queens problem is to place N queens on an N×N chessboard such that no two queens attack each other.

// Intuition:
// We can solve this problem using backtracking by trying all possible combinations of queen placements and checking for conflicts.

// DSA Strategy:
// Recursion, Backtracking

// Approach:
// 1. Implement a recursive function 'solve' to generate all valid placements of queens.
//    a. Base case: If the current row 'row' reaches the size of the board 'n', add the current configuration 'board' to the result 'ans'.
//    b. For each column 'c' in the current row, check if placing a queen at position (row, c) is valid:
//       i. Check if there is no queen in the same column, left diagonal (\), and right diagonal (/).
//       ii. If the position is valid, mark it as a queen ('Q') and recursively call 'solve' for the next row.
//       iii. Backtrack: Remove the queen and try the next position in the same row.
// 2. After generating all valid configurations, return the 'ans' vector containing all solutions.

// Time Complexity: O(N!), where N is the size of the chessboard.
// Space Complexity: O(N^2), considering the space required for the chessboard and the recursive stack.

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
            board[row][col] = 'Q'; // Place a queen at position (row, col)
            solve(board, row + 1, ans); // Recursively try the next row
            board[row][col] = '.'; // Backtrack: Remove the queen and try the next position in the same row
        }
    }
}

// Function to generate all valid placements of queens on an N×N chessboard
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); // Initialize the chessboard with empty cells
    vector<vector<string>> ans; // Vector to store all valid configurations
    solve(board, 0, ans); // Recursive queen placement
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
