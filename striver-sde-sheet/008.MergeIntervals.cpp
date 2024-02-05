// https://leetcode.com/problems/merge-intervals/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals using brute force approach
// Intuition:
// - Iterate through each interval.
// - For each interval, check if it overlaps with any other interval.
// - If it overlaps, merge it with the overlapping interval.
// - Repeat the process until no more merging is possible.
// Time Complexity: O(n^2) where n is the number of intervals
//   - It takes O(n) time to merge an interval with every other interval.
// Space Complexity: O(1)
vector<vector<int>> mergeOverlappingIntervalsBrute(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    for (int i = 0; i < intervals.size(); ++i)
    {
        vector<int> merged = intervals[i];
        for (int j = i + 1; j < intervals.size(); ++j)
        {
            if (intervals[j][0] <= merged[1])
            {
                merged[1] = max(merged[1], intervals[j][1]);
                merged[0] = min(merged[0], intervals[j][0]);
                intervals.erase(intervals.begin() + j);
                --j;
            }
        }
        mergedIntervals.push_back(merged);
    }
    return mergedIntervals;
}

// Function to merge overlapping intervals using optimal approach
// Intuition:
// - Sort the intervals based on their start times.
// - Iterate through the sorted intervals.
// - If the current interval overlaps with the previous one, merge them.
// - Otherwise, add the current interval to the merged intervals list.
// Time Complexity: O(n log n) where n is the number of intervals
//   - Sorting takes O(n log n) time.
//   - Merging takes O(n) time.
// Space Complexity: O(n) for storing the merged intervals
vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    vector<vector<int>> mergedIntervals = {intervals[0]};
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] <= mergedIntervals.back()[1])
        {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
        }
        else
        {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    return mergedIntervals;
}

// Utility function to print intervals
void printIntervals(const vector<vector<int>> &intervals)
{
    for (const auto &interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Brute force approach
    cout << "Merged Intervals (Brute Force): ";
    printIntervals(mergeOverlappingIntervalsBrute(intervals));

    // Optimal approach
    cout << "Merged Intervals (Optimal): ";
    printIntervals(mergeOverlappingIntervalsOptimal(intervals));

    return 0;
}
