#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// You are training for a ninja competition, and you have a list of tasks to complete each day.
// Each day, you can choose one of the three tasks to perform, but you cannot choose the same task two days in a row.
// The tasks are represented by a 2D array 'points', where 'points[i][j]' represents the points you'll earn for completing task 'j' on day 'i'.
// Find the maximum total points you can earn by completing tasks each day without choosing the same task two days in a row.

// Intuition:
// This problem is similar to the house robbery problem, where you need to maximize the points earned without consecutive tasks.
// We can solve it using dynamic programming by considering each day and each task, and calculating the maximum points earned.
// We have four different approaches: recursion, recursion with memoization, bottom-up dynamic programming (tabulation), and optimized dynamic programming.

// DSA Strategy:
// We can solve this problem using dynamic programming:
// 1. Recursion: We recursively traverse each day and choose the task that gives maximum points without choosing the same task two days in a row.
// 2. Recursion with memoization: We use memoization to store the results of previously calculated states to avoid redundant calculations.
// 3. Bottom-up dynamic programming (Tabulation): We iterate through each day and each task, calculating the maximum points earned.
//    We store the results in a DP table and return the final result.
// 4. Optimized dynamic programming: We optimize the space complexity by using only two arrays to store the maximum points earned on the previous day and the current day.
//    We update these arrays iteratively as we traverse through the days.

// Approach 1: Recursion
// - Create a recursive function 'solve' that calculates the maximum points earned each day without choosing the same task two days in a row.
// - Return the maximum points earned after completing all days.
// Time Complexity: O(3^n)
// Space Complexity: O(n) (recursion stack)

// Comments for each line in method

// Recursion function to solve the problem
int solve(int day, int lastIdx, vector<vector<int>> points)
{
    int maxp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastIdx)
        {
            // Calculate today's points
            int todayPoints = points[day][i];
            // If not the first day, add points from the previous day
            if (day > 0)
                todayPoints += solve(day - 1, i, points);
            // Update the maximum points
            maxp = max(maxp, todayPoints);
        }
    }
    return maxp;
}

// Function to find the maximum total points earned using recursion
int ninjaTraining(vector<vector<int>> points)
{
    return solve(points.size() - 1, 3, points);
}

// Approach 2: Recursion with Memoization
// - Create a recursive function 'solveMemo' with memoization that calculates the maximum points earned each day.
// - Use memoization to store the results of previously calculated states to avoid redundant calculations.
// - Return the maximum points earned after completing all days.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Comments for each line in method

// Recursion function with memoization
int solveMemo(int day, int lastIdx, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (dp[day][lastIdx] != -1)
        return dp[day][lastIdx];

    int maxp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastIdx)
        {
            // Calculate today's points
            int todayPoints = points[day][i];
            // If not the first day, add points from the previous day
            if (day > 0)
                todayPoints += solveMemo(day - 1, i, points, dp);
            // Update the maximum points
            maxp = max(maxp, todayPoints);
        }
    }
    return dp[day][lastIdx] = maxp;
}

// Function to find the maximum total points earned using recursion with memoization
int ninjaTrainingMemo(vector<vector<int>> points)
{
    vector<vector<int>> dp = vector<vector<int>>(points.size(), vector<int>(4, -1));
    return solveMemo(points.size() - 1, 3, points, dp);
}

// Approach 3: Bottom-up Dynamic Programming (Tabulation)
// - Create a DP table 'dp' to store the maximum points earned for each day and each task.
// - Iterate through each day and each task, calculating the maximum points earned.
// - Return the maximum points earned after completing all days.
// Time Complexity: O(n)
// Space Complexity: O(n)

// Comments for each line in method

// Function for bottom-up dynamic programming (tabulation)
int solveTable(vector<vector<int>> points, vector<vector<int>> &dp)
{
    int n = points.size();
    for (int day = 0; day < n; day++)
    {
        for (int lastIdx = 0; lastIdx < 4; lastIdx++)
        {
            int maxp = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastIdx)
                {
                    // Calculate today's points
                    int todayPoints = points[day][task];
                    // If not the first day, add points from the previous day
                    if (day > 0)
                        todayPoints += dp[day - 1][task];
                    // Update the maximum points
                    maxp = max(maxp, todayPoints);
                }
            }
            // Store the maximum points in the DP table
            dp[day][lastIdx] = maxp;
        }
    }

    return dp[n - 1][3];
}

// Function to find the maximum total points earned using bottom-up dynamic programming (tabulation)
int ninjaTrainingTable(vector<vector<int>> points)
{
    vector<vector<int>> dp = vector<vector<int>>(points.size(), vector<int>(4, -1));
    return solveTable(points, dp);
}

// Approach 4: Optimized Dynamic Programming
// - Use two arrays 'prevDay' and 'curr' to store the maximum points earned on the previous day and the current day, respectively.
// - Iterate through each day, updating the 'curr' array based on the maximum points earned without choosing the same task two days in a row.
// - Return the maximum points earned after completing all days.
// Time Complexity: O(n)
// Space Complexity: O(1)

// Comments for each line in method

// Function for optimized dynamic programming
int ninjaTrainingOpt(vector<vector<int>> points)
{
    int n = points.size();
    vector<int> prevDay = vector<int>(4, 0);
    for (int day = 0; day < n; day++)
    {
        vector<int> curr = vector<int>(4, -1);
        for (int lastIdx = 0; lastIdx < 4; lastIdx++)
        {
            int maxp = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastIdx)
                {
                    // Calculate today's points
                    int todayPoints = points[day][task] + prevDay[task];
                    // Update the maximum points
                    maxp = max(maxp, todayPoints);
                }
            }
            // Store the maximum points for the current day
            curr[lastIdx] = maxp;
        }
        // Update the maximum points earned on the previous day
        prevDay = curr;
    }

    return prevDay[3];
}

// Main function
int main()
{
    // Input: points earned for each task on each day
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    // Printing the output of all approaches
    cout << "Maximum points earned (recursion): " << ninjaTraining(points) << endl;
    cout << "Maximum points earned (recursion with memoization): " << ninjaTrainingMemo(points) << endl;
    cout << "Maximum points earned (bottom-up dynamic programming): " << ninjaTrainingTable(points) << endl;
    cout << "Maximum points earned (optimized dynamic programming): " << ninjaTrainingOpt(points) << endl;

    return 0;
}
