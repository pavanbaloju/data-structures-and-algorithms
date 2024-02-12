#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm library for using the sort function
using namespace std;

// Problem Statement: Given a list of meetings with start and finish times, 
// find the maximum number of meetings that can be conducted without overlapping.
// Intuition: Sort the meetings based on their finish times. 
// Then, iterate through the sorted meetings and select the meetings that do not overlap with each other.

// DSA Strategy: Greedy Algorithm

// Approach:
// 1. Sort the meetings based on their finish times using the custom comparator function `sorter`.
// 2. Initialize the count of maximum meetings as 1 and set the end time of the first meeting.
// 3. Iterate through the sorted meetings starting from the second meeting.
// 4. If the start time of the current meeting is greater than the end time of the previous meeting,
//    increment the count of maximum meetings and update the end time to the finish time of the current meeting.
// 5. Return the maximum number of meetings.

// Time Complexity: O(n log n) - Sorting the meetings based on finish times.
// Space Complexity: O(1) - Constant space is used.

// Function to sort meetings based on finish time
bool sorter(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}

// Function to find the maximum number of meetings that can be conducted
int maxMeetings(vector<vector<int>> meetings)
{
    // Sort meetings based on finish time
    sort(meetings.begin(), meetings.end(), sorter);

    int maxMeetings = 1;      // Initialize the count of maximum meetings
    int end = meetings[0][1]; // Set the end time of the first meeting

    // Iterate through the sorted meetings
    for (int i = 1; i < meetings.size(); i++)
    {
        // Check if the start time of the current meeting is greater than the end time of the previous meeting
        if (meetings[i][0] > end)
        {
            maxMeetings++;        // Increment the count of maximum meetings
            end = meetings[i][1]; // Update the end time to the finish time of the current meeting
        }
    }

    return maxMeetings; // Return the maximum number of meetings
}

int main()
{
    // Input: List of meetings with start and finish times
    vector<vector<int>> meetings = {
        {3, 4},
        {0, 6},
        {1, 2},
        {5, 7},
        {8, 9},
        {5, 9}};

    // Call the function to find the maximum number of meetings
    cout << "Maximum number of meetings: " << maxMeetings(meetings) << endl;

    return 0;
}
