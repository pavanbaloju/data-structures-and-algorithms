#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can climb either 1 or 2 steps. The staircase is represented by an array of integers,
// where each integer represents the height of the step. When you climb from the ith step to the (i+1)th or (i+2)th step,
// you incur a cost equal to the absolute difference in height between the two steps.
// Find the minimum cost to reach the top of the staircase.

// Intuition:
// This problem is similar to the minimum cost climbing stairs problem, where you need to find the minimum cost to reach the top.
// We can solve it using dynamic programming by considering each step and calculating the minimum cost to reach that step.
// We have three different approaches: recursive with memoization, bottom-up dynamic programming, and optimized dynamic programming.

// DSA Strategy:
// We can solve this problem using dynamic programming:
// 1. Recursive with memoization: We recursively traverse the steps, calculating the minimum cost to reach each step.
//    We store the results in a memoization table to avoid redundant calculations.
// 2. Bottom-up dynamic programming: We iterate through the steps from bottom to top, calculating the minimum cost to reach each step.
//    We store the results in a DP table and return the final result.
// 3. Optimized dynamic programming: We use two variables to store the minimum costs for the previous and previous to previous steps.
//    We iterate through the steps and update these variables based on the minimum cost to reach the current step.
//    We return the minimum cost to reach the top.

// Approach 1: Recursive with Memoization
// - Create a recursive function that calculates the minimum cost to reach each step from the bottom to the top.
// - Use memoization to store the results of previously calculated steps to avoid redundant calculations.
// - Return the minimum cost to reach the top step.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Comments for each line in method
int jumpMemo(int ind, vector<int> &height, vector<int> &dp)
{
    // Base case: when reaching the first step, return 0 cost.
    if (ind == 0)
        return 0;
    // If the result for the current index is already calculated, return it.
    if (dp[ind] != -1)
        return dp[ind];

    // Calculate the cost of jumping one step and two steps, and choose the minimum.
    int jumpTwo = INT_MAX;
    int jumpOne = jumpMemo(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = jumpMemo(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    // Store the minimum cost for the current index in the DP table.
    return dp[ind] = min(jumpOne, jumpTwo);
}

// Approach 2: Bottom-up Dynamic Programming
// - Initialize a DP table to store the minimum cost to reach each step.
// - Iterate through the steps from bottom to top, calculating the minimum cost to reach each step.
// - Return the minimum cost to reach the top step.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Comments for each line in method
int jumpTable(int n, vector<int> &height, vector<int> &dp)
{
    // Base case: no cost for reaching the first step.
    dp[0] = 0;
    // Calculate the minimum cost for each step.
    for (int i = 1; i < dp.size(); i++)
    {
        // Calculate the cost of jumping one step.
        int one = dp[i - 1] + abs(height[i] - height[i - 1]);
        // Calculate the cost of jumping two steps (if possible).
        int two = i > 1 ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
        // Store the minimum cost for the current step in the DP table.
        dp[i] = min(one, two);
    }

    // Return the minimum cost to reach the top step.
    return dp[n - 1];
}

// Approach 3: Optimized Dynamic Programming
// - Initialize two variables to store the minimum costs for the previous and previous to previous steps.
// - Iterate through the steps from bottom to top, updating these variables based on the minimum cost to reach the current step.
// - Return the minimum cost to reach the top step.
// Time Complexity: O(n)
// Space Complexity: O(1)

// Comments for each line in method
int jumpOpt(int n, vector<int> &height)
{
    // Initialize variables to store the minimum costs for the previous and previous to previous steps.
    int prev = 0;
    int prev2 = 0;
    // Iterate through the steps from bottom to top.
    for (int i = 1; i < n; i++)
    {
        // Calculate the cost of jumping one step.
        int one = prev + abs(height[i] - height[i - 1]);
        // Calculate the cost of jumping two steps (if possible).
        int two = i > 1 ? prev2 + abs(height[i] - height[i - 2]) : INT_MAX;

        // Update the previous and previous to previous costs for the next iteration.
        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    // Return the minimum cost to reach the top step.
    return prev;
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);

    // Printing the output of all approaches
    cout << "Minimum cost to reach the top (memoization): " << jumpMemo(n - 1, height, dp) << endl;
    dp = vector<int>(n, -1);
    cout << "Minimum cost to reach the top (table): " << jumpTable(n, height, dp) << endl;
    cout << "Minimum cost to reach the top (optimized): " << jumpOpt(n, height) << endl;

    return 0;
}
