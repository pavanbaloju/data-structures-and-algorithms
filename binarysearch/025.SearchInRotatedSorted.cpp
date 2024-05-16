#include <iostream>
#include <vector>

using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given a rotated sorted array, find the index of a target element.

// 2. Add Intuition
// Intuition:
// We can use a modified binary search to find the target element in the rotated sorted array.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// We perform a modified binary search to find the target element in the rotated sorted array. 
// At each step, we check if the left half or the right half is sorted, and then determine if the target lies within the sorted half. 
// We update the search range accordingly and continue the search until we find the target or exhaust the search space.

// 5. Add time and space complexity
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1).

// Function to search for the target element in the rotated sorted array
int search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target == nums[mid])
            return mid; // Target found

        // Check if the left half is sorted
        if (nums[start] <= nums[mid])
        {
            // Check if target lies within the left half
            if (nums[start] <= target && target <= nums[mid])
                end = mid - 1; // Update end to mid - 1
            else
                start = mid + 1; // Update start to mid + 1
        }
        // If the right half is sorted
        else
        {
            // Check if target lies within the right half
            if (nums[mid] <= target && target <= nums[end])
                start = mid + 1; // Update start to mid + 1
            else
                end = mid - 1; // Update end to mid - 1
        }
    }
    return -1; // Target not found
}

// Main function
int main()
{
    // Example usage
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0); // Test search function
    return 0;
}
