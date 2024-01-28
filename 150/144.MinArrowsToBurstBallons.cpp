#include <iostream>
#include <vector>
using namespace std;

static bool sorter(vector<int> &p1, vector<int> &p2)
{
    return p1[1] < p2[1];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), sorter);

    long end = LONG_MIN, arrows = 0;
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i][0] > end)
        {
            end = points[i][1];
            arrows++;
        }
    }
    return arrows;
}

int main()
{
    // [[10,16],[2,8],[1,6],[7,12]]
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}