#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can climb either 1 or k steps. The staircase is represented by an array of integers,
// where each integer represents the height of the step. When you climb from the ith step to the (i+j)th step,
// you incur a cost equal to the absolute difference in height between the two steps.
// Find the minimum cost to reach the top of the staircase.

// Intuition:
// This problem is similar to the minimum cost climbing stairs problem, where you need to find the minimum cost to reach the top.
// We can solve it using dynamic programming by considering each step and calculating the minimum cost to reach that step.
// We have two different approaches: recursive with memoization and bottom-up dynamic programming.

// DSA Strategy:
// We can solve this problem using dynamic programming:
// 1. Recursive with memoization: We recursively traverse the steps, calculating the minimum cost to reach each step.
//    We store the results in a memoization table to avoid redundant calculations.
// 2. Bottom-up dynamic programming: We iterate through the steps from bottom to top, calculating the minimum cost to reach each step.
//    We store the results in a DP table and return the final result.

// Approach 1: Recursive with Memoization
// - Create a recursive function that calculates the minimum cost to reach each step from the bottom to the top.
// - Use memoization to store the results of previously calculated steps to avoid redundant calculations.
// - Return the minimum cost to reach the top step.
// Time Complexity: O(n * k)
// Space Complexity: O(n)

// Comments for each line in method
int jumpMemo(int ind, vector<int> &height, vector<int> &dp, int k)
{
    // Base case: when reaching the first step, return 0 cost.
    if (ind == 0)
        return 0;
    // If the result for the current index is already calculated, return it.
    if (dp[ind] != -1)
        return dp[ind];

    // Initialize the minimum steps to reach the current index.
    int minSteps = INT_MAX;
    // Iterate through the possible number of steps to take (from 1 to k).
    for (int j = 1; j <= k; j++)
    {
        // Check if it's possible to take j steps from the current index.
        if (ind - j >= 0)
        {
            // Calculate the cost of jumping j steps and update the minimum steps.
            int jump = jumpMemo(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            minSteps = min(jump, minSteps);
        }
    }

    // Store the minimum cost for the current index in the DP table.
    return dp[ind] = minSteps;
}

// Approach 2: Bottom-up Dynamic Programming
// - Initialize a DP table to store the minimum cost to reach each step.
// - Iterate through the steps from bottom to top, calculating the minimum cost to reach each step.
// - Return the minimum cost to reach the top step.
// Time Complexity: O(n * k)
// Space Complexity: O(n)

// Comments for each line in method
int jumpTable(int n, vector<int> &height, vector<int> &dp, int k)
{
    // Base case: no cost for reaching the first step.
    dp[0] = 0;
    // Calculate the minimum cost for each step.
    for (int i = 1; i < dp.size(); i++)
    {
        // Initialize the minimum steps to reach the current index.
        int minSteps = INT_MAX;
        // Iterate through the possible number of steps to take (from 1 to k).
        for (int j = 1; j <= k; j++)
        {
            // Check if it's possible to take j steps from the current index.
            if (i - j >= 0)
            {
                // Calculate the cost of jumping j steps and update the minimum steps.
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minSteps = min(jump, minSteps);
            }
        }
        // Store the minimum cost for the current step in the DP table.
        dp[i] = minSteps;
    }

    // Return the minimum cost to reach the top step.
    return dp[n - 1];
}

int main()
{
    // Input height array representing the heights of steps.
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size(); // Number of steps
    int k = 2;             // Maximum number of steps that can be taken at a time
    vector<int> dp(n, -1); // DP table to store the minimum cost to reach each step

    // Calculate the minimum cost using the memoization approach
    cout << "Minimum cost to reach the top (memoization): " << jumpMemo(n - 1, height, dp, k) << endl;

    // Reset DP table for the bottom-up DP approach
    dp = vector<int>(n, -1);

    // Calculate the minimum cost using the bottom-up DP approach
    cout << "Minimum cost to reach the top (table): " << jumpTable(n, height, dp, k) << endl;

    return 0;
}
