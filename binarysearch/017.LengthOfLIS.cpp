#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given an array of integers, find the length of the longest increasing subsequence.

// 2. Add Intuition
// Intuition:
// The problem can be solved by maintaining an array, 'tail', which stores the smallest tail for all increasing subsequences.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Dynamic Programming with Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// Step 1: Initialize an empty array 'tail'.
// Step 2: Iterate through the input array 'nums'.
// Step 3: Use binary search to find the insertion point of the current number in 'tail'.
// Step 4: If the insertion point is at the end of 'tail', append the current number.
// Step 5: Otherwise, replace the element in 'tail' at the insertion point with the current number.
// Step 6: The size of 'tail' is the length of the longest increasing subsequence.

// 5. Add time and space complexity
// Time Complexity: O(n log n), where n is the number of elements in the array.
// Space Complexity: O(n), where n is the number of elements in the array.

int lengthOfLIS(vector<int>& nums) {
    vector<int> tail; // This will store the smallest tail for all increasing subsequences

    for (int num : nums) {
        // Use binary search to find the insertion point of the current number
        auto it = lower_bound(tail.begin(), tail.end(), num);

        if (it == tail.end()) {
            // If num is greater than all elements in tail, append it
            tail.push_back(num);
        } else {
            // Otherwise, replace the first element in tail that is >= num
            *it = num;
        }
    }

    return tail.size(); // The size of tail is the length of the longest increasing subsequence
}

// 6. Adds comment on every line in method
// Commenting is done inline within the function 'lengthOfLIS'.

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // 8. Format the output better in main method by printing the output
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
