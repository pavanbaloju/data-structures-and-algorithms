#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the 
// sorted rotated array nums, return the minimum element of this array.

// Intuition:
// Since the array is rotated, we can observe that the minimum element will always be on the left side 
// of the rotation. Therefore, we can apply binary search to find the minimum element. The idea is to 
// compare the middle element with the start and end elements of the array to determine which side of 
// the array contains the minimum element.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
// 2. While 'start' is less than 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'nums[start]' is less than 'nums[end]', then 'nums[start]' is the minimum element. Return it.
//    c. If 'nums[start]' is less than or equal to 'nums[mid]', move towards the right side of the array 
//       by updating 'start' to 'mid + 1'.
//    d. Otherwise, move towards the left side of the array by updating 'end' to 'mid'.
// 3. Return 'nums[start]' as the minimum element.

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to find the minimum element in the rotated sorted array
int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[start] < nums[end]) // Check if the array is not rotated
        {
            return nums[start]; // Minimum element is nums[start]
        }
        if (nums[start] <= nums[mid]) // Move towards the right side of the array
        {
            start = mid + 1;
        }
        else // Move towards the left side of the array
        {
            end = mid;
        }
    }
    return nums[start]; // Return the minimum element
}

// Main function
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2}; // Example rotated sorted array
    cout << findMin(nums); // Find and print the minimum element
    return 0;
}
