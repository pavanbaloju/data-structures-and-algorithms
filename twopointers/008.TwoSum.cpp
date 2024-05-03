#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given an array of integers 'nums' and an integer 'target', return the indices of the two numbers such that they add up to 'target'.

// Intuition:
// We'll use two approaches to solve the problem:
// 1. Two Pointers: Sort the array and use two pointers to find the sum.
// 2. Hash Map: Use a hash map to store each element's index and check for the complement.

// DSA Strategy/Pattern:
// Two Pointers, Hash Map

// Approach 1: Two Pointers
// Sort the array 'nums'.
// Initialize two pointers 'left' and 'right' at the start and end of the array, respectively.
// Iterate until 'left' is less than 'right':
//    Calculate the sum of the elements at 'left' and 'right'.
//    If the sum is less than 'target', move 'left' to the right.
//    If the sum is greater than 'target', move 'right' to the left.
//    If the sum is equal to 'target', return the indices of 'left' and 'right'.
// If no such pair is found, return an empty vector.

// Complexity:
// Time complexity: O(n log n) due to sorting.
// Space complexity: O(1) as no extra space is used apart from the input vector.

// Function to find the indices of two numbers in the array that add up to the target using two pointers
vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    for (int left = 0, right = nums.size() - 1; left < right;)
    {
        int sum = nums[left] + nums[right];
        if (sum < target)
        {
            left++;
        }
        else if (sum > target)
        {
            right--;
        }
        else
        {
            return {left + 1, right + 1};
        }
    }
    return {};
}

// Approach 2: Hash Map
// Use an unordered map 'numMap' to store elements and their indices.
// Iterate through the array 'nums':
//    Calculate the complement (target - nums[i]).
//    If the complement exists in 'numMap' and its index is not equal to the current index 'i':
//       Return the indices of the current element and its complement.
//    Store the current element and its index in 'numMap'.
// If no such pair is found, return an empty vector.

// Complexity:
// Time complexity: O(n) as we iterate through the array once.
// Space complexity: O(n) for the unordered map.

// Function to find the indices of two numbers in the array that add up to the target using hash map
vector<int> twoSumHash(vector<int> &nums, int target)
{
    unordered_map<int, int> numMap; // Map to store elements and their indices

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end() && numMap[complement] != i)
        {
            return {numMap[complement] + 1, i + 1};
        }
        numMap[nums[i]] = i; // Store current element and its index
    }

    return {}; // No solution found
}

int main()
{
    // Test the twoSum function with an example array.
    vector<int> arr = {15, 7, 11, 2};
    vector<int> v = twoSum(arr, 9);

    // Output the indices of the two numbers and their sum.
    cout << "Indices: " << v[0] << ", " << v[1] << endl;
    cout << "Sum: " << arr[v[0] - 1] + arr[v[1] - 1] <<endl;


    v = twoSumHash(arr, 9);
    cout << "Indices: " << v[0] << ", " << v[1] << endl;
    cout << "Sum: " << arr[v[0] - 1] + arr[v[1] - 1];

    return 0;
}
