#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<char> row, col;
    vector<unordered_set<char>> grid(9);

    for (int i = 0; i < 9; i++)
    {
        row.clear();
        col.clear();
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (row.find(board[i][j]) != row.end())
                    return false;
                row.insert(board[i][j]);
            }

            if (board[j][i] != '.')
            {
                if (col.find(board[j][i]) != col.end())
                    return false;
                col.insert(board[j][i]);
            }

            if (board[i][j] != '.')
            {
                int loc = (i / 3) * 3 + j / 3;
                if (grid[loc].find(board[i][j]) != grid[loc].end())
                    return false;
                grid[loc].insert(board[i][j]);
            }
        }
    }
    return true;
}

bool isValidSudoku2(vector<vector<char>> &board)
{
    unordered_set<string> visited;

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
                continue;
            const string c(1, board[i][j]);
            if (!visited.insert(c + "@row" + to_string(i)).second ||
                !visited.insert(c + "@col" + to_string(j)).second ||
                !visited.insert(c + "@box" + to_string(i / 3) + to_string(j / 3)).second)
                return false;
        }

    return true;
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
    cout << isValidSudoku(board);
}