#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted and rotated array 'nums' with distinct elements, return the index of the target element. 
// If the target element does not exist in the array, return -1.

// Intuition:
// Since the array is sorted and rotated, we can use a modified binary search algorithm to find the target element efficiently.
// The idea is to determine whether the left half or the right half of the array is sorted, and then check if the target lies within the sorted half.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
// 2. While 'start' is less than or equal to 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'target' is equal to 'nums[mid]', return 'mid' (target found).
//    c. Check if the left half (from 'start' to 'mid') or the right half (from 'mid' to 'end') is sorted:
//       i. If the left half is sorted:
//          - If 'target' lies between 'nums[start]' and 'nums[mid]', update 'end' to 'mid - 1'.
//          - Otherwise, update 'start' to 'mid + 1'.
//       ii. If the right half is sorted:
//          - If 'target' lies between 'nums[mid]' and 'nums[end]', update 'start' to 'mid + 1'.
//          - Otherwise, update 'end' to 'mid - 1'.
// 3. If the target is not found, return -1.

// Time Complexity: O(log n), where 'n' is the number of elements in the array.
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
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0); // Test search function
    return 0;
}
