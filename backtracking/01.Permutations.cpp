#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given an array nums of distinct integers, return all possible permutations. You can return the answer in any order.

// Intuition:
// The problem can be solved using backtracking by exploring all possible permutations.
// Alternatively, we can use an optimized approach by swapping elements in place to generate permutations.

// Approach 1: Backtracking with additional space
// 1. Initialize an empty current permutation (permn) and a result container (permns).
// 2. Recursively build permutations by adding each element not yet in permn.
// 3. Once the current permutation size equals nums size, add it to the result container.
// 4. Backtrack by removing the last element and exploring other possibilities.

// Time Complexity: O(n * n!), where n is the size of nums.
// Space Complexity: O(n!), due to the storage of all permutations.

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
            permn.push_back(nums[i]);   // Include the current number in the permutation if it's not already present
            solve(nums, permn, permns); // Recursively generate permutations
            permn.pop_back();           // Backtrack: Remove the last added element for the next permutation
        }
    }
}

// Function to generate all permutations using additional space for backtracking
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> permn;          // Current permutation
    vector<vector<int>> permns; // All permutations
    solve(nums, permn, permns); // Recursive permutation generation
    return permns;              // Return all generated permutations
}

// Approach 2: Backtracking with swapping in place
// 1. Recursively generate permutations by swapping the current element with each subsequent element.
// 2. After each swap, recurse with the next index to continue building the permutation.
// 3. Once the index reaches the size of nums, add the current permutation to the result container.
// 4. Backtrack by swapping back the elements to restore the original array state.

// Time Complexity: O(n * n!), where n is the size of nums.
// Space Complexity: O(1) additional space, aside from the recursion stack.

void solve2(int ind, int n, vector<int> &nums, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(nums); // Base case: Add the current permutation to the result if the index reaches the size of nums
        return;
    }

    for (int i = ind; i < n; i++)
    {
        swap(nums[i], nums[ind]);      // Swap elements to create a new permutation
        solve2(ind + 1, n, nums, ans); // Recursively generate permutations
        swap(nums[i], nums[ind]);      // Backtrack: Restore the original order of elements for the next iteration
    }
}

// Function to generate all permutations using swapping instead of additional space
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans; // Vector to store all permutations
    int n = nums.size();     // Size of the input vector
    solve2(0, n, nums, ans); // Recursive permutation generation
    return ans;              // Return all generated permutations
}

// Function to print a vector of vectors
void print(vector<vector<int>> &ans)
{
    for (auto row : ans)
    {
        for (auto n : row)
            cout << n << " "; // Print each element in the row
        cout << endl;         // Move to the next row
    }
}

int main()
{
    vector<int> nums = {1, 2, 3}; // Input vector

    cout << "Permutations using additional space for backtracking:" << endl;
    vector<vector<int>> ans = permute(nums); // Generate permutations using additional space
    print(ans);                              // Print permutations

    cout << endl;

    cout << "Permutations using swapping instead of additional space:" << endl;
    vector<vector<int>> ans2 = permute2(nums); // Generate permutations using swapping instead of additional space
    print(ans2);                               // Print permutations

    return 0;
}
