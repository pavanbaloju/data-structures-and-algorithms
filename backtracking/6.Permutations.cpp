#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a collection of distinct integers, return all possible permutations.

// Intuition:
// We can use backtracking to generate all possible permutations of the given integers.

// DSA Strategy:
// Recursion, Backtracking

// Approach 1:
// 1. Implement a recursive function 'solve' to generate all possible permutations.
//    a. Base case: If the size of the current permutation 'permn' becomes equal to the size of the input array 'nums', add 'permn' to the result 'permns'.
//    b. For each index 'i' in the range [0, nums.size()):
//       i. If 'nums[i]' is not already present in 'permn', add it to 'permn'.
//       ii. Recursively call 'solve' with the updated 'permn'.
//       iii. Backtrack: Remove the last added element from 'permn' before the next iteration.
// 2. After generating all possible permutations, return the 'permns' vector containing all permutations.
//
// Time Complexity: O(N!), where N is the number of elements in the input array 'nums'.
// Space Complexity: O(N!), considering the space required to store all possible permutations.

// Function to generate all permutations using additional space for backtracking
void solve(vector<int> &nums, vector<int> &permn, vector<vector<int>> &permns)
{
    if (permn.size() == nums.size())
    {
        permns.push_back(permn); // Base case: Add the current permutation to the result if its size is equal to the number of elements in nums
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (find(permn.begin(), permn.end(), nums[i]) == permn.end())
        {
            permn.push_back(nums[i]); // Include the current number in the permutation if it's not already present
            solve(nums, permn, permns); // Recursively generate permutations
            permn.pop_back(); // Backtrack: Remove the last added element for the next permutation
        }
    }
}

// Function to generate all permutations using additional space for backtracking
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> permn; // Current permutation
    vector<vector<int>> permns; // All permutations
    solve(nums, permn, permns); // Recursive permutation generation
    return permns; // Return all generated permutations
}

// Approach 2:
// 1. Implement a recursive function 'solve2' to generate all possible permutations using swapping instead of additional space.
//    a. Base case: If the index 'ind' reaches the size of the input array 'nums', add 'nums' to the result 'ans'.
//    b. For each index 'i' starting from 'ind':
//       i. Swap 'nums[i]' with 'nums[ind]'.
//       ii. Recursively call 'solve2' with the updated index 'ind + 1'.
//       iii. Backtrack: Restore the original order of elements after each recursion.
// 2. After generating all possible permutations, return the 'ans' vector containing all permutations.
//
// Time Complexity: O(N!), where N is the number of elements in the input array 'nums'.
// Space Complexity: O(N!), considering the space required to store all possible permutations.

// Function to generate all permutations using swapping instead of additional space
void solve2(int ind, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(nums); // Base case: Add the current permutation to the result if the index reaches the size of nums
        return;
    }

    for (int i = ind; i < n; i++)
    {
        swap(nums[i], nums[ind]); // Swap elements to create a new permutation
        solve2(ind + 1, n, nums, ans); // Recursively generate permutations
        swap(nums[i], nums[ind]); // Backtrack: Restore the original order of elements for the next iteration
    }
}

// Function to generate all permutations using swapping instead of additional space
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans; // Vector to store all permutations
    int n = nums.size(); // Size of the input vector
    solve2(0, n, nums, ans); // Recursive permutation generation
    return ans; // Return all generated permutations
}

// Function to print a vector of vectors
void print(vector<vector<int>> &ans)
{
    for (auto row : ans)
    {
        for (auto n : row)
            cout << n << " "; // Print each element in the row
        cout << endl; // Move to the next row
    }
}

int main()
{
    vector<int> nums = {1, 2, 3}; // Input vector
    cout << "Permutations using additional space for backtracking:" << endl;
    vector<vector<int>> ans = permute(nums); // Generate permutations using additional space
    print(ans); // Print permutations
    cout << endl;
    cout << "Permutations using swapping instead of additional space:" << endl;
    vector<vector<int>> ans2 = permute2(nums); // Generate permutations using swapping instead of additional space
    print(ans2); // Print permutations
    return 0;
}
