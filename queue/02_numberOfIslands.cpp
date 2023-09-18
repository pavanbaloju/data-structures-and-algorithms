#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addAdjacent(int r, int c, int rows, int cols, vector<vector<char>> &grid, queue<pair<int, int>> &q)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
    {
        return;
    }
    q.push({r, c});
    grid[r][c] = '0';
}
int numIslands(vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    int islands = 0;
    int rows = grid.size(), cols = grid[0].size();

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                q.push({i, j});
                grid[i][j] = '0';
                ++islands;

                while (!q.empty())
                {
                    pair<int, int> pair = q.front();
                    q.pop();
                    int r = pair.first;
                    int c = pair.second;
                    addAdjacent(r - 1, c, rows, cols, grid, q);
                    addAdjacent(r + 1, c, rows, cols, grid, q);
                    addAdjacent(r, c - 1, rows, cols, grid, q);
                    addAdjacent(r, c + 1, rows, cols, grid, q);
                }
            }
        }
    }
    return islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << numIslands(grid);
    return 0;
}