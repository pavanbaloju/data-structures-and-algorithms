#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an m x n board and a word, find if the word exists in the grid. The word can 
// be constructed from letters of sequentially adjacent cells, where "adjacent" cells 
// are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Intuition:
// We can use backtracking to search for the word on the board. We start from each cell 
// on the board and recursively explore all possible paths to find the word. At each step, 
// we check if the current character in the word matches the character at the current cell 
// on the board. If it matches, we mark the cell as visited and explore all four directions 
// from that cell. If we reach the end of the word during exploration, the word is found. 
// We restore the cell to its original character after exploration to allow backtracking.

// DSA Strategy/Pattern: Backtracking, Depth-First Search (DFS)

// Approach:
// Explanation:
// 1. Define a recursive function 'solve' to search for the word starting from a given position on the board.
// 2. If the index 'wi' reaches the end of the word, return true, indicating the word is found.
// 3. If the position is out of bounds or the current cell doesn't match the word character, return false.
// 4. Mark the current cell as visited and recursively search in all four directions.
// 5. After exploring all directions, restore the original character in the current cell.
// 6. Define the main function 'exist' to iterate through each cell on the board and start searching for the word.
// 7. If the word is found starting from any cell, return true. Otherwise, return false.
// 8. Define the main function 'main' to create a sample input board and word, and call the 'exist' function.
// 9. Example usage: Create a sample input 'board' and 'word', and call the 'exist' function to check if the word exists.

// Time Complexity: O(m * n * 4^l), where m is the number of rows, n is the number of columns, and l is the length of the word.
//                  For each cell on the board, we explore four directions (up, down, left, right) during backtracking.
//                  The worst-case time complexity occurs when searching for the word starting from each cell.
// Space Complexity: O(l) for the recursive call stack, where l is the length of the word.

// Function to recursively search for the word starting from a given position on the board
bool solve(int br, int bc, int wi, vector<vector<char>> &board, string &word) {
    // If the index 'wi' reaches the end of the word, it means the word is found
    if (wi == word.size())
        return true;

    // If the position is out of bounds or the current cell doesn't match the word character, return false
    if (br < 0 || br >= board.size() || bc < 0 || bc >= board[0].size() || board[br][bc] == 'X' || board[br][bc] != word[wi])
        return false;

    // Mark the current cell as visited
    char ch = board[br][bc];
    board[br][bc] = 'X';

    // Recursively search in all four directions
    bool exists = false;
    exists = exists || solve(br - 1, bc, wi + 1, board, word); // Up
    exists = exists || solve(br + 1, bc, wi + 1, board, word); // Down
    exists = exists || solve(br, bc - 1, wi + 1, board, word); // Left
    exists = exists || solve(br, bc + 1, wi + 1, board, word); // Right

    // Restore the original character in the current cell
    board[br][bc] = ch;

    return exists;
}

// Function to check if the given word can be formed on the board
bool exist(vector<vector<char>> &board, string word) {
    // Iterate through each cell on the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // If the starting character of the word matches the current cell, start searching
            if (board[i][j] == word[0]) {
                if (solve(i, j, 0, board, word)) // If the word is found starting from this cell, return true
                    return true;
            }
        }
    }
    return false; // If the word cannot be formed starting from any cell, return false
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}