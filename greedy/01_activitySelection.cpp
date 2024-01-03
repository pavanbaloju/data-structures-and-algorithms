#include <iostream>
#include <vector>
using namespace std;

// sort on finish time
bool sorter(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}

// sort the activities in increasing order of finish time
// consider eachtime
int maxActivities(vector<vector<int>> activities)
{
    sort(activities.begin(), activities.end(), sorter);
    int maxActivities = 0;
    int finish = -1;

    for (int i = 0; i < activities.size(); i++)
    {
        if (activities[i][0] >= finish)
        {
            finish = activities[i][1];
            maxActivities++;
            cout << activities[i][0] << "," << activities[i][1] << endl;
        }
    }

    return maxActivities;
}

int main()
{
    vector<vector<int>> activities = {
        {3, 4},
        {0, 6},
        {1, 2},
        {5, 7},
        {8, 9},
        {5, 9}};

    cout << maxActivities(activities) << endl;
    return 0;
}