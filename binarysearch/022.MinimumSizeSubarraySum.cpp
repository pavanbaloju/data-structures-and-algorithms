#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// 2. Add Intuition
// Intuition:
// We can use the sliding window technique to find the minimal length of a contiguous subarray with a sum greater than or equal to the target.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Sliding Window

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// Step 1: Initialize minLength to the maximum possible integer value.
// Step 2: Initialize left and right pointers to 0.
// Step 3: Initialize sum to 0.
// Step 4: Iterate over the array using the right pointer until it reaches the end.
// Step 5: Add the current element to the sum.
// Step 6: While the sum is greater than or equal to the target, update minLength with the minimum of minLength and the current window size, subtract the leftmost element from the sum, and move the left pointer to the right.
// Step 7: Move the right pointer to the right.
// Step 8: Repeat steps 4-7 until the end of the array is reached.
// Step 9: If minLength is still the maximum possible integer value, return 0; otherwise, return minLength.

// 5. Add time and space complexity
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = numeric_limits<int>::max(); // Initialize minimum length
        
        int left = 0, right = 0; // Initialize left and right pointers
        int sum = 0; // Initialize sum of elements
        
        while (right < n) {
            sum += nums[right]; // Add current element to the sum
            
            while (sum >= target) { // Shrink the window as much as possible
                minLength = min(minLength, right - left + 1); // Update minimum length
                sum -= nums[left++]; // Remove leftmost element from the sum
            }
            
            ++right; // Move right pointer to the right
        }
        
        return (minLength == numeric_limits<int>::max()) ? 0 : minLength;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int minLength = sol.minSubArrayLen(target, nums);

    cout << "Minimum size subarray sum: " << minLength << endl;

    return 0;
}
