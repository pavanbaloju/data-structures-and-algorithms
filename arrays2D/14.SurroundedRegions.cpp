#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Intuition:
// To efficiently capture regions surrounded by 'X', we can perform a depth-first search (DFS) starting from the boundary cells.
// We mark all 'O's that are connected to the boundary as visited, indicating they are not surrounded.
// Then, we iterate through the board and mark any unvisited 'O's as surrounded and change them to 'X's.

// DSA Strategy/Pattern: Depth-First Search (DFS)

// Approach 1: Using Additional Space for Visited Matrix
// 1. Perform DFS starting from boundary cells (top, bottom, left, right).
// 2. Mark connected 'O's as visited.
// 3. Iterate through the board and mark unvisited 'O's as surrounded 'X's.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the board.
// Space Complexity: O(m * n) for the visited matrix.
void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c)
{
    // Base cases for recursion: out of bounds or visited cell or 'X'
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] == 'X')
        return;

    // Mark the cell as visited
    visited[r][c] = true;

    // Explore neighboring cells in all four directions
    for (auto nrc : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
        helper(board, visited, r + nrc.first, c + nrc.second);
}

void solve(vector<vector<char>> &board)
{
    // Get the dimensions of the board
    int R = board.size(), C = board[0].size();

    // Create a visited matrix to keep track of visited cells
    vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));

    // Mark 'O's connected to the boundary as visited
    for (int r : vector<int>({0, R - 1}))
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] == 'O')
            {
                helper(board, visited, r, c);
            }
        }
    }

    for (int c : vector<int>({0, C - 1}))
    {
        for (int r = 1; r < R - 1; r++)
        {
            if (board[r][c] == 'O')
            {
                helper(board, visited, r, c);
            }
        }
    }

    // Iterate through the board and mark unvisited 'O's as surrounded 'X's
    for (int r = 1; r < R - 1; r++)
    {
        for (int c = 1; c < C - 1; c++)
        {
            if (board[r][c] == 'O' && !visited[r][c])
            {
                board[r][c] = 'X';
            }
        }
    }
}

// Approach 2: Without Additional Space for Visited Matrix
// 1. Perform DFS starting from boundary cells (top, bottom, left, right).
// 2. Mark connected 'O's as visited by changing them to 'M'.
// 3. Iterate through the board and mark 'O's as 'X's and 'M's as 'O's.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the board.
// Space Complexity: O(1), no additional space used.
void helper2(vector<vector<char>> &board, int r, int c)
{
    // Base cases for recursion: out of bounds or 'X' or already marked 'M'
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'M')
        return;

    // Mark the cell as visited by changing it to 'M'
    board[r][c] = 'M';

    // Explore neighboring cells in all four directions
    for (auto nrc : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
        helper2(board, r + nrc.first, c + nrc.second);
}

void solve2(vector<vector<char>> &board)
{
    // Get the dimensions of the board
    int R = board.size(), C = board[0].size();

    // Mark 'O's connected to the boundary as visited by changing them to 'M'
    for (int r : vector<int>({0, R - 1}))
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] == 'O')
            {
                helper2(board, r, c);
            }
        }
    }

    for (int c : vector<int>({0, C - 1}))
    {
        for (int r = 1; r < R - 1; r++)
        {
            if (board[r][c] == 'O')
            {
                helper2(board, r, c);
            }
        }
    }

    // Iterate through the board and mark 'O's as 'X's and 'M's as 'O's
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] == 'O')
            {
                board[r][c] = 'X';
            }
            else if (board[r][c] == 'M')
            {
                board[r][c] = 'O';
            }
        }
    }
}

// Function to print the contents of the board.
void print(vector<vector<char>> &board)
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> grid = {
        {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'}};

    // Applying first approach
    vector<vector<char>> gridCopy1 = grid;
    solve(gridCopy1);
    cout << "After solving using additional space for visited matrix:" << endl;
    print(gridCopy1);
    cout << endl;

    // Applying second approach
    vector<vector<char>> gridCopy2 = grid;
    solve2(gridCopy2);
    cout << "After solving without additional space for visited matrix:" << endl;
    print(gridCopy2);

    return 0;
}
