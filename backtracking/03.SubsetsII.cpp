#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem Statement:
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Intuition:
// The problem can be solved using backtracking by exploring all possible subsets of the given array.
// For each element, we have the choice to either include it in the current subset or exclude it, which leads to two recursive calls.
// By sorting the array first and using a set to store unique subsets, we can avoid duplicate subsets.

// Approach 1:
// 1. Sort the input array to handle duplicates effectively.
// 2. Use a set to store unique subsets.
// 3. Recursively generate subsets by including and excluding each element.
// 4. Add the current subset to the set when all elements are processed.

// Time Complexity: O(2^n), where n is the size of nums. Each element has two choices (include or exclude).
// Space Complexity: O(2^n * n), for storing all unique subsets and recursion stack.

void solve(int ind, int n, vector<int> &nums, vector<int> &curr, set<vector<int>> &unique)
{
    if (ind == n)
    {
        unique.insert(curr); // Base case: Add the current subset to the set if all elements are processed
        return;
    }

    // Exclude the current element
    solve(ind + 1, n, nums, curr, unique);

    // Include the current element
    curr.push_back(nums[ind]);
    solve(ind + 1, n, nums, curr, unique);
    curr.pop_back(); // Backtrack: Remove the last added element for the next iteration
}

// Function to find all possible subsets without duplicates using a set
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates effectively
    set<vector<int>> unique;        // Set to store unique subsets
    vector<int> curr;               // Vector to store current subset being formed
    int n = nums.size();
    solve(0, n, nums, curr, unique); // Start recursion from index 0 with an empty 'curr'

    vector<vector<int>> res; // Vector to store unique subsets
    for (auto v : unique)
    {
        res.push_back(v); // Copy unique subsets to the result vector
    }
    return res;
}

// Approach 2:
// 1. Sort the input array to handle duplicates effectively.
// 2. Use a recursive function to generate subsets by including each element once.
// 3. Skip over consecutive duplicates to avoid duplicate subsets in the result.

// Time Complexity: O(2^n), where n is the size of nums. Each element has two choices (include or exclude).
// Space Complexity: O(2^n * n), for storing all unique subsets and recursion stack.

void solve2(vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &result)
{
    result.push_back(cur); // Add the current subset to the result

    for (int i = start; i < nums.size(); i++)
    {
        if (i > start && nums[i] == nums[i - 1])
        {
            continue; // Skip over consecutive duplicates
        }
        cur.push_back(nums[i]);           // Include nums[i] in the current subset
        solve2(nums, i + 1, cur, result); // Explore further subsets
        cur.pop_back();                   // Backtrack: Remove nums[i] from the current subset
    }
}

// Function to find all possible subsets without duplicates using DFS
vector<vector<int>> subsetsWithDup2(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sort the input nums to handle duplicates properly

    vector<int> cur;            // To store the current subset being constructed
    vector<vector<int>> result; // To store the resulting subsets

    // Define a DFS function
    solve2(nums, 0, cur, result);
    return result; // Return the resulting subsets
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
    vector<int> nums{3, 1, 2, 2}; // Input vector containing duplicates
    cout << "Subsets using set to handle duplicates:" << endl;
    vector<vector<int>> res = subsetsWithDup(nums); // Calculate all possible subsets without duplicates using set
    print(res);                                     // Print all possible subsets without duplicates

    cout << endl;

    cout << "Subsets using DFS to handle duplicates:" << endl;
    res = subsetsWithDup2(nums); // Calculate all possible subsets without duplicates using DFS
    print(res);                  // Print all possible subsets without duplicates
    return 0;
}