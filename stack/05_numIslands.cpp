#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

void visitAdjacent(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';
    visitAdjacent(grid, i - 1, j);
    visitAdjacent(grid, i + 1, j);
    visitAdjacent(grid, i, j - 1);
    visitAdjacent(grid, i, j + 1);
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
                visitAdjacent(grid, i, j);
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