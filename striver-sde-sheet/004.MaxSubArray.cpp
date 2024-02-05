#include <iostream>
#include <vector>
using namespace std;

// Method 1: Brute Force Method
// Time Complexity: O(n^3)
int maxSubarrayBruteForce(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to minimum possible value
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
// Time Complexity: O(n^2)
int maxSubarrayOptimizedBruteForce(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to minimum possible value

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
// Time Complexity: O(n)
int maxSubarrayKadane(vector<int> nums)
{
    int n = nums.size();
    int maxSum = INT_MIN; // Initialize maximum subarray sum to minimum possible value
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

// Method 4: Divide and Conquer Approach
// Time Complexity: O(n log n)
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
