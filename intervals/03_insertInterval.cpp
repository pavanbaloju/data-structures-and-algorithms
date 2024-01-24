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

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    return merge(intervals);
}

vector<vector<int>> insertOpt(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0;
    int j = 0;
    int s = intervals.size();
    vector<vector<int>> ans;

    // {2, 3} and {4, 6}
    while (i < s && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i++]);
    }

    // {2, 5} and {4, 6}
    vector<int> temp = newInterval;
    while (i < s && intervals[i][0] <= newInterval[1])
    {
        temp = {min(intervals[i][0], temp[0]), max(intervals[i][1], newInterval[1])};
        i++;
    }
    ans.push_back(temp);

    // {6, 8} and {4, 5}
    while (i < s)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}};
    vector<int> newInterval{3, 4};
    vector<vector<int>> merged = insertOpt(intervals, newInterval);
    for (auto v : merged)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}