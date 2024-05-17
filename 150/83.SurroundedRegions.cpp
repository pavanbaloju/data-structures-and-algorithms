#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c)
{
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] == 'X')
        return;

    visited[r][c] = true;
    for (auto nrc : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
        helper(board, visited, r + nrc.first, c + nrc.second);
}

void solve(vector<vector<char>> &board)
{
    int R = board.size(), C = board[0].size();
    vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));

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

// with out additional space for visited
void helper2(vector<vector<char>> &board, int r, int c)
{
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'M')
        return;

    board[r][c] = 'M';
    for (auto nrc : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
        helper2(board, r + nrc.first, c + nrc.second);
}

void solve2(vector<vector<char>> &board)
{
    int R = board.size(), C = board[0].size();

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


void print(vector<vector<char>> &board)
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
        ;
    }
}

int main()
{
    vector<vector<char>> grid =
        {
            {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
            {'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'}};

    solve(grid);
    print(grid);
    return 0;
}
