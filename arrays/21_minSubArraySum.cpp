#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Problem Statement:
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target.
// If there is no such subarray, return 0 instead.

// Intuition:
// We can use a two-pointer approach to find the minimal length of a contiguous subarray with a sum greater than or equal to the target.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// 1. Initialize minLength to INT_MAX (a large value) to track the minimum length of the subarray.
// 2. Initialize sum to 0 to track the sum of elements in the current window.
// 3. Initialize left pointer to 0 to represent the start of the window.
// 4. Iterate through the array with the right pointer:
//    a. Add the current element to the sum.
//    b. While the sum is greater than or equal to the target:
//       - Update minLength by taking the minimum of its current value and the length of the current window (right - left + 1).
//       - Move the left pointer to the right and subtract the element at the left pointer from the sum.
// 5. If minLength is still INT_MAX, return 0, indicating no subarray with sum >= target was found.
//    Otherwise, return minLength.
// 6. Time Complexity: O(n), where n is the number of elements in the input array. We iterate through the array once.
// 7. Space Complexity: O(1), as we use only a constant amount of extra space.

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int minLength = INT_MAX; // Initialize the minimum length to a large value
    int sum = 0;             // Initialize the sum of elements in the current window
    int left = 0;            // Initialize the left pointer of the sliding window

    // Iterate through the array with the right pointer
    for (int right = 0; right < n; ++right)
    {
        sum += nums[right]; // Add the current element to the sum

        // If the sum becomes greater than or equal to the target
        while (sum >= target)
        {
            minLength = min(minLength, right - left + 1); // Update the minimum length
            sum -= nums[left++];                          // Move the left pointer to the right and subtract the element from the sum
        }
    }

    // If minLength is still INT_MAX, no subarray with sum >= target was found, return 0
    // Otherwise, return the minimum length
    return minLength == INT_MAX ? 0 : minLength;
}

int main()
{
    // Example usage
    vector<int> nums = {2, 3, 1, 2, 4, 3};        // Input array
    int target = 7;                               // Target sum
    int minLength = minSubArrayLen(target, nums); // Find the minimum subarray length
    cout << "Minimum size of subarray with sum greater than or equal to " << target << " is: " << minLength << endl;
    return 0;
}
