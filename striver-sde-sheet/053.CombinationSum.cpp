#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// Intuition:
// Use backtracking to explore all possible combinations. 
// Start with an empty combination and recursively add numbers from the candidates array to form combinations that sum up to the target.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Implement a recursive function 'solve' to generate all possible combinations.
//    a. Base cases:
//       i. If the target becomes negative or the index 'index' exceeds the size of the candidates array, return.
//       ii. If the target becomes 0, it means a valid combination is found. Add this combination to the result 'ans'.
//    b. Recursively call 'solve' for two cases:
//       i. Include the current element nums[index] by pushing it to the combination 'comb', then calling 'solve(index, nums, comb, ans, target - nums[index])', and finally popping it from 'comb'.
//       ii. Exclude the current element nums[index] by calling 'solve(index + 1, nums, comb, ans, target)'.
// 2. Start the recursion from index 0 and an empty combination vector.
// 3. Return the 'ans' vector containing all unique combinations.

// Time Complexity: Exponential, as there can be many combinations to explore.
// Space Complexity: Exponential, as the space required to store all unique combinations can grow exponentially.

void solve(int index, vector<int> &nums, vector<int> &comb, vector<vector<int>> &ans, int target)
{
    if (target < 0 || index == nums.size())
        return;

    if (target == 0)
    {
        ans.push_back(comb);
        return;
    }

    // Include the current element nums[index]
    comb.push_back(nums[index]);
    solve(index, nums, comb, ans, target - nums[index]);
    comb.pop_back(); // Backtrack: Remove nums[index] from the combination

    // Exclude the current element nums[index]
    solve(index + 1, nums, comb, ans, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> comb;
    solve(0, candidates, comb, ans, target);
    return ans;
}

void print(vector<vector<int>> &ans)
{
    for (auto row : ans)
    {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    vector<vector<int>> ans = combinationSum(nums, 7);
    print(ans);
    return 0;
}
