#include <iostream>
using namespace std;

// Problem Statement:
// Implement strStr() function, which returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Intuition:
// We'll use a two-pointer approach to iterate through the haystack string.
// At each position in the haystack, we'll check if the substring starting from that position matches the needle string.
// If a match is found, we return the starting index of the matching substring.
// If no match is found, we backtrack and continue searching.

// DSA Strategy/Pattern:
// Two Pointers

// Function to find the index of the first occurrence of needle in haystack
int strStr(string haystack, string needle)
{
    // Iterate through the haystack string.
    for (int left = 0, right = 0; left < haystack.size(); left++)
    {
        // Check if characters match.
        if (haystack[left] == needle[right])
        {
            right++; // Increment needle pointer if characters match.
        }
        else
        {
            // Backtrack haystack pointer and reset needle pointer.
            left = left - right;
            right = 0;
        }
        // Check if the entire needle is found in the haystack.
        if (right == needle.size())
        {
            return left - right + 1; // Return starting index of the needle substring.
        }
    }
    return -1; // Return -1 if needle is not found in the haystack.
}

int main()
{
    // Test cases
    cout << strStr("sadbutsad", "sad") << endl;          // Output: 0
    cout << strStr("aaa", "aaaa") << endl;               // Output: -1
    cout << strStr("mississippi", "issip") << endl;      // Output: 4
    return 0;
}
