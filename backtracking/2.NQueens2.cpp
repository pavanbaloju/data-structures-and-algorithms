#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// The N-Queens problem is to count the number of distinct solutions to place N queens on an N×N chessboard such that no two queens attack each other.

// Intuition:
// Similar to the N-Queens problem, we can use backtracking to explore all possible configurations of queen placements and count the number of valid solutions.

// DSA Strategy:
// Recursion, Backtracking

// Approach:
// 1. Implement a recursive function 'solve' to explore all possible configurations of queen placements.
//    a. Base case: If the current row 'row' reaches the size of the board 'n', increment the count of valid solutions.
//    b. For each column 'c' in the current row, check if placing a queen at position (row, c) is valid:
//       i. Check if there is no queen in the same column, left diagonal (\), and right diagonal (/).
//       ii. If the position is valid, mark it as a queen ('Q') and recursively call 'solve' for the next row.
//       iii. Backtrack: Remove the queen and try the next position in the same row.
// 2. After exploring all possible configurations, return the count of valid solutions.

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

// Recursive function to count the number of valid solutions for N-Queens
void solve(vector<string> &board, int row, int &count)
{
    int n = board.size();
    if (row == n)
    {
        count++; // Base case: Increment the count if all queens are placed
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isNotUnderAttack(board, row, col)) // If placing a queen at position (row, col) is valid
        {
            board[row][col] = 'Q'; // Place a queen at position (row, col)
            solve(board, row + 1, count); // Recursively try the next row
            board[row][col] = '.'; // Backtrack: Remove the queen and try the next position in the same row
        }
    }
}

// Function to count the total number of distinct solutions for N-Queens
int totalNQueens(int n)
{
    vector<string> board(n, string(n, '.')); // Initialize the chessboard with empty cells
    int count = 0; // Initialize the count of valid solutions
    solve(board, 0, count); // Recursive exploration of queen placements
    return count; // Return the count of valid solutions
}

int main()
{
    cout << totalNQueens(5); // Output the total number of distinct solutions for N-Queens with N = 5
    return 0;
}
