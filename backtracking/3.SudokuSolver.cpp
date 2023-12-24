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

bool canPlace(vector<vector<char>> &board, int row, int col, char d)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == d || board[row][i] == d)
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
            if (board[r][c] == d)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    int n = board.size();
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (canPlace(board, r, c, ch))
                    {
                        board[r][c] = ch;
                        if (solve(board))
                            return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
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