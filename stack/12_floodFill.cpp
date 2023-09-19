#include <iostream>
#include <vector>
using namespace std;

void fill(vector<vector<int>> &image, int sr, int sc, int color, int startColor)
{
    if (sr < 0 || sr == image.size() || sc < 0 || sc > image[0].size() 
    || color == image[sr][sc] || startColor != image[sr][sc])
    {
        return;
    }
    image[sr][sc] = color;
    fill(image, sr + 1, sc, color, startColor);
    fill(image, sr - 1, sc, color, startColor);
    fill(image, sr, sc + 1, color, startColor);
    fill(image, sr, sc - 1, color, startColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    fill(image, sr, sc, color, image[sr][sc]);
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