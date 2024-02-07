#include <iostream>
using namespace std;

// Function to find the starting index of the first occurrence of a substring in a string (needle in haystack).
// Intuition:
// - Iterate through the haystack string and compare characters with the needle string.
// - If a match is found, continue comparing subsequent characters.
// - If a mismatch occurs, backtrack the index in the haystack and reset the index in the needle.
// Approach:
// - Use two pointers, i and j, to traverse the haystack and needle strings, respectively.
// - If haystack[i] matches needle[j], increment both i and j.
// - If a mismatch occurs, reset i to (i - j + 1) and j to 0.
// - Repeat the process until the entire needle is found in the haystack or the end of haystack is reached.
// Time complexity: O(n * m), where n is the length of the haystack and m is the length of the needle.
//   - Worst-case time complexity occurs when the needle occurs at the end of the haystack.
// Space complexity: O(1), constant space used.
int strStr(string haystack, string needle)
{
    // Iterate through the haystack string.
    for (int i = 0, j = 0; i < haystack.size(); i++)
    {
        // Check if characters match.
        if (haystack[i] == needle[j])
        {
            j++; // Increment needle pointer if characters match.
        }
        else
        {
            // Backtrack haystack pointer and reset needle pointer.
            i = i - j;
            j = 0;
        }
        // Check if the entire needle is found in the haystack.
        if (j == needle.size())
        {
            return i - j + 1; // Return starting index of the needle substring.
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
