#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> board)
{
    for (string s : board)
    {
        cout << s << endl;
    }
    cout << endl;
}

bool isNotUnderAttack(vector<string> &board, int row, int col)
{
    int n = board.size();

    // row
    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }
    // col
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    // check left \ diagonal
    for (int i = 0; i < n; i++)
    {
        if (row - i >= 0 && col - i >= 0)
        {
            if (board[row - i][col - i] == 'Q')
                return false;
        }
    }

    // check right diagonal /
    for (int i = 0; i < n; i++)
    {
        if (row - i >= 0 && col + i < n)
        {
            if (board[row - i][col + i] == 'Q')
                return false;
        }
    }
    return true;
}

void solve(vector<string> &board, int row, int &count)
{
    int n = board.size();
    if (row == n)
    {
        count++;
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (isNotUnderAttack(board, row, c))
        {
            board[row][c] = 'Q';
            solve(board, row + 1, count);
            board[row][c] = '.';
        }
    }
}

int totalNQueens(int n)
{
    vector<string> board = vector<string>(n, string(n, '.'));
    int count = 0;
    solve(board, 0, count);
    return count;
}

int main()
{
    cout << totalNQueens(5);
}