#include <iostream>
#include <vector>
using namespace std;

// sort on finish time
bool sorter(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}
// same as activity selection
int maxMeetings(vector<vector<int>> meetings)
{
    sort(meetings.begin(), meetings.end(), sorter);
    int maxMeetings = 1;
    int end = meetings[0][1];
    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i][0] > end)
        {
            maxMeetings++;
            end = meetings[i][1];
        }
    }
    return maxMeetings;
}
int main()
{
    vector<vector<int>> meetings = {
        {3, 4},
        {0, 6},
        {1, 2},
        {5, 7},
        {8, 9},
        {5, 9}};

    cout << maxMeetings(meetings) << endl;
    return 0;
}