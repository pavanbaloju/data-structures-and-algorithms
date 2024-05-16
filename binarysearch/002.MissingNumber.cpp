#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Problem Statement:
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Intuition:
// The problem can be solved using multiple approaches such as Brute Force, Sorting, and Binary Search.
// 1. Brute Force: Calculate the sum of all numbers from 0 to n and subtract the sum of elements in the array. The difference is the missing number.
// 2. Sorting: Sort the array and iterate through it. The first number that does not match its index is the missing number.
// 3. Binary Search: Use binary search to find the first element whose value is not equal to its index. That element's index is the missing number.

// DSA Strategy/Pattern:
// Brute Force, Sorting, Binary Search

// Approach 1 (Brute Force):
// Explanation:
// 1. Calculate the sum of all numbers from 0 to n using the formula (n * (n + 1)) / 2.
// 2. Subtract the sum of elements in the array from the total sum.
// 3. The difference is the missing number.
// 4. Return the missing number.

// Time Complexity: O(n)
// Space Complexity: O(1)

int missingNumber_BruteForce(vector<int> &nums)
{
    int n = nums.size();
    // Calculate the sum of all numbers from 0 to n
    int sum = n * (n + 1) / 2;
    // Subtract each number in the array from the total sum
    for (int num : nums)
    {
        sum -= num;
    }
    // The missing number is the remaining sum
    return sum;
}

// Approach 2 (Sorting):
// Explanation:
// 1. Sort the array.
// 2. Check each number in the sorted array.
// 3. If the current number does not match its index, it is the missing number.
// 4. Return the missing number.

// Time Complexity: O(n log n)
// Space Complexity: O(1) if sorting in place, otherwise O(n)

int missingNumber_Sorting(vector<int> &nums)
{
    // Sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // Check each number in the sorted array
    for (int i = 0; i < n; ++i)
    {
        // If the current number does not match its index, it is the missing number
        if (nums[i] != i)
        {
            return i;
        }
    }
    // If all numbers are present, the missing number is n
    return n;
}

// Approach 3 (Binary Search):
// Explanation:
// 1. Initialize left and right pointers.
// 2. Use binary search to find the first element whose value is not equal to its index.
// 3. At the end of the loop, 'left' will point to the index where the missing number should be.
// 4. Return the missing number.

// Time Complexity: O(log n)
// Space Complexity: O(1)

int missingNumber_BinarySearch(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // If the current middle element is equal to its index, the missing number is on the right side
        if (nums[mid] == mid)
        {
            left = mid + 1;
        }
        // Otherwise, the missing number is on the left side
        else
        {
            right = mid - 1;
        }
    }
    // At the end of the loop, 'left' will point to the index where the missing number should be
    return left;
}

// Main function
int main()
{
    // Example usage
    vector<int> nums = {3, 0, 1};

    // Brute Force
    cout << "Missing number (Brute Force): " << missingNumber_BruteForce(nums) << endl;

    // Sorting
    cout << "Missing number (Sorting): " << missingNumber_Sorting(nums) << endl;

    // Binary Search
    cout << "Missing number (Binary Search): " << missingNumber_BinarySearch(nums) << endl;

    return 0;
}
