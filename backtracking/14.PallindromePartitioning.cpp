#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Intuition:
// We can use backtracking to generate all possible palindrome partitions of the input string.
// At each step, we consider all possible substrings starting from the current index and check
// if they are palindromes. If a substring is a palindrome, we add it to the current partition
// and recursively explore the rest of the string. Once we reach the end of the string, we add
// the current partition to the result.

// DSA Strategy/Pattern: Backtracking

// Approach:
// Explanation:
// 1. Define a helper function 'isPalindrome' to check if a substring is a palindrome.
//    - Iterate from both ends of the substring and compare characters.
//    - If any pair of characters does not match, return false; otherwise, return true.
// 2. Define a recursive helper function 'partitionHelper' to generate all palindrome partitions.
//    - If the current index reaches the end of the string, add the current partition to the result.
//    - Iterate from the current index to the end of the string.
//    - If the substring from the current index to the current iterator is a palindrome:
//      - Add it to the current partition.
//      - Recursively call the function for the next index (i + 1).
//      - Backtrack: Remove the last added substring from the current partition.
// 3. Define the main function 'partition' to initialize variables and call 'partitionHelper'.
//    - Initialize an empty result vector to store all palindrome partitions.
//    - Initialize an empty vector to store the current partition being formed.
//    - Call 'partitionHelper' with index 0, the input string 's', the empty partition vector,
//      and the result vector.
//    - Return the result vector.
// 4. Example usage: Create a sample input string and call 'partition' to generate palindrome partitions.

// Time Complexity: O(n * 2^n) where n is the length of the input string 's'.
//                  Each partition has 2 choices (partition or not) and checking for palindrome
//                  takes O(n) time in the worst case.
// Space Complexity: O(n^2) for storing substrings in the result vector.

// Function to check if a substring is a palindrome
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

// Helper function for backtracking and generating palindrome partitions
void partitionHelper(int index, string s, vector<string> &substrs, vector<vector<string>> &res)
{
    // If the current index reaches the end of the string, add the current partition to the result
    if (index == s.size())
    {
        res.push_back(substrs);
        return;
    }

    // Iterate from the current index to the end of the string
    for (int i = index; i < s.size(); ++i)
    {
        // If the substring from the current index to i is a palindrome, add it to the current partition
        if (isPalindrome(s, index, i))
        {
            substrs.push_back(s.substr(index, i - index + 1));
            // Recursively call the function for the next index (i + 1)
            partitionHelper(i + 1, s, substrs, res);
            // Backtrack: Remove the last added substring from the current partition
            substrs.pop_back();
        }
    }
}

// Main function to generate all palindrome partitions of the input string
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;          // Result vector to store all palindrome partitions
    vector<string> substrs;              // Current partition being formed
    partitionHelper(0, s, substrs, res); // Start backtracking from the first index with an empty partition
    return res;                          // Return the final result
}

// Main function
int main()
{
    // Example usage
    string s = "aabb";
    vector<vector<string>> ans = partition(s); // Generate all palindrome partitions for the input string
    // Print the generated palindrome partitions
    for (auto v : ans)
    {
        for (auto str : v)
            cout << str << ", ";
        cout << endl;
    }
    return 0;
}
