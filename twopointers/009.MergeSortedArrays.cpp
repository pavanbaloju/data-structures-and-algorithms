#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// Intuition:
// We can use a hash map to store the elements and their indices while traversing the array. 
// For each element nums[i], we check if target - nums[i] exists in the hash map.

// DSA Strategy/Pattern: 
// Two Pointers, Hash Map

// Approach 1: Two Pointers
// Explanation:
// 1. Sort the input array nums.
// 2. Initialize two pointers, left and right, pointing to the start and end of the array respectively.
// 3. While left < right, calculate the sum of elements at indices left and right.
// 4. If the sum is less than target, increment left. If the sum is greater than target, decrement right.
// 5. If the sum equals target, return the indices (left + 1, right + 1) as the result.

vector<int> twoSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    for (int left = 0, right = nums.size() - 1; left < right;) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        } else {
            return {left + 1, right + 1};
        }
    }
    return {};
}

// Approach 2: Hash Map
// Explanation:
// 1. Initialize an unordered_map numMap to store elements and their indices.
// 2. Iterate through the input array nums.
// 3. For each element nums[i], calculate its complement as target - nums[i].
// 4. If the complement exists in numMap and its index is not i, return the indices (numMap[complement] + 1, i + 1).
// 5. Otherwise, store the element and its index in numMap.
// 6. If no solution is found, return an empty vector.

vector<int> twoSumHash(vector<int> &nums, int target) {
    unordered_map<int, int> numMap; // Map to store elements and their indices
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end() && numMap[complement] != i) {
            return {numMap[complement] + 1, i + 1};
        }
        numMap[nums[i]] = i; // Store current element and its index
    }
    return {}; // No solution found
}

// Main function
int main() {
    // Test case
    vector<int> arr = {15, 7, 11, 2};
    
    // Output the result of Approach 1
    cout << "Approach 1 - Two Pointers:" << endl;
    vector<int> v = twoSum(arr, 9);
    cout << "Indices: " << v[0] << ", " << v[1] << endl;
    cout << "Sum: " << arr[v[0] - 1] + arr[v[1] - 1] << endl;

    // Output the result of Approach 2
    cout << "Approach 2 - Hash Map:" << endl;
    v = twoSumHash(arr, 9);
    cout << "Indices: " << v[0] << ", " << v[1] << endl;
    cout << "Sum: " << arr[v[0] - 1] + arr[v[1] - 1] << endl;

    return 0;
}
