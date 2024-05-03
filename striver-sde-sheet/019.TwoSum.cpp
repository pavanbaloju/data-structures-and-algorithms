#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given an array of integers nums and an integer target, return the indices of the two numbers
// such that they add up to target. You may assume that each input would have exactly one solution,
// and you may not use the same element twice. You can return the answer in any order.

// Function to find the indices of two numbers that add up to the target.
// Intuition:
// Sort the array to use two pointers technique where one pointer starts from the beginning
// and the other poinxter starts from the end. Move the pointers inward based on the sum of
// the elements at the pointers compared to the target. If the sum is less than the target,
// move the left pointer to the right to increase the sum. If the sum is greater than the target,
// move the right pointer to the left to decrease the sum. If the sum equals the target, return
// the indices of the two numbers.
// Time complexity: O(nlogn) due to sorting, where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
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

// Function to find the indices of two numbers that add up to the target without sorting.
// Intuition:
// Use a hash table to store the elements of the array and their indices. As we iterate through
// the array, for each element nums[i], calculate the complement (target - nums[i]). If the complement
// exists in the hash table and its index is not the same as i, return the indices of nums[i] and its
// complement. Otherwise, continue iterating.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(n) due to the hash table.
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
