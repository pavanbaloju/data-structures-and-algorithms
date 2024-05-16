#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Intuition:
// The problem can be solved using backtracking by exploring all possible subsets of the given array.
// For each element, we have the choice to either include it in the current subset or exclude it, which leads to two recursive calls.

// Approach:
// 1. Start from the first element and recursively generate subsets.
// 2. For each element, make two recursive calls:
//    - One excluding the current element.
//    - One including the current element.
// 3. Once we have processed all elements, add the current subset to the result set.
// 4. Backtrack by removing the last added element and continue the recursion.

// Time Complexity: O(2^n), where n is the size of nums. Each element has two choices (include or exclude).
// Space Complexity: O(n), for the recursion stack and the current subset.

void solve(int ind, int n, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res)
{
    if (ind == n)
    {
        res.push_back(curr); // Base case: Add the current subset to the result when all elements are processed
        return;
    }

    // Exclude the current element
    solve(ind + 1, n, nums, curr, res);

    // Include the current element
    curr.push_back(nums[ind]);
    solve(ind + 1, n, nums, curr, res);
    curr.pop_back(); // Backtrack: Remove the last added element for the next iteration
}

// Function to find all possible subsets
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res; // Vector to store all possible subsets
    vector<int> curr;        // Vector to store the current subset being formed
    int n = nums.size();
    solve(0, n, nums, curr, res); // Start recursion from index 0 with an empty 'curr'
    return res;
}

// Function to print vectors of vectors
void print(vector<vector<int>> vectors)
{
    for (auto v : vectors)
    {
        cout << "[";
        for (int i = 0; i < v.size(); ++i)
        {
            cout << " " << v[i] << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    vector<int> nums{3, 1, 2};               // Input vector
    vector<vector<int>> res = subsets(nums); // Calculate all possible subsets
    print(res);                              // Print all possible subsets
    return 0;
}
