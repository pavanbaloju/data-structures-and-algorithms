#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void addAdjacent(vector<vector<int>> &image, int sr, int sc, int color, int startColor, queue<pair<int, int>> &q)
{
    if (sr < 0 || sr == image.size() || sc < 0 || sc == image[0].size())
        return;
    q.push({sr, sc});
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
        return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    int startColor = image[sr][sc];
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        sr = p.first;
        sc = p.second;
        if (color != image[sr][sc] && startColor == image[sr][sc])
        {
            image[sr][sc] = color;
            addAdjacent(image, sr - 1, sc, color, startColor, q);
            addAdjacent(image, sr + 1, sc, color, startColor, q);
            addAdjacent(image, sr, sc - 1, color, startColor, q);
            addAdjacent(image, sr, sc + 1, color, startColor, q);
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    vector<vector<int>> res = floodFill(image, 1, 1, 2);
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}