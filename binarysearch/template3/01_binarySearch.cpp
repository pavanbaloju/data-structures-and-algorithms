#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted (in ascending order) integer array nums of n elements and a target value, 
// return the index of the target value in nums. If the target is not found, return -1.

// Intuition:
// We can utilize binary search to efficiently find the target value in the sorted array.
// The binary search algorithm works by repeatedly dividing the search interval in half. 
// At each step, the algorithm compares the middle element of the array with the target value 
// and decides whether to continue searching in the left half, the right half, or if the 
// middle element is the target.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
// 2. While 'start' + 1 is less than 'end':
//    a. Calculate 'mid' as the average of 'start' and 'end'.
//    b. If 'nums[mid]' is equal to the 'target', return 'mid'.
//    c. If 'target' is greater than 'nums[mid]', update 'start' to 'mid'.
//    d. If 'target' is less than 'nums[mid]', update 'end' to 'mid'.
// 3. After the loop, check if 'nums[start]' or 'nums[end]' is equal to the 'target'. 
//    If so, return the index of the found target.
// 4. If the target is not found, return -1.

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to perform binary search
int binarySearch(vector<int> &nums, int target, int start, int end)
{
    if (nums.size() == 0)
        return -1;
    while (start + 1 < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }

    // End Condition: start == end
    if (nums[start] == target)
    {
        return start;
    }
    if (nums[end] == target)
    {
        return end;
    }

    return -1;
}

// Function to search for the target value in the sorted array
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target, 0, nums.size() - 1);
}

// Main function
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6}; // Example sorted array
    cout << search(nums, 3); // Search for the target value and print the index
    return 0;
}
