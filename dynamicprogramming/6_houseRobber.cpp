#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers representing the values of houses in a row, 
// find the maximum amount of money you can rob tonight without alerting the police. 
// You cannot rob adjacent houses.

// Intuition:
// This problem is a variant of the house robbery problem where we cannot rob adjacent houses.
// We can solve it using dynamic programming by considering each house and calculating the maximum amount of money we can rob without alerting the police.
// We have one approach: optimized dynamic programming.

// DSA Strategy:
// We can solve this problem using optimized dynamic programming:
// - Initialize two variables to store the maximum amounts of money for the previous and previous-to-previous houses.
// - Iterate through the houses from left to right, updating these variables based on the maximum amount of money that can be robbed without alerting the police.
// - Return the maximum amount of money that can be robbed.

// Approach: Optimized Dynamic Programming
// - Initialize two variables to store the maximum amounts of money for the previous and previous-to-previous houses.
// - Iterate through the houses from left to right.
// - Calculate the maximum amount of money that can be robbed from the current house:
//    - If the current house is picked, add its value to the maximum amount of money that can be robbed from the previous-to-previous house.
//    - If the current house is not picked, use the maximum amount of money that can be robbed from the previous house.
// - Update the variables for the next iteration.
// - Return the maximum amount of money that can be robbed.

// Time Complexity: O(n)
// Space Complexity: O(1)

// Function to solve the problem using optimized dynamic programming
int rob(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0; // Initialize variables for the first and second houses

    for (int i = 1; i < n; i++)
    {
        // Calculate the maximum amount of money that can be robbed from the current house
        int pick = nums[i] + prev2; // Pick the current house and add its value to the maximum amount of money robbed from the previous-to-previous house
        int nonPick = prev;          // Do not pick the current house and use the maximum amount of money robbed from the previous house

        // Update the variables for the next iteration
        int curr = max(pick, nonPick); // Calculate the maximum amount of money that can be robbed from the current house
        prev2 = prev;                   // Update the maximum amount of money robbed from the previous-to-previous house
        prev = curr;                    // Update the maximum amount of money robbed from the previous house
    }

    return prev; // Return the maximum amount of money that can be robbed
}

// Main function
int main()
{
    vector<int> nums{1, 2, 3, 1}; // Input array representing the values of houses
    cout << "Maximum amount of money that can be robbed: " << rob(nums) << endl;
    return 0;
}
