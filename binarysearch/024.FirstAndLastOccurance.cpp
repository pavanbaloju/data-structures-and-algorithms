#include <iostream>
#include <vector>

using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// 2. Add Intuition
// Intuition:
// We can perform two binary searches to find the starting and ending positions of the target value in the sorted array.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// To find the starting position of the target value, we perform a binary search to find the leftmost occurrence of the target. Similarly, to find the ending position, we perform another binary search to find the rightmost occurrence of the target.

// 5. Add time and space complexity
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1).

// Function to find the starting position of a target value
int findStartingPosition(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();

    // 6. Adds comment on every line in method
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) // If current element is greater or equal to the target
            right = mid;         // Update right pointer
        else
            left = mid + 1; // Update left pointer
    }

    // Check if left pointer is within bounds and if the element at left index is the target
    return (left < nums.size() && nums[left] == target) ? left : -1;
}

// Function to find the ending position of a target value
int findEndingPosition(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();

    // 6. Adds comment on every line in method
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) // If current element is greater than the target
            right = mid;        // Update right pointer
        else
            left = mid + 1; // Update left pointer
    }

    // Return the left pointer as ending position
    return left;
}

// Function to find the range of a target value in a sorted array
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    // Find the starting position of the target value
    int left = findStartingPosition(nums, target);

    // If target is not found, return {-1, -1}
    if (left == -1)
        return {-1, -1};

    // Find the ending position of the target value
    int right = findEndingPosition(nums, target);

    // Return the range of the target value
    return {left, right - 1};
}

int main()
{
    // Example usage
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);

    // 8. Format the output better in main method by printing the output of all approaches
    // Print the starting and ending positions of the target value
    cout << "Starting position: " << result[0] << ", Ending position: " << result[1] << endl;

    return 0;
}
