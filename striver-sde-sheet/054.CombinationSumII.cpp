#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given an array of integers candidates and a target, find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Intuition:
// Use recursion to generate all possible combinations that sum up to the target.
// Sort the input array to handle duplicates properly.
// Skip over duplicate elements while forming combinations to ensure uniqueness.

// DSA Strategy:
// Recursion, Backtracking, Sorting

// Approach:
// 1. Implement a recursive function 'solve' to find unique combinations.
//    a. Base case: If the target becomes 0, add the current combination 'comb' to the result 'ans'.
//    b. Loop through the elements starting from 'index':
//       i. Skip duplicates by checking if the current element is equal to the previous element and if the current index is greater than the start index.
//       ii. If the current element is greater than the remaining target, stop the loop.
//       iii. Include the current element in the combination and recursively call 'solve' with updated index and target.
//       iv. Backtrack: Remove the current element from the combination.
// 2. Sort the input array 'candidates' to handle duplicates properly.
// 3. Call the recursive function 'solve' with initial parameters.
// 4. Return the result 'ans' containing all unique combinations.

// Time Complexity: O(2^N), where N is the number of elements in the input array 'candidates'.
//                  In the worst case, all combinations need to be generated.
// Space Complexity: O(N * M), where N is the number of elements in the input array 'candidates' and M is the average length of the combinations.

// Recursive function to find unique combinations that sum up to the target
void solve(int index, vector<int> &nums, vector<int> &comb, vector<vector<int>> &ans, int target)
{
    if (target == 0)
    {
        ans.push_back(comb);
        return;
    }

    // Loop through the elements starting from 'index'
    for (int i = index; i < nums.size(); ++i)
    {
        // Skip duplicates
        if (i > index && nums[i] == nums[i - 1])
            continue;

        // If the current element is greater than the remaining target, stop the loop
        if (nums[i] > target)
            break;

        // Include the current element in the combination
        comb.push_back(nums[i]);

        // Recursive call with updated index and target
        solve(i + 1, nums, comb, ans, target - nums[i]);

        // Backtrack: Remove the current element from the combination
        comb.pop_back();
    }
}

// Function to find unique combinations that sum up to the target
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> comb;
    // Sort the input array to handle duplicates properly
    sort(candidates.begin(), candidates.end());
    // Call the recursive function
    solve(0, candidates, comb, ans, target);
    return ans;
}

// Function to print vectors of vectors
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
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(nums, target);
    print(ans);
    return 0;
}
