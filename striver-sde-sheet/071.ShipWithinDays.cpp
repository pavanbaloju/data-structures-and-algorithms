#include <iostream>
#include <vector>
#include <numeric> // For accumulate
using namespace std;

// Problem Statement:
// You have a list of weights `weights` representing the weights of packages to be shipped. You need to ship all the packages within `days` days.
// The constraint is that you can only ship one package per day, and you cannot break a package and ship its parts on different days. 
// The goal is to find the minimum weight capacity of the ship that will allow you to ship all the packages within `days` days.

// Intuition:
// We need to find the minimum weight capacity of the ship such that all packages can be shipped within `days` days. 
// Since we can only ship one package per day, we can use binary search to find the minimum weight capacity.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Set the range of possible weight capacities as [maximum weight in `weights`, sum of all weights in `weights`].
// 2. Perform binary search on the range.
// 3. For each mid value, check if all packages can be shipped within `days` days using a helper function `canShipWithinDays`.
// 4. If all packages can be shipped within `days` days with the mid capacity, search on the left side of the range; otherwise, search on the right side.
// 5. Continue the binary search until the range converges to a single value.
// 6. Return the minimum weight capacity.

// Time Complexity: O(n * log(sum of all weights)), where 'n' is the number of packages.
// Space Complexity: O(1).

// Helper function to check if all packages can be shipped within `days` days with given weight capacity
bool canShipWithinDays(vector<int> &weights, int capacity, int days)
{
    int currentCapacity = 0;
    int currentDays = 1;

    for (int weight : weights)
    {
        if (currentCapacity + weight > capacity)
        {
            // If adding the current weight exceeds the capacity, start a new day
            currentCapacity = weight;
            currentDays++;
        }
        else
        {
            // Otherwise, continue adding the weight to the current day
            currentCapacity += weight;
        }

        // If the number of days exceeds the given days, return false
        if (currentDays > days)
        {
            return false;
        }
    }

    // If all packages are shipped within the given days, return true
    return true;
}

// Function to find the minimum weight capacity of the ship using binary search
int shipWithinDays(vector<int> &weights, int days)
{
    // Set the range of possible weight capacities
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    // Perform binary search to find the minimum weight capacity
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (canShipWithinDays(weights, mid, days))
        {
            // If all packages can be shipped within mid capacity, search on the left side
            high = mid - 1;
        }
        else
        {
            // Otherwise, search on the right side
            low = mid + 1;
        }
    }

    // Return the minimum weight capacity
    return low;
}

// Main function
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    // Output the minimum weight capacity
    cout << "Minimum weight capacity: " << shipWithinDays(weights, days) << endl;

    return 0;
}
