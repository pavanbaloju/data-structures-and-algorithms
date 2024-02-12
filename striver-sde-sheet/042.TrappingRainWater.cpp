#include <iostream>
#include <vector>
using namespace std;

// Problem Statement: Given an array representing heights of blocks, calculate the total trapped rainwater.
// Problem Link: https://www.geeksforgeeks.org/trapping-rain-water/

// Function to calculate the trapped rainwater using brute force approach
// Intuition: For each block, find the maximum heights of blocks to its left and right.
//            Then, the amount of water that can be trapped at this block is determined by the minimum of these maximum heights minus the height of the current block.
//            Add up the trapped water for each block to get the total trapped rainwater.
// Approach:
// 1. Iterate through each block from index 1 to n-2.
// 2. For each block, find the maximum heights of blocks to its left and right using nested loops.
// 3. Calculate the trapped water at this block using the minimum of maximum heights and subtracting the current block's height.
// 4. Add up the trapped water for each block to get the total trapped rainwater.
// Time Complexity: O(n^2), where n is the size of the input array.
//                  Two nested loops are used to find the maximum heights to the left and right of each block.
// Space Complexity: O(1), no extra space is used other than a few variables.
int trapBrute(vector<int> &arr)
{
    int n = arr.size();
    // To store the maximum water that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

// Function to calculate the trapped rainwater using pre-calculation approach
// Intuition: Pre-calculate the maximum heights of blocks to the left and right of each block.
//            Then, for each block, calculate the trapped water using the pre-calculated maximum heights.
// Approach:
// 1. Create two arrays to store the maximum heights to the left and right of each block.
// 2. Iterate through the array from left to right to calculate the maximum heights to the left of each block.
// 3. Iterate through the array from right to left to calculate the maximum heights to the right of each block.
// 4. Iterate through the array once again to calculate the trapped water at each block using the pre-calculated maximum heights.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n), where n is the size of the input array.
int trapWithPrecalculate(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);

    // Calculate the maximum height to the left of each element
    for (int i = 1; i < n; ++i)
        leftMax[i] = max(height[i - 1], leftMax[i - 1]);

    // Calculate the maximum height to the right of each element
    for (int i = n - 2; i >= 0; --i)
        rightMax[i] = max(height[i + 1], rightMax[i + 1]);

    int ans = 0;
    // Calculate the trapped rainwater for each element
    for (int i = 0; i < n; ++i)
    {
        int waterLevel = min(leftMax[i], rightMax[i]);
        if (waterLevel >= height[i])
            ans += waterLevel - height[i];
    }
    return ans;
}

// Function to calculate the trapped rainwater using two-pointer approach
// Intuition: Use two pointers to maintain the maximum heights of blocks to the left and right of the current block.
//            Move the pointers inward, updating the maximum heights and calculating the trapped water as needed.
// Approach:
// 1. Initialize left and right pointers at the beginning and end of the array, respectively.
// 2. Initialize variables to keep track of the maximum heights to the left and right of the current block.
// 3. Move the pointers inward, updating the maximum heights and calculating the trapped water as needed.
// 4. Repeat until the left pointer is less than or equal to the right pointer.
// Time Complexity: O(n), where n is the size of the input array.
//                  The two-pointer approach iterates through the array only once.
// Space Complexity: O(1), no extra space is used other than a few variables.
int trap(vector<int> &height)
{
    if (height.size() <= 2)
        return 0;

    int n = height.size();
    int leftMax = height[0], rightMax = height[n - 1];
    int left = 1, right = n - 2, ans = 0;

    // Iterate through the array using two pointers
    while (left <= right)
    {
        if (leftMax < rightMax)
        {
            // Update the left maximum height
            if (height[left] > leftMax)
                leftMax = height[left];
            else
                ans += leftMax - height[left];
            ++left;
        }
        else
        {
            // Update the right maximum height
            if (height[right] > rightMax)
                rightMax = height[right];
            else
                ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}

// Main function
int main()
{
    // Input vector representing the heights of blocks
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Output the trapped rainwater using different approaches
    cout << trap(heights) << endl;                 // Using two-pointer approach
    cout << trapBrute(heights) << endl;            // Using brute force approach
    cout << trapWithPrecalculate(heights) << endl; // Using pre-calculation approach

    return 0;
}
