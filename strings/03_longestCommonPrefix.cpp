#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

// Function to find the longest common prefix among an array of strings.
// Intuition:
// - Sort the array of strings to bring the common prefixes together.
// - Compare the first and last string in the sorted array to find the common prefix.
// Approach:
// - Sort the array of strings in lexicographical order.
// - Iterate through the characters of the first string.
// - Compare the corresponding characters of the first and last string.
// - Return the common prefix found.
// Time complexity: O(n * m * log n), where n is the number of strings and m is the length of the longest string.
//   - Sorting the array of strings takes O(n * log n) time.
//   - Finding the common prefix takes O(m) time.
// Space complexity: O(1), constant space used.
string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end()); // Sort the array of strings

    int i = 0; // Initialize index for iterating through characters
    while (i < strs[0].size())
    {
        char c = strs[0][i]; // Get the character from the first string
        for (int j = 1; j < strs.size(); j++)
        {
            // Compare characters from other strings with the current character
            if (strs[j][i] != c)
            {
                return strs[0].substr(0, i); // Return the common prefix found
            }
        }
        i++; // Move to the next character
    }
    return strs[0]; // Return the entire first string if it's the only string or all strings have the same prefix
}

// Alternate function using a different approach to find the longest common prefix.
// Intuition:
// - Sort the array of strings to bring the common prefixes together.
// - Compare the first and last string in the sorted array to find the common prefix.
// Approach:
// - Sort the array of strings in lexicographical order.
// - Iterate through the characters of the first string and the last string.
// - Compare the corresponding characters of both strings.
// - Return the common prefix found.
// Time complexity: O(n * m * log n), where n is the number of strings and m is the length of the longest string.
//   - Sorting the array of strings takes O(n * log n) time.
//   - Finding the common prefix takes O(m) time.
// Space complexity: O(1), constant space used.
string longestCommonPrefix2(vector<string> &strs)
{
    sort(strs.begin(), strs.end()); // Sort the array of strings

    int i = 0;               // Initialize index for iterating through characters
    int l = strs.size() - 1; // Index of the last string in the sorted array
    while (i < strs[0].size() && strs[l][i] == strs[0][i])
    {
        i++; // Move to the next character if characters match
    }
    return strs[0].substr(0, i); // Return the common prefix found
}

int main()
{
    // Test cases
    vector<string> strings1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strings1) << endl; // Output: "fl"

    vector<string> strings2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix2(strings2) << endl; // Output: ""

    return 0;
}
