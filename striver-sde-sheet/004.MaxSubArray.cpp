#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers, find the contiguous subarray with the largest sum.

// Method 1: Brute Force Method
// Intuition:
// - Iterate through all possible subarrays and find their sums.
// - Keep track of the maximum sum encountered.
// Approach:
// - Use three nested loops to iterate through all possible subarrays.
// - Update the maximum sum whenever a larger sum is found.
// Time Complexity: O(n^3), where n is the size of the input array.
// Space Complexity: O(1).
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

// Method 2: Optimized Brute Force Method
// Intuition:
// - Instead of recomputing the sum for each subarray, maintain a running sum.
// - Iterate through all possible subarrays, updating the current sum.
// Approach:
// - Use two nested loops to iterate through all possible subarrays.
// - Update the current sum by adding the next element.
// - Update the maximum sum whenever a larger sum is found.
// Time Complexity: O(n^2), where n is the size of the input array.
// Space Complexity: O(1).
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

// Method 3: Kadane's Algorithm (Dynamic Programming)
// Intuition:
// - Maintain a running sum while iterating through the array.
// - If the current sum becomes negative, reset it to zero.
// - Keep track of the maximum sum encountered.
// Approach:
// - Iterate through the array, updating the current sum.
// - If the current sum becomes negative, reset it to zero.
// - Update the maximum sum whenever a larger sum is found.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1).
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

    // if (maxSum < 0) maxSum = 0;

    return maxSum;
}

// Method 4: Divide and Conquer Approach
// Intuition:
// - Divide the array into halves and find the maximum subarray sum recursively.
// - Consider subarrays that cross the midpoint.
// - Return the maximum sum of the left, right, and cross subarrays.
// Approach:
// - Implement a helper function that handles the recursive division.
// - Find the maximum subarray sum in the left and right halves.
// - Find the maximum subarray sum that crosses the midpoint.
// - Return the maximum of the three values.
// Time Complexity: O(n log n), where n is the size of the input array.
// Space Complexity: O(log n), for the recursion stack.
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

// Method 4: Divide and Conquer Approach (Continued)
// Intuition:
// - Use the helper function to find the maximum subarray sum.
// Approach:
// - Call the helper function with the entire array and return the result.
// Time Complexity: O(n log n), where n is the size of the input array.
// Space Complexity: O(log n), for the recursion stack.
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
