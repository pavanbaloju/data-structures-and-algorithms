#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers representing the values of houses in a circle, 
// find the maximum amount of money you can rob tonight without alerting the police. 
// You cannot rob adjacent houses, and the first and last houses are considered adjacent.

// Intuition:
// This problem is an extension of the house robbery problem where houses form a circle.
// We can solve it by considering two cases: robbing the first house or not robbing the first house.
// For each case, we apply the house robbery algorithm separately and choose the maximum result.
// We use the house robbery algorithm implemented in the previous example.

// DSA Strategy:
// We can solve this problem by considering two cases:
// 1. Robbing the first house: Remove the last house and apply the house robbery algorithm.
// 2. Not robbing the first house: Remove the first house and apply the house robbery algorithm.
// Return the maximum result among the two cases.

// Approach:
// - Define a helper function 'robHelper' that implements the house robbery algorithm.
// - Create two separate arrays 'nums1' and 'nums2' representing two cases: robbing the first house and not robbing the first house.
// - Apply the house robbery algorithm on both arrays using the 'robHelper' function.
// - Return the maximum result among the two cases.

// Time Complexity: O(n)
// Space Complexity: O(n)

// Function to implement the house robbery algorithm
int robHelper(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i] + prev2;
        int nonPick = prev;

        int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

// Function to find the maximum amount of money that can be robbed without alerting the police
int rob(vector<int> &nums)
{
    int n = nums.size();
    
    // If there is only one house, return its value
    if (n == 1)
        return nums[0];

    // Create two separate arrays representing two cases: robbing the first house and not robbing the first house
    vector<int> nums1;
    vector<int> nums2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            nums1.push_back(nums[i]);
        if (i != n - 1)
            nums2.push_back(nums[i]);
    }

    // Return the maximum result among the two cases
    return max(robHelper(nums1), robHelper(nums2));
}

// Main function
int main()
{
    vector<int> nums{2, 3, 2}; // Input array representing the values of houses in a circle
    cout << "Maximum amount of money that can be robbed without alerting the police: " << rob(nums) << endl;
    return 0;
}
