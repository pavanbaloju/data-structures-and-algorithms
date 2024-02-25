#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted array 'nums' of distinct integers, return the index of 'target' if it is present in the array. 
// If it is not present, return -1.

// Intuition:
// This problem can be efficiently solved using the binary search algorithm since the array is sorted.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Implement the binarySearch function to search for the target in the given sorted array.
// 2. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
// 3. While 'start' is less than 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'nums[mid]' is equal to 'target', return 'mid' (target found).
//    c. If 'target' is greater than 'nums[mid]', update 'start' to 'mid + 1'.
//    d. If 'target' is less than 'nums[mid]', update 'end' to 'mid'.
// 4. After the loop, if 'nums[start]' is equal to 'target', return 'start'. Otherwise, return -1.

// Time Complexity: O(log n), where 'n' is the number of elements in the array.
// Space Complexity: O(1).

// Function to perform binary search for the target element
int binarySearch(vector<int> &nums, int target, int start, int end)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid; // Target found
        }
        else if (target > nums[mid])
        {
            start = mid + 1; // Update start to mid + 1
        }
        else
        {
            end = mid; // Update end to mid
        }
    }

    // End Condition: start == end
    if (nums[start] == target)
    {
        return start; // Target found
    }

    return -1; // Target not found
}

// Function to search for the target element in the sorted array
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target, 0, nums.size() - 1);
}

// Main function
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << search(nums, 3); // Test search function
    return 0;
}
