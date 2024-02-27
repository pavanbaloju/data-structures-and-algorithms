#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Problem Statement:
// Given a row of stalls represented by their positions on a horizontal line, and the number of cows 'k',
// find the maximum possible minimum distance between cows, such that each cow is placed in a stall and
// the distance between any two cows is at least the minimum distance.

// Intuition:
// To maximize the minimum distance between cows, we can use binary search to find the maximum possible minimum distance.
// We start with a minimum distance of 1 and keep increasing it until we cannot place all cows with the given distance.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Sort the positions of stalls in ascending order.
// 2. Define a function 'canWePlace' to check if we can place cows with a given minimum distance.
// 3. Iterate through the sorted stalls and check if the distance between the current stall and the last placed cow
//    is greater than or equal to the given distance. If so, place the next cow.
// 4. If we can place all cows with the given distance, return true; otherwise, return false.
// 5. Define a function 'aggressiveCows' to find the maximum possible minimum distance using binary search.
// 6. Set the limit as the maximum possible distance between stalls (difference between the last and first stall positions).
// 7. Perform binary search to find the maximum possible minimum distance by checking if we can place all cows with
//    each possible distance from 1 to the limit.
// 8. Return the maximum possible minimum distance found using binary search.
// 9. In the main function, provide the positions of stalls and the number of cows.
// 10. Calculate the maximum possible minimum distance using the 'aggressiveCows' function.
// 11. Output the result.

// Time Complexity: O(n * log(maxDistance)), where 'n' is the number of stalls and 'maxDistance' is the maximum possible distance between stalls.
// Space Complexity: O(1).

// Function to check if we can place cows with given minimum distance
bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size(); // Number of stalls
    int cntCows = 1;       // Number of cows placed
    int last = stalls[0];  // Position of last placed cow

    // Iterate through the stalls
    for (int i = 1; i < n; i++)
    {
        // If the distance between the current stall and the last placed cow is greater than or equal to the given distance
        if (stalls[i] - last >= dist)
        {
            cntCows++;        // Place the next cow
            last = stalls[i]; // Update the position of the last placed cow
        }

        // If we have placed all cows, return true
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size(); // size of array
    // sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    // apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

// Main function
int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};                            // Positions of stalls
    int k = 4;                                                           // Number of cows
    int ans = aggressiveCows(stalls, k);                                 // Calculate the maximum possible minimum distance
    cout << "The maximum possible minimum distance is: " << ans << "\n"; // Output the result
    return 0;
}
