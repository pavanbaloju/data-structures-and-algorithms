#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool sorter(vector<int> &u, vector<int> &v)
{
    return u[0] <= v[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), sorter);
    int n = intervals.size();
    vector<vector<int>> merged;
    for (auto interval : intervals)
    {
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    // vector<vector<int>> intervals = {{1, 4}, {4, 6}};
    vector<vector<int>> merged = merge(intervals);
    for (auto v : merged)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}