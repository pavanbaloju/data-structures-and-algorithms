#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    // Problem Statement:
    // Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    // Intuition:
    // This problem can be solved efficiently using the divide and conquer approach.
    // We can divide the array into two halves and find the maximum subarray sum in each half recursively.
    // Then, we find the maximum subarray sum that crosses the middle and return the maximum of the three sums.

    // DSA Strategy:
    // Divide and Conquer, Maximum Subarray Sum

    // Approach:
    // 1. Implement a helper function 'maxSubArrayHelper' to find the maximum subarray sum using divide and conquer.
    //    - Base case: if the subarray has only one element, return that element.
    //    - Find the middle index to divide the array into two halves.
    //    - Recursively find the maximum subarray sum in the left half.
    //    - Recursively find the maximum subarray sum in the right half.
    //    - Find the maximum subarray sum across the middle using 'maxCrossingSubarray'.
    //    - Return the maximum of the three sums.
    // 2. Implement a helper function 'maxCrossingSubarray' to find the maximum subarray sum across the middle.
    //    - Initialize sum to find the maximum sum of the left half.
    //    - Traverse from mid to left and find the maximum sum.
    //    - Initialize sum to find the maximum sum of the right half.
    //    - Traverse from mid + 1 to right and find the maximum sum.
    //    - Return the sum of maximum subarrays from both halves.
    // 3. In the main function, call the 'maxSubArrayHelper' function to find the maximum subarray sum.
    // 4. Print the maximum subarray sum.

    // Time Complexity: O(n log n), where n is the size of the input array.
    // Space Complexity: O(log n) due to the recursion stack.

    int maxSubArray(vector<int> &nums)
    {
        // Call the helper function to find the maximum subarray sum
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

private:
    // Helper function to find the maximum subarray sum using divide and conquer
    int maxSubArrayHelper(const vector<int> &nums, int left, int right)
    {
        // Base case: if the subarray has only one element, return that element
        if (left == right)
        {
            return nums[left];
        }

        // Find the middle index to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively find the maximum subarray sum in the left half
        int leftMax = maxSubArrayHelper(nums, left, mid);

        // Recursively find the maximum subarray sum in the right half
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);

        // Find the maximum subarray sum across the middle
        int crossMax = maxCrossingSubarray(nums, left, mid, right);

        // Return the maximum of the three sums
        return max({leftMax, rightMax, crossMax});
    }

    // Helper function to find the maximum subarray sum across the middle
    int maxCrossingSubarray(const vector<int> &nums, int left, int mid, int right)
    {
        // Initialize sum to find the maximum sum of the left half
        int leftSum = numeric_limits<int>::min();
        int sum = 0;
        // Traverse from mid to left and find the maximum sum
        for (int i = mid; i >= left; --i)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        // Initialize sum to find the maximum sum of the right half
        int rightSum = numeric_limits<int>::min();
        sum = 0;
        // Traverse from mid + 1 to right and find the maximum sum
        for (int i = mid + 1; i <= right; ++i)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        // Return the sum of maximum subarrays from both halves
        return leftSum + rightSum;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << sol.maxSubArray(nums) << endl;

    return 0;
}
