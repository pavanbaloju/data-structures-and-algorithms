#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers nums sorted in ascending order, find the starting and ending position 
// of a given target value in the array. If the target is not found in the array, return [-1, -1].

// Intuition:
// We can use binary search to efficiently find the starting and ending positions of the target value.
// Two approaches are discussed here: 
// 1. Using two separate binary searches for the starting and ending positions.
// 2. Using a single binary search to find the lower bound of the target value and its next element.

// DSA Strategy:
// Binary Search

// Approach 1:
// 1. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
// 2. Use binary search to find the first occurrence of the target:
//    a. If 'nums[mid]' is equal to 'target', update 'first' as 'mid' and search in the left half by 
//       updating 'end' to 'mid - 1'.
//    b. If 'target' is greater than 'nums[mid]', update 'start' to 'mid + 1'.
//    c. If 'target' is less than 'nums[mid]', update 'end' to 'mid - 1'.
// 3. Use binary search to find the last occurrence of the target:
//    a. If 'nums[mid]' is equal to 'target', update 'last' as 'mid' and search in the right half by 
//       updating 'start' to 'mid + 1'.
//    b. If 'target' is greater than 'nums[mid]', update 'start' to 'mid + 1'.
//    c. If 'target' is less than 'nums[mid]', update 'end' to 'mid - 1'.
// 4. Return the range [first, last].

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to find the starting and ending position of the target value in the array (Approach 1)
vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return {-1, -1};

    int start = 0, end = nums.size() - 1;
    int first = -1, last = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (first == -1)
    {
        return {-1, -1};
    }

    start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return {first, last};
}

// Approach 2:
// 1. Implement a function 'lowerBound' to find the lower bound of the target value in the sorted array.
// 2. Find the lower bound of 'target' and 'target + 1' using 'lowerBound' function.
// 3. If the lower bound of 'target' exists and equals 'target', set 'first' to the lower bound 
//    and 'last' to the lower bound of 'target + 1' minus 1.
// 4. Return the range [first, last].

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to find the lower bound of the target value (Approach 2)
int lowerBound(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

// Function to find the starting and ending position of the target value in the array (Approach 2)
vector<int> searchRange2(vector<int> &nums, int target)
{
    int first = lowerBound(nums, target);
    int last = lowerBound(nums, target + 1) - 1;
    if (first < nums.size() && nums[first] == target)
    {
        return {first, last};
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res1 = searchRange(nums, 8);
    vector<int> res2 = searchRange2(nums, 8);

    // Output for Approach 1
    cout << "Approach 1 Output: ";
    for (int x : res1)
        cout << x << " ";
    cout << endl;

    // Output for Approach 2
    cout << "Approach 2 Output: ";
    for (int x : res2)
        cout << x << " ";
    cout << endl;

    return 0;
}
