#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers nums, find the dominant index. The dominant index
// is the index where nums[i] is greater than or equal to twice the value of every
// other element in the array. If no such index exists, return -1.

// Function to find the dominant index in the given array.
// Intuition:
// We traverse the array twice:
// 1. In the first pass, we find the index of the maximum and second maximum elements.
// 2. In the second pass, we check if the maximum element is at least twice as large
//    as the second maximum element. If it is, we return the index of the maximum element.
//    Otherwise, we return -1.
// Approach:
// - Initialize max and max2 to -1 (or any invalid index).
// - Traverse the array to find the maximum element (max) and its index.
// - Traverse the array again to find the second maximum element (max2).
// - If max is at least twice as large as max2, return the index of max.
// - Otherwise, return -1.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int dominantIndex(vector<int> &nums)
{
    int max = -1, max2 = -1, count = nums.size();

    // First pass: Find the index of the maximum and second maximum elements.
    for (int i = 0; i < count; i++)
    {
        // Update max and max2 based on current element.
        if (max == -1 || nums[i] > nums[max])
        {
            max2 = max;
            max = i;
        }
        else if (max2 == -1 || nums[i] > nums[max2])
        {
            max2 = i;
        }
    }

    // Second pass: Check if the maximum element is at least twice as large as the second maximum.
    if (nums[max] >= 2 * nums[max2])
    {
        return max;
    }
    else
    {
        return -1;
    }
}

// Function to find the dominant index in the given array using another approach.
// Intuition:
// We traverse the array twice:
// 1. In the first pass, we find the maximum element (max) and its index (maxi).
// 2. In the second pass, we check if the maximum element is at least twice as large
//    as every other element. If it is, we return its index (maxi).
//    Otherwise, we return -1.
// Approach:
// - Initialize max to INT_MIN and maxi to -1.
// - Traverse the array to find the maximum element (max) and its index (maxi).
// - Traverse the array again and check if every element is at most half of max.
// - If any element violates the condition, return -1.
// - Otherwise, return maxi.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int dominantIndex2(vector<int> &nums)
{
    int max = INT_MIN, maxi = -1, count = nums.size();

    // First pass: Find the maximum element (max) and its index (maxi).
    for (int i = 0; i < count; i++)
    {
        // Update max and maxi based on current element.
        if (nums[i] > max)
        {
            max = nums[i];
            maxi = i;
        }
    }

    // Second pass: Check if every element is at most half of max.
    for (int i = 0; i < count; i++)
    {
        // Skip the maximum element.
        if (i == maxi)
        {
            continue;
        }
        // If any other element is greater than half of max, return -1.
        else if (max < nums[i] * 2)
        {
            return -1;
        }
    }
    return maxi;
}

int main()
{
    // Test the dominantIndex function with an example array.
    vector<int> nums = {2, 1};
    int p = dominantIndex(nums);

    // Output the dominant index.
    cout << p;
    return 0;
}
