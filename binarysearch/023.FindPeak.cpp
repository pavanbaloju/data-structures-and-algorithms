#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// A peak element in an array is an element that is strictly greater than its neighbors. Given an integer 
// array nums, find a peak element, and return its index. If the array contains multiple peaks, return 
// the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞.

// Intuition:
// This problem can be solved using binary search. We need to find any peak element, not necessarily the 
// global peak. If we observe the array, we can notice that if the current element is smaller than the 
// next element, then there must be a peak on the right side of the current element. Similarly, if the 
// current element is smaller than the previous element, there must be a peak on the left side of the 
// current element. Using this observation, we can perform binary search to find a peak element.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Check if the array contains only one element. If so, return its index as the peak.
// 2. Check if the first element is a peak by comparing it with the second element. If so, return its index.
// 3. Check if the last element is a peak by comparing it with the second last element. If so, return its index.
// 4. Initialize 'start' as 1 and 'end' as 'n - 1', where 'n' is the size of the array.
// 5. While 'start' is less than or equal to 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'nums[mid - 1]' is less than 'nums[mid]' and 'nums[mid]' is greater than 'nums[mid + 1]', 
//       then 'nums[mid]' is a peak element. Return 'mid'.
//    c. If 'nums[mid - 1]' is greater than 'nums[mid]', move towards the left side of the array by updating 
//       'end' to 'mid - 1'.
//    d. If 'nums[mid]' is less than 'nums[mid + 1]', move towards the right side of the array by updating 
//       'start' to 'mid + 1'.
// 6. If no peak element is found, return -1.

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to find a peak element in the array
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1) // Check if the array contains only one element
        return 0;

    int n = nums.size() - 1;
    if (nums[0] > nums[1]) // Check if the first element is a peak
        return 0;
    if (nums[n] > nums[n - 1]) // Check if the last element is a peak
        return n;

    int start = 1, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) // Check if nums[mid] is a peak element
        {
            return mid;
        }
        else if (nums[mid - 1] > nums[mid]) // Move towards the left side of the array
        {
            end = mid - 1;
        }
        else if (nums[mid] < nums[mid + 1]) // Move towards the right side of the array
        {
            start = mid + 1;
        }
    }
    return -1; // No peak element found
}

// Main function
int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4}; // Example array
    cout << findPeakElement(nums); // Find and print a peak element in the array
    return 0;
}
