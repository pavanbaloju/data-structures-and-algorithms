#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Intuition:
// This problem can be solved using various techniques such as brute force, Kadane's algorithm, and divide and conquer.
// Brute force involves trying all possible subarrays, while Kadane's algorithm provides an efficient linear solution.
// Divide and conquer offers a more optimized solution by recursively dividing the array into halves.

// DSA Strategy/Pattern:
// Brute Force, Kadane's Algorithm, Divide and Conquer

// Approach:
// Brute Force:
// Explanation:
// 1. Initialize a variable `maxSum` to the minimum possible value.
// 2. Use nested loops to iterate through all possible subarrays.
// 3. Calculate the sum of each subarray and update `maxSum` if the current sum is greater.
// 4. Return `maxSum`.
// Time Complexity: O(n^3) - Three nested loops for iterating through all subarrays.
// Space Complexity: O(1) - Constant space is used.

int maxSubarrayBruteForce(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to the minimum possible value
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // Calculate sum of subarray nums[start...end]
            int currSum = 0;
            for (int i = start; i <= end; i++)
                currSum += nums[i];

            // Update maxSum if currSum is greater
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// Optimized Brute Force:
// Explanation:
// 1. Initialize a variable `maxSum` to the minimum possible value.
// 2. Use two loops to iterate through all subarrays.
// 3. Calculate the sum of each subarray and update `maxSum` if the current sum is greater.
// 4. Return `maxSum`.
// Time Complexity: O(n^2) - Two nested loops for iterating through all subarrays.
// Space Complexity: O(1) - Constant space is used.

int maxSubarrayOptimizedBruteForce(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to the minimum possible value

    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            // Update currSum by adding nums[end]
            currSum += nums[end];

            // Update maxSum if currSum is greater
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// Kadane's Algorithm:
// Explanation:
// 1. Initialize variables `maxSum` and `currSum` to the minimum possible value.
// 2. Iterate through the array and update `currSum` by adding the current element.
// 3. Update `maxSum` if `currSum` becomes greater than `maxSum`.
// 4. Return `maxSum`.
// Time Complexity: O(n) - Single pass through the input array.
// Space Complexity: O(1) - Constant space is used.

int maxSubarrayKadane(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to the minimum possible value
    int currSum = 0;      // Initialize current subarray sum

    for (int i = 0; i < n; i++)
    {
        // Update currSum by adding nums[i]
        currSum = max(nums[i], currSum + nums[i]);

        // Update maxSum if currSum is greater
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// Divide and Conquer:
// Explanation:
// 1. Recursively divide the array into halves.
// 2. Find the maximum subarray sum in the left half, right half, and a subarray crossing the midpoint.
// 3. Return the maximum of these three values.
// Time Complexity: O(n log n) - Recurrence relation T(n) = 2T(n/2) + O(n).
// Space Complexity: O(log n) - Stack space for recursive calls.

int maxSubarrayDivideAndConquerHelper(vector<int> &nums, int low, int high)
{
    if (low == high)
        return nums[low];

    int mid = (low + high) / 2;
    int leftMax = INT_MIN, rightMax = INT_MIN;

    // Find maximum subarray sum in left and right halves recursively
    for (int i = mid, sum = 0; i >= low; --i)
        leftMax = max(leftMax, sum += nums[i]);

    for (int i = mid + 1, sum = 0; i <= high; ++i)
        rightMax = max(rightMax, sum += nums[i]);

    // Find maximum subarray sum that crosses mid
    int includesMid = leftMax + rightMax;

    // Return maximum of left subarray, right subarray, and subarray crossing mid
    return max(max(maxSubarrayDivideAndConquerHelper(nums, low, mid),
                   maxSubarrayDivideAndConquerHelper(nums, mid + 1, high)),
               includesMid);
}


int maxSubarrayDivideAndConquer(vector<int> &nums)
{
    return maxSubarrayDivideAndConquerHelper(nums, 0, nums.size() - 1);
}

// Main function
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Method 1: Brute Force
    cout << "Maximum Subarray Sum (Brute Force): " << maxSubarrayBruteForce(nums) << endl;

    // Method 2: Optimized Brute Force
    cout << "Maximum Subarray Sum (Optimized Brute Force): " << maxSubarrayOptimizedBruteForce(nums) << endl;

    // Method 3: Kadane's Algorithm
    cout << "Maximum Subarray Sum (Kadane's Algorithm): " << maxSubarrayKadane(nums) << endl;

    // Method 4: Divide and Conquer
    cout << "Maximum Subarray Sum (Divide and Conquer): " << maxSubarrayDivideAndConquer(nums) << endl;

    return 0;
}
