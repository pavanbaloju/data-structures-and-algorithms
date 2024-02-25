#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers representing the heights of steps in a staircase, 
// find the maximum sum that can be obtained by summing up the values of the steps 
// while traversing the staircase. You can only move upwards and either climb 1 or 2 steps at a time.

// Intuition:
// This problem can be solved using dynamic programming.
// We have three different approaches: recursive with memoization, bottom-up dynamic programming, and optimized dynamic programming.

// DSA Strategy:
// We can solve this problem using dynamic programming:
// 1. Recursive with memoization: We recursively traverse the steps, calculating the maximum sum at each step.
//    We store the results in a memoization table to avoid redundant calculations.
// 2. Bottom-up dynamic programming: We iterate through the steps from bottom to top, 
//    calculating the maximum sum that can be obtained by considering each step.
//    We store the results in a DP table and return the final result.
// 3. Optimized dynamic programming: We use two variables to store the maximum sums for the previous and 
//    previous-to-previous steps. We iterate through the steps and update these variables based on the 
//    maximum sum that can be obtained at the current step. We return the maximum sum.

// Approach 1: Recursive with Memoization
// - Create a recursive function that calculates the maximum sum at each step from the bottom to the top.
// - Use memoization to store the results of previously calculated steps to avoid redundant calculations.
// - Return the maximum sum at the top step.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Recursive function to calculate the maximum sum at each step
int solveMemo(int ind, vector<int> &nums, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    int pick = nums[ind] + solveMemo(ind - 2, nums, dp); // Pick the current step and the step two steps below
    int nonPick = 0 + solveMemo(ind - 1, nums, dp);      // Do not pick the current step and move to the next step
    return dp[ind] = max(pick, nonPick);                 // Store the maximum of the two choices
}

// Function to find the maximum sum using memoization
int maxSumMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1); // Initialize memoization table with -1
    return solveMemo(n - 1, nums, dp); // Start from the top step and calculate the maximum sum
}

// Approach 2: Bottom-up Dynamic Programming
// - Initialize a DP table to store the maximum sum that can be obtained at each step.
// - Iterate through the steps from bottom to top, calculating the maximum sum considering each step.
// - Return the maximum sum at the top step.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Function to solve the problem using bottom-up dynamic programming
int solveTable(vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0]; // Base case: Maximum sum at the first step is the value of the first step

    for (int i = 1; i < n; i++)
    {
        // Calculate the maximum sum considering the current step
        int pick = nums[i] + (i > 1 ? dp[i - 2] : 0); // Pick the current step and add the maximum sum obtained two steps below
        int nonPick = dp[i - 1];                      // Do not pick the current step and use the maximum sum obtained at the previous step
        dp[i] = max(pick, nonPick);                   // Store the maximum sum for the current step
    }

    return dp[n - 1]; // Return the maximum sum at the top step
}

// Function to find the maximum sum using bottom-up dynamic programming
int maxSumTable(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1); // Initialize DP table with -1
    return solveTable(nums, dp); // Solve the problem using bottom-up dynamic programming
}

// Approach 3: Optimized Dynamic Programming
// - Initialize two variables to store the maximum sums for the previous and previous-to-previous steps.
// - Iterate through the steps from bottom to top, updating these variables based on the maximum sum that can be obtained at the current step.
// - Return the maximum sum at the top step.
// Time Complexity: O(n)
// Space Complexity: O(1)

// Function to solve the problem using optimized dynamic programming
int maxSumOpt(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0; // Initialize variables for the first and second steps

    for (int i = 1; i < n; i++)
    {
        // Calculate the maximum sum considering the current step
        int pick = nums[i] + prev2; // Pick the current step and add the maximum sum obtained two steps below
        int nonPick = prev;          // Do not pick the current step and use the maximum sum obtained at the previous step

        // Update the variables for the next iteration
        int curr = max(pick, nonPick); // Calculate the maximum sum at the current step
        prev2 = prev;                   // Update the maximum sum for the second previous step
        prev = curr;                    // Update the maximum sum for the previous step
    }

    return prev; // Return the maximum sum at the top step
}

// Main function
int main()
{
    vector<int> nums{2, 1, 4, 9}; // Input array representing the heights of steps
    cout << "Maximum sum using memoization: " << maxSumMemo(nums) << endl;
    cout << "Maximum sum using bottom-up dynamic programming: " << maxSumTable(nums) << endl;
    cout << "Maximum sum using optimized dynamic programming: " << maxSumOpt(nums) << endl;
    return 0;
}
