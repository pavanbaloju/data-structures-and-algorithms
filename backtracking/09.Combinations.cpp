#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Generate all combinations of k elements from the range [1, n].

// Intuition:
// We can use backtracking to generate all combinations. At each step, we choose an element and explore 
// all possible combinations by recursively choosing the next elements.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// 1. Define a recursive function 'solve' to generate combinations.
//    - Base case: If the size of the current combination equals k, add it to the answer.
//    - Explore all possible choices for the next element, starting from 's' to 'n'.
//    - Choose the current element, recur with the next starting index, and backtrack.
// 2. Define the 'combine' function to generate all combinations of k elements from [1, n].
//    - Initialize a vector to store the combinations.
//    - Initialize a vector to store the current combination.
//    - Call the 'solve' function to generate combinations.
// 3. Print the generated combinations.

// Time Complexity: O(C(n, k)) where C(n, k) is the binomial coefficient "n choose k", representing the number of combinations.
// Space Complexity: O(k * C(n, k)) for storing the combinations.

// Function to generate combinations of k elements from the range [1, n]
void solve(int s, int n, int k, vector<int> &choose, vector<vector<int>> &ans)
{
    // Base case: if the size of the combination equals k, add it to the answer
    if (k == choose.size())
    {
        ans.push_back(vector<int>(choose)); // Add the current combination to the answer
        return; // Return to backtrack
    }

    // Explore all possible choices for the next element
    for (int i = s; i <= n; i++)
    {
        choose.push_back(i); // Choose the current element
        solve(i + 1, n, k, choose, ans); // Recur with the next starting index
        choose.pop_back(); // Backtrack: remove the current element to explore other choices
    }
}

// Function to generate all combinations of k elements from the range [1, n]
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans; // Vector to store the combinations
    vector<int> choose; // Vector to store the current combination being formed
    solve(1, n, k, choose, ans); // Call the helper function to generate combinations
    return ans; // Return the combinations
}

// Function to print a vector of vectors
void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto n : row)
            cout << n << " "; // Print each element of the combination
        cout << endl; // Move to the next line for the next combination
    }
}

int main()
{
    // Example usage
    vector<vector<int>> ans = combine(4, 2); // Generate combinations of 2 elements from [1, 4]
    print(ans); // Print the generated combinations
    return 0;
}