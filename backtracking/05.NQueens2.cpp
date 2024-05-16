#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// The N-Queens problem is to count the total number of distinct solutions for placing N chess queens on an N×N chessboard 
// such that no two queens attack each other. A queen can attack horizontally, vertically, or diagonally.

// Intuition:
// We can solve the N-Queens problem using backtracking. We'll recursively explore all possible placements of queens on 
// the chessboard, ensuring that no two queens attack each other.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// Use backtracking to count the number of valid solutions for the N-Queens problem.
// Approach:
// 1. Define a recursive function to explore all possible placements of queens row by row.
// 2. In each row, iterate through each column to find a valid position for the queen.
// 3. Check if placing a queen at position (row, col) is valid by ensuring it doesn't attack any other queen.
// 4. If a valid position is found, place the queen and recursively try the next row.
// 5. If all queens are placed successfully, increment the count of valid solutions.
// 6. Backtrack by removing the last queen placed and try the next position in the same row.
// 7. Return the count of valid solutions.
// Time Complexity: O(N!) where N is the size of the chessboard (number of rows/columns). The time complexity arises from 
//                  the exponential growth in the number of configurations to explore.
// Space Complexity: O(N^2) where N is the size of the chessboard (number of rows/columns). The space complexity is 
//                   dominated by the storage of the chessboard configurations.

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
