#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Problem Statement:
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// Intuition:
// This problem can be solved using backtracking. We can map each digit to its corresponding letters and generate all possible combinations recursively.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a function 'solve' to recursively generate all possible combinations of letters.
//    - If the index reaches the size of the digits string, it means a combination is formed, so add it to the result.
//    - For the current digit, iterate over its corresponding letters and append each letter to the combination, then recursively call 'solve' with the next index.
//    - After each recursive call, backtrack by removing the last added letter from the combination.
// 2. Define the main function 'letterCombinations' to initialize an empty combination string and call the 'solve' function to generate all combinations.
// 3. Return the generated combinations.

// Time Complexity: O(4^n), where 'n' is the number of digits in the input string. Each digit can represent up to 4 letters in the mapping.
// Space Complexity: O(4^n) for storing the result.

// Function to print the generated combinations
void print(vector<string> v)
{
    for (auto s : v)
        cout << s << " ";
}

// Function to recursively generate all possible combinations of letters
void solve(int index, string &comb, vector<string> &ans, string digits, map<char, string> mapping)
{
    if (index == digits.size())
    {
        ans.push_back(comb); // Add the generated combination to the result
        return;
    }

    for (char ch : mapping[digits[index]])
    {
        comb.push_back(ch); // Append the current letter to the combination
        solve(index + 1, comb, ans, digits, mapping); // Recursively call solve with the next index
        comb.pop_back(); // Backtrack by removing the last added letter
    }
}

// Function to generate all possible letter combinations from a string of digits
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return {}; // If the input string is empty, return an empty vector
    }
    string comb; // Initialize an empty combination string
    vector<string> ans; // Initialize an empty result vector

    // Mapping of digits to corresponding letters
    map<char, string> mapping = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    solve(0, comb, ans, digits, mapping); // Call the recursive function to generate combinations
    return ans; // Return the result vector containing all combinations
}

// Main function to demonstrate the letterCombinations function
int main()
{
    print(letterCombinations("236")); // Generate letter combinations for the given digits and print them
    return 0;
}
