#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> ans;
    multiset<int> pointSet{0};

    vector<pair<int, int>> points;

    for (auto coords : buildings)
    {
        points.push_back({coords[0], -coords[2]});
        points.push_back({coords[1], coords[2]});
    }

    sort(points.begin(), points.end());

    int currentMaxHeight = 0;
    for (int i = 0; i < points.size(); i++)
    {
        int currentPoint = points[i].first;
        int heightAtCurrentPoint = points[i].second;

        if (heightAtCurrentPoint < 0)
        {
            pointSet.insert(-heightAtCurrentPoint);
        }
        else
        {
            pointSet.erase(pointSet.find(heightAtCurrentPoint));
        }
        auto maxHeight = *pointSet.rbegin();
        if (currentMaxHeight != maxHeight)
        {
            currentMaxHeight = maxHeight;
            ans.push_back({currentPoint, currentMaxHeight});
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> ans = getSkyline(buildings);
    print(ans);
    return 0;
}