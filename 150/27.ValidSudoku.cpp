#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// hashing
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

bool isValidSudoku3(vector<vector<char>> &board)
{
    bool iisdigit[9][9]{};
    bool jisdigit[9][9]{};
    bool ijisdigit[3][3][9]{};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int d = board[i][j] - '0' - 1;
                if (iisdigit[i][d])
                {
                    return false;
                }
                iisdigit[i][d] = true;
                if (jisdigit[j][d])
                {
                    return false;
                }
                jisdigit[j][d] = true;
                if (ijisdigit[i / 3][j / 3][d])
                {
                    return false;
                }
                ijisdigit[i / 3][j / 3][d] = true;
            }
        }
    }
    return true;
}

// no hashing
bool canPlace(vector<vector<char>> &board, int row, int col)
{
    char d = board[row][col];
    for (int i = 0; i < 9; i++)
    {
        if ((board[i][col] == d && i != row) || (board[row][i] == d && i != col))
        {
            return false;
        }
    }
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for (int r = sr; r < sr + 3; r++)
    {
        for (int c = sc; c < sc + 3; c++)
        {
            if (board[r][c] == d && r != row && c != col)
                return false;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] != '.' && !canPlace(board, r, c))
            {
                return false;
            }
        }
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
    cout << isValidSudoku2(board);
    cout << isValidSudoku3(board);
}