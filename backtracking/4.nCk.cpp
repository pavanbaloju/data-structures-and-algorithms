#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given two integers 'n' and 'k', return all possible combinations of 'k' numbers out of the range [1, n].

// Intuition:
// To generate all possible combinations of 'k' numbers from the range [1, n], we can use backtracking.
// We start with an empty combination and iteratively add numbers to it until it reaches size 'k'.
// After adding 'k' numbers, we add the combination to the result set.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a function 'solve' to generate all combinations of 'k' numbers.
//    - If the size of the combination becomes equal to 'k', add it to the result.
//    - Otherwise, iterate over the numbers from 's' to 'n', add each number to the combination,
//      and recursively call 'solve' with the next index.
//    - After the recursive call, remove the last added number from the combination to backtrack.
// 2. Define the main function 'combine' to initialize an empty combination and call the 'solve' function to generate combinations.
// 3. Print the generated combinations.

// Time Complexity: O(n choose k), where n choose k is the number of combinations of 'n' elements taken 'k' at a time.
// Space Complexity: O(k * n choose k)

// Function to print the combinations
void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto n : row)
            cout << n << " ";
        cout << endl;
    }
}

// Function to generate combinations using backtracking
void solve(int s, int n, int k, vector<int> &choose, vector<vector<int>> &ans)
{
    if (k == choose.size())
    {
        ans.push_back(vector<int>(choose));
        return;
    }

    for (int i = s; i <= n; i++)
    {
        choose.push_back(i); // Add the current number to the combination
        solve(i + 1, n, k, choose, ans); // Recursively generate combinations with the next index
        choose.pop_back(); // Backtrack by removing the last added number
    }
}

// Function to generate all combinations of 'k' numbers out of the range [1, n]
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans; // Result vector to store combinations
    vector<int> choose; // Vector to store the current combination being generated
    solve(1, n, k, choose, ans); // Call the recursive function to generate combinations
    return ans; // Return the result vector containing all combinations
}

// Main function to demonstrate the combine function
int main()
{
    vector<vector<int>> ans = combine(4, 2); // Generate combinations of 2 numbers out of the range [1, 4]
    print(ans); // Print the generated combinations
    return 0;
}
