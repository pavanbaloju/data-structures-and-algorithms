#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Intuition:
// Use backtracking to generate all possible palindrome partitions.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Implement a helper function 'isPalindrome' to check if a given substring of s is a palindrome.
//    a. Use two pointers 'start' and 'end' to traverse the substring from both ends.
//    b. If the characters at 'start' and 'end' are not equal, return false; otherwise, continue checking.
//    c. If 'start' becomes greater than or equal to 'end', return true.
// 2. Implement a helper function 'partitionHelper' to perform backtracking and generate palindrome partitions.
//    a. If the current index 'index' reaches the end of the string, add the current partition 'substrs' to the result 'res' and return.
//    b. Iterate from 'index' to the end of the string.
//       i. If the substring from 'index' to 'i' is a palindrome, add it to 'substrs'.
//       ii. Recursively call 'partitionHelper' for the next index 'i + 1'.
//       iii. Backtrack by removing the last added substring from 'substrs'.
// 3. Implement the main function 'partition' that initializes the result vector 'res' and calls 'partitionHelper' with the initial parameters.
// 4. Return the final result 'res'.

// Time Complexity: O(N * 2^N), where N is the length of the input string s.
//                  In the worst case, there can be 2^N possible palindrome partitions, and for each partition, it takes O(N) time to check if each substring is a palindrome.
// Space Complexity: O(N), where N is the length of the input string s.
//                   The space required for storing the current partition and the result vector.

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
    vector<vector<string>> res; // Result vector to store all palindrome partitions
    vector<string> substrs;     // Current partition being formed
    partitionHelper(0, s, substrs, res); // Start backtracking from the first index with an empty partition
    return res; // Return the final result
}

// Main function
int main()
{
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
