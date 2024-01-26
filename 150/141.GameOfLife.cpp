#include <iostream>
#include <vector>
using namespace std;

int neighbors(int r, int c, vector<vector<int>> &board)
{
    int i, j, count = 0;
    for (i = r - 1; i <= r + 1; i++)
    {
        for (j = c - 1; j <= c + 1; j++)
        {
            if ((i == r && j == c) || (i < 0 || j < 0) || (i >= board.size() || j >= board[0].size()))
            {
                continue;
            }
            if (board[i][j] == 1 || board[i][j] == 3)
            {
                count++;
            }
        }
    }
    return count;
}

void gameOfLife(vector<vector<int>> &board)
{
    int R = board.size(), C = board[0].size();
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int nbrs = neighbors(r, c, board);
            int &cell = board[r][c];
            if (cell)
            {
                if (nbrs == 2 || nbrs == 3)
                {
                    cell = 3;
                }
            }
            else if (nbrs == 3)
            {
                cell = 2;
            }
        }
    }
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int &cell = board[r][c];
            if (cell == 1)
                cell = 0;
            else if (cell == 2 || cell == 3)
                cell = 1;
        }
    }
}

void print(vector<vector<int>> board)
{
    for (auto row : board)
    {
        for (auto cell : row)
            cout << cell << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    print(board);
    gameOfLife(board);
    print(board);
    return 0;
}