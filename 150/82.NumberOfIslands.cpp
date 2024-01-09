#include <iostream>
#include <vector>
using namespace std;

void markIslandVisited(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';

    for (auto nrc : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
        markIslandVisited(grid, i + nrc.first, j + nrc.second);
}

int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                markIslandVisited(grid, i, j);
            }
        }
    }
    return islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << numIslands(grid);
    return 0;
}