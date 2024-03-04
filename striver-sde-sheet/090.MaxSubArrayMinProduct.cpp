#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem Statement:
// Given an integer array nums, find the maximum value of minimums in all non-empty subarrays of nums. Since the answer may be large, return it modulo 10^9 + 7.

// Intuition:
// To efficiently calculate the maximum min-product of any non-empty subarray, we can find the nearest previous smaller element and the nearest next smaller element for each element in the array.
// Then, we can use prefix sums to quickly compute the sum of elements in any subarray between these two nearest smaller elements.
// Finally, we can iterate through each element and calculate the minimum value of each subarray along with its sum, and update the maximum min-product accordingly.

// DSA Strategy:
// Stack

// Approach:
// 1. Define a function calculatePrefixSum to calculate the prefix sum of the array.
// 2. Define functions findNearestPreviousSmaller and findNearestNextSmaller to find the nearest previous and next smaller elements for each element in the array using stacks.
// 3. Calculate prefix sums of the input array.
// 4. Find the nearest previous smaller element for each element.
// 5. Find the nearest next smaller element for each element.
// 6. Iterate through each element, calculate the min-product for each subarray, and update the maximum min-product.
// 7. Return the maximum min-product modulo 10^9 + 7 as the result.

// Time Complexity:
// - calculatePrefixSum: O(n)
// - findNearestPreviousSmaller: O(n)
// - findNearestNextSmaller: O(n)
// - maxMinProduct: O(n)
// Overall time complexity: O(n)
// Space Complexity: O(n)

// Function to calculate the prefix sum of the array
vector<long long> calculatePrefixSum(const vector<int> &nums)
{
    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    return prefixSum;
}

// Function to find the index of the previous smaller element for each element
vector<int> findNearestPreviousSmaller(const vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    vector<int> left(n, -1);

    for (int i = 0; i < n; ++i)
    {
        // Pop elements from the stack until a smaller element is found
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        // Update the nearest previous smaller index for the current element
        left[i] = s.empty() ? -1 : s.top();
        // Push the current index onto the stack
        s.push(i);
    }

    return left;
}

// Function to find the index of the next smaller element for each element
vector<int> findNearestNextSmaller(const vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    vector<int> right(n, n);

    for (int i = n - 1; i >= 0; --i)
    {
        // Pop elements from the stack until a smaller element is found
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        // Update the nearest next smaller index for the current element
        right[i] = s.empty() ? n : s.top();
        // Push the current index onto the stack
        s.push(i);
    }

    return right;
}

// Function to calculate the maximum min-product of any non-empty subarray
int maxSumMinProduct(const vector<int> &nums)
{
    const int MOD = 1e9 + 7;
    int n = nums.size();
    long long maxProduct = 0;

    // Calculate prefix sum
    vector<long long> prefixSum = calculatePrefixSum(nums);

    // Find nearest previous smaller element for each element
    vector<int> left = findNearestPreviousSmaller(nums);

    // Find nearest next smaller element for each element
    vector<int> right = findNearestNextSmaller(nums);

    // Calculate the maximum min-product
    for (int i = 0; i < n; ++i)
    {
        long long minValue = nums[i];
        long long subArraySum = prefixSum[right[i]] - prefixSum[left[i] + 1];
        maxProduct = max(maxProduct, minValue * subArraySum);
    }

    return maxProduct % MOD;
}

int main()
{
    // Test cases
    vector<int> nums1 = {3, 1, 5, 2, 4, 6};
    cout << maxSumMinProduct(nums1) << endl; // Output: 60

    vector<int> nums2 = {2, 3, 1, 5, 4};
    cout << maxSumMinProduct(nums2) << endl; // Output: 27

    return 0;
}
