#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an integer 'n', generate all combinations of well-formed parentheses pairs of length '2n'.

// Intuition:
// To generate all combinations of well-formed parentheses, we can use backtracking.
// We start with an empty string and add '(' or ')' based on certain conditions until we form valid pairs.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a function 'solve' to recursively generate combinations of well-formed parentheses.
//    - If both 'left' and 'right' counts become zero, it means a valid combination is formed, so add it to the result.
//    - If 'left' count is greater than zero, it means we can add '(' to the string, so add it and recursively call 'solve' with decreased 'left' count.
//    - If 'right' count is greater than 'left' count, it means we can add ')' to the string, so add it and recursively call 'solve' with decreased 'right' count.
//    - After each recursive call, remove the last character from the string to backtrack.
// 2. Define the main function 'generateParenthesis' to initialize an empty string and call the 'solve' function to generate combinations.
// 3. Return the generated combinations.

// Time Complexity: O(4^n / sqrt(n)), where 'n' is the number of pairs of parentheses to be generated.
// Space Complexity: O(4^n / sqrt(n)) for storing the result.

// Function to recursively generate combinations of well-formed parentheses
void solve(int left, int right, string s, vector<string> &res)
{
    if (left == 0 && right == 0)
    {
        res.push_back(s); // Add the generated combination to the result
        return;
    }
    if (left > 0)
    {
        s.push_back('(');               // Add '(' if left count is greater than zero
        solve(left - 1, right, s, res); // Recursively call solve with decreased left count
        s.pop_back();                   // Backtrack by removing the last character
    }
    if (right > left)
    {
        s.push_back(')');               // Add ')' if right count is greater than left count
        solve(left, right - 1, s, res); // Recursively call solve with decreased right count
        s.pop_back();                   // Backtrack by removing the last character
    }
}

// Function to generate all combinations of well-formed parentheses
vector<string> generateParenthesis(int n)
{
    vector<string> res;  // Result vector to store generated combinations
    string s = "";       // Initialize an empty string
    solve(n, n, s, res); // Call the recursive function to generate combinations
    return res;          // Return the result vector containing all combinations
}

// Function to print the generated combinations
void print(vector<string> v)
{
    for (auto s : v)
        cout << " " << s << " ";
}

// Main function to demonstrate the generateParenthesis function
int main()
{
    vector<string> res = generateParenthesis(3); // Generate combinations of well-formed parentheses for n = 3
    print(res);                                  // Print the generated combinations
    return 0;
}
