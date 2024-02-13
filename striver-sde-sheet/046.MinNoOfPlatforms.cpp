#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Method 1: Brute Force Method
// Problem Statement:
// Given arrival and departure times of trains, find the minimum number of platforms required at the railway station
// to avoid any delay in train departures.
//
// Intuition:
// This method compares each pair of trains to check if their arrival and departure times overlap.
// By comparing all pairs, it finds the maximum number of trains that can be accommodated simultaneously.
//
// DSA Strategy Used:
// - Nested loop iteration to compare all pairs of trains.
//
// Approach:
// - Iterate through each pair of trains and check if their arrival and departure times overlap.
// - Increment a counter for each train that doesn't overlap with others.
// - Return the maximum counter value, representing the minimum number of platforms required.
//
// Time Complexity: O(n^2) - Nested loop iteration.
// Space Complexity: O(1) - Constant space used.

int countPlatformsBrute(vector<int> arr, vector<int> dep)
{
    int n = arr.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            // Check if the arrival and departure times overlap for the current pair of trains.
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++; // Increment count if there is an overlap.
            }
        }
        ans = max(ans, count); // Update the maximum count of platforms needed.
    }
    return ans; // Return the final result.
}

// Method 2: Greedy Method
//
// Intuition:
// This method uses a greedy approach by sorting the arrival and departure times of trains.
// It then iterates through the sorted arrays, maintaining a count of trains present at any given time.
// By incrementing the count when a train arrives and decrementing it when a train departs,
// it finds the maximum count, which represents the minimum number of platforms required.
//
// DSA Strategy Used:
// - Sorting to arrange the trains in chronological order.
// - Iteration to traverse the sorted arrays and update counts based on train arrivals and departures.
//
// Approach:
// - Sort the arrival and departure times of trains.
// - Initialize two pointers to traverse the arrival and departure arrays.
// - Initialize variables to keep track of the current and maximum counts of trains present at any time.
// - Iterate through the sorted arrays and update the counts based on train arrivals and departures.
// - Return the maximum count, representing the minimum number of platforms required.
//
// Time Complexity: O(n log n) - Sorting the arrival and departure arrays.
// Space Complexity: O(1) - Constant space used.

int countPlatformsGreedy(vector<int> arr, vector<int> dep)
{
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the arrival times.
    sort(dep.begin(), dep.end()); // Sort the departure times.

    int count = 1; // Initialize the current count of platforms.
    int ans = 1;   // Initialize the maximum count of platforms needed.
    int i = 1, j = 0; // Pointers to traverse the arrival and departure arrays, respectively.

    while (i < n && j < n)
    {
        // If the arrival time of the current train is less than or equal to the departure time of the other train,
        // it means a platform is needed, so increment 'count' and move 'i' to the next arrival time.
        if (arr[i] <= dep[j])
        {
            i++;
            count++;
        }
        else
        {
            // If the arrival time of the current train is greater than the departure time of the other train,
            // it means a platform is freed up, so decrement 'count' and move 'j' to the next departure time.
            j++;
            count--;
        }
        ans = max(ans, count); // Update the maximum count of platforms needed.
    }
    return ans; // Return the final result.
}

// Format the output better in main method
int main()
{
    vector<int> arr{900, 945, 955, 1100, 1500, 1800}, dep{920, 1200, 1130, 1150, 1900, 2000};

    // Output the results
    cout << "Minimum Platforms (Brute Force): " << countPlatformsBrute(arr, dep) << endl;
    cout << "Minimum Platforms (Greedy): " << countPlatformsGreedy(arr, dep) << endl;

    return 0;
}
