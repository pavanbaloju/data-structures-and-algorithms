#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addAdjacent(int r, int c, int rows, int cols, vector<vector<int>> &res, queue<pair<int, int>> &q, int dist)
{
    if (r < 0 || r == rows || c < 0 || c == cols || res[r][c] != -1)
    {
        return;
    }
    q.push({r, c});
    res[r][c] = dist;
}
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> res(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;

        addAdjacent(r + 1, c, rows, cols, res, q, res[r][c] + 1);
        addAdjacent(r - 1, c, rows, cols, res, q, res[r][c] + 1);
        addAdjacent(r, c + 1, rows, cols, res, q, res[r][c] + 1);
        addAdjacent(r, c - 1, rows, cols, res, q, res[r][c] + 1);
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    vector<vector<int>> res = updateMatrix(mat);
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}