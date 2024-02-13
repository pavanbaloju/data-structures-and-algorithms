#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem Statement:
// Given an array of integers that may contain duplicates, nums, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.

// Intuition:
// Use recursion to generate all possible subsets. To avoid duplicate subsets, use a set to store unique subsets.

// DSA Strategy:
// Recursion, Backtracking, Set

// Approach:
// 1. Implement a recursive function 'solve' to generate all possible subsets.
//    a. Base case: If the index 'ind' reaches the size of the input array 'nums', insert the current subset 'curr' into the set 'unique'.
//    b. Recursively call 'solve' for two cases:
//       i. Exclude the current element by calling 'solve(ind + 1, n, nums, curr, unique)'.
//       ii. Include the current element by pushing it to 'curr', then calling 'solve(ind + 1, n, nums, curr, unique)', and finally popping it from 'curr'.
// 2. Sort the input array 'nums' to handle duplicates effectively.
// 3. After generating all possible subsets, copy the unique subsets from the set 'unique' to the result vector 'res'.
// 4. Return the 'res' vector containing all unique subsets.

// Time Complexity: O(2^N * log(N)), where N is the number of elements in the input array 'nums'.
//                  This is because there are 2^N possible subsets, and sorting the array takes O(N * log(N)) time.
// Space Complexity: O(2^N * N), considering the space required to store all possible subsets and the set 'unique'.

void solve(int ind, int n, vector<int> &nums, vector<int> &curr, set<vector<int>> &unique)
{
    if (ind == n)
    {
        unique.insert(curr);
        return;
    }

    // Exclude the current element
    solve(ind + 1, n, nums, curr, unique);

    // Include the current element
    curr.push_back(nums[ind]);
    solve(ind + 1, n, nums, curr, unique);
    curr.pop_back();
}

// Function to find all possible subsets without duplicates
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

void solve2(vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &result)
{
    result.push_back(cur); // Add the current subset to the result

    for (int i = start; i < nums.size(); i++)
    {
        if (i > start && nums[i] == nums[i - 1])
        {
            continue; // Skip over consecutive duplicates
        }
        cur.push_back(nums[i]);        // Include nums[i] in the current subset
        solve2(nums, i + 1, cur, result); // Explore further subsets
        cur.pop_back();                // Backtrack: Remove nums[i] from the current subset
    }
}

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
    vector<int> nums{3, 1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums); // Calculate all possible subsets without duplicates
    print(res);                              // Print all possible subsets without duplicates
    res = subsetsWithDup2(nums); // Calculate all possible subsets without duplicates
    print(res);            
    return 0;
}
