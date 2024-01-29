#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int maxPoints = 0;
    for (int i = 0; i < points.size(); i++)
    {
        unordered_map<double, int> pointsOnSlope = unordered_map<double, int>();
        for (int j = i + 1; j < points.size(); j++)
        {
            double slope = INT_MAX;
            if (points[i][0] != points[j][0])
            {
                slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
            }

            pointsOnSlope[slope]++;
            maxPoints = max(maxPoints, pointsOnSlope[slope]);
        }
    }
    return maxPoints + 1;
}

int main()
{
    // vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    vector<vector<int>> points{{1, 1}, {2, 2}, {3, 3}};
    cout << maxPoints(points);
    return 0;
}