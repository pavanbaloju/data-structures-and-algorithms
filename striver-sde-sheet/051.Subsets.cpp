#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of distinct integers, nums, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.

// Intuition:
// Use recursion to generate all possible subsets.

// DSA Strategy:
// Recursion, Backtracking

// Approach:
// 1. Implement a recursive function 'solve' to generate all possible subsets.
//    a. Base case: If the index 'ind' reaches the size of the input array 'nums', add the current subset 'curr' to 'res'.
//    b. Recursively call 'solve' for two cases:
//       i. Exclude the current element by calling 'solve(ind + 1, n, nums, curr, res)'.
//       ii. Include the current element by pushing it to 'curr', then calling 'solve(ind + 1, n, nums, curr, res)', and finally popping it from 'curr'.
// 2. Start the recursion from index 0 with an empty 'curr' vector.
// 3. Return the 'res' vector containing all possible subsets.

// Time Complexity: O(2^N), where N is the number of elements in the input array 'nums'.
//                  This is because there are 2^N possible subsets.
// Space Complexity: O(2^N * N), considering the space required to store all possible subsets.

void solve(int ind, int n, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res)
{
    if (ind == n)
    {
        res.push_back(curr);
        return;
    }

    // Exclude the current element
    solve(ind + 1, n, nums, curr, res);

    // Include the current element
    curr.push_back(nums[ind]);
    solve(ind + 1, n, nums, curr, res);
    curr.pop_back();
}

// Function to find all possible subsets
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res; // Vector to store all possible subsets
    vector<int> curr; // Vector to store current subset being formed
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
            cout<<" " << v[i] << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    vector<int> nums{3, 1, 2};
    vector<vector<int>> res = subsets(nums); // Calculate all possible subsets
    print(res); // Print all possible subsets
    return 0;
}
