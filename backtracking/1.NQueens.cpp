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

void solve(vector<string> &board, int row, vector<vector<string>> &ans)
{
    int n = board.size();
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (isNotUnderAttack(board, row, c))
        {
            board[row][c] = 'Q';
            solve(board, row + 1, ans);
            board[row][c] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board = vector<string>(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(board, 0, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);

    for (auto board : ans)
        print(board);
}