#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Intuition:
// This problem can be solved efficiently using the sliding window technique.
// We maintain a window that starts from the beginning of the array and expands towards the end as long as the sum of the window is less than the target.
// Once the sum becomes greater than or equal to the target, we shrink the window from the left side while updating the minimum length.

// DSA Strategy/Pattern:
// Sliding Window

// Approach:
// Explanation:
// 1. Initialize variables: `minLen` to store the minimum length, `sum` to store the sum of the current window, and `start` to store the start index of the current window.
// 2. Iterate through the array using the end pointer.
// 3. Add the current element to the sum of the window.
// 4. Check if the sum of the current window is greater than or equal to the target.
// 5. If true, update `minLen` with the minimum of its current value and the length of the current window (`end - start + 1`).
// 6. Shrink the window from the left side by subtracting the element at the start index and move the start index to the right until the sum becomes less than the target.
// 7. Return `minLen`.

// Time Complexity: O(n) - Single pass through the input array.
// Space Complexity: O(1) - Constant space is used.

// Function to find the minimum length of a contiguous subarray whose sum is greater than or equal to the given target.
int minSubArrayLen(int target, vector<int> &nums)
{
    // Initialize the minimum length to a maximum value.
    int minLen = INT_MAX;
    // Initialize the sum of the current window.
    int sum = 0;
    // Initialize the start index of the current window.
    int start = 0;

    // Iterate through the array using the end pointer.
    for (int end = 0; end < nums.size(); end++)
    {
        // Add the current element to the sum of the window.
        sum += nums[end];

        // Check if the sum of the current window is greater than or equal to the target.
        while (sum >= target)
        {
            // Update the minimum length if the current window length is smaller.
            minLen = min(minLen, end - start + 1);
            // Shrink the window from the left side by subtracting the element at the start index.
            sum -= nums[start];
            // Move the start index to the right.
            start++;
        }
    }
    // If no subarray is found, return 0. Otherwise, return the minimum length.
    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    // Example usage
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl; // Output the minimum length
    return 0;
}
