#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int shortestPath(vector<vector<int>> &board, vector<pair<int, int>> cells)
{
    int n = board.size();
    vector<bool> visited(n * n + 1, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int curr = p.first;
        int dist = p.second;

        if (curr == n * n)
            return dist;

        q.pop();
        for (int next = curr + 1; next <= min(curr + 6, n * n); next++)
        {
            auto [row, col] = cells[next];
            int dest = board[row][col] != -1 ? board[row][col] : next;
            if (!visited[dest])
            {
                visited[dest] = true;
                q.push({dest, dist + 1});
            }
        }
    }
    return -1;
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size(), ind = 1;
    vector<pair<int, int>> cells(n * n + 1);
    vector<int> cols(n);

    iota(cols.begin(), cols.end(), 0);
    for (int row = n - 1; row >= 0; row--)
    {
        for (int col : cols)
        {
            cells[ind++] = {row, col};
        }
        reverse(cols.begin(), cols.end());
    }
    return shortestPath(board, cells);
}

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};
    cout << snakesAndLadders(board) << endl;
    return 0;
}