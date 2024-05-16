#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a set of integers, find all possible sums that can be formed by subsets of the set.

// Intuition:
// Use recursion to generate all possible subsets and calculate their sums.

// DSA Strategy:
// Recursion, Backtracking

// Approach:
// 1. Implement a recursive function 'solve' to generate all possible sums of subsets.
//    a. Base case: If the index 'ind' reaches the size of the input array 'nums', add the current sum to 'sums'.
//    b. Recursively call 'solve' for two cases:
//       i. Exclude the current element by calling 'solve(ind + 1, sum, nums, sums)'.
//       ii. Include the current element by calling 'solve(ind + 1, sum + nums[ind], nums, sums)'.
// 2. Start the recursion from index 0 with an initial sum of 0.
// 3. Return the vector 'sums' containing all possible sums.

// Time Complexity: O(2^N), where N is the number of elements in the input array 'nums'.
//                  This is because there are 2^N possible subsets.
// Space Complexity: O(2^N), considering the space required to store all possible subset sums.

void solve(int ind, int sum, vector<int> &nums, vector<int> &sums)
{
    if (ind == nums.size())
    {
        sums.push_back(sum);
        return;
    }

    // Exclude the current element
    solve(ind + 1, sum, nums, sums);
    
    // Include the current element
    solve(ind + 1, sum + nums[ind], nums, sums);
}

// Function to find all possible sums of subsets
vector<int> sumsOfSubsets(vector<int> &nums)
{
    vector<int> sums; // Vector to store all possible subset sums
    solve(0, 0, nums, sums); // Start recursion from index 0 with initial sum 0
    return sums;
}

int main()
{
    vector<int> nums{3, 1, 2};
    vector<int> sums = sumsOfSubsets(nums); // Calculate all possible subset sums
    
    // Print all possible subset sums
    for (int sum : sums)
        cout << sum << " ";
    
    return 0;
}
