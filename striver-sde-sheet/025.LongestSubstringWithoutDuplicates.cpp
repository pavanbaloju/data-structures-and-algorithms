#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if there are duplicates within a given range in a map.
// Intuition:
// This function checks if there are duplicates within a given range in a map.
// Approach:
// Compares the size of the map with the difference between the end and start index of the range.
// If the size is less than the difference, there are duplicates.
// Time complexity: O(1) - Comparing sizes of maps.
// Space complexity: O(1) - No additional space used besides the map.
bool hasDuplicates(unordered_map<char, int> visited, int i, int j)
{
    // Check if the size of the map is less than the difference between the end and start index of the range.
    return visited.size() < j - i + 1;
}

// Function to find the length of the longest substring without repeating characters.
// Intuition:
// This function aims to find the length of the longest substring without repeating characters.
// It uses a sliding window approach to traverse the string while keeping track of character counts in a map.
// Approach:
// 1. Initialize variables `charAndCount` map, `maxLen`, and `currLen`.
// 2. Use two pointers, `i` and `j`, to define the current substring.
// 3. Iterate `j` through the string:
//    a. Increment the count of the character at index `j` in the `charAndCount` map.
//    b. If the size of `charAndCount` equals the length of the current substring (`j - i + 1`), update `maxLen`.
//    c. If the size of `charAndCount` is greater than the length of the current substring, move the `i` pointer until `charAndCount` size becomes valid.
// 4. Return `maxLen`.
// Time complexity: O(n) - Single pass through the input string.
// Space complexity: O(min(n, m)) - Additional space used to store characters and their counts in the `charAndCount` map, where `n` is the length of the string and `m` is the size of the character set.
int lengthOfLongestSubstring(string s)
{
    // If the string is empty, return 0.
    if (s.length() == 0)
        return 0;

    // Initialize a map to store characters and their counts.
    unordered_map<char, int> charAndCount;

    // Initialize variables for maximum length and current length.
    int maxLen = INT_MIN, currLen = 0;

    // Loop with two pointers, `i` and `j`, defining the current substring.
    for (int i = 0, j = 0; j < s.length(); j++)
    {
        // Increment the count of the character at index `j`.
        charAndCount[s[j]]++;

        // If the size of `charAndCount` equals the length of the current substring (`j - i + 1`), update `maxLen`.
        if (charAndCount.size() == j - i + 1)
        {
            maxLen = max(maxLen, j - i + 1);
        }
        // If the size of `charAndCount` is greater than the length of the current substring, move the `i` pointer until `charAndCount` size becomes valid.
        else if (charAndCount.size() < j - i + 1)
        {
            while (charAndCount.size() < j - i + 1)
            {
                if (--charAndCount[s[i]] == 0)
                {
                    charAndCount.erase(s[i]);
                }
                i++;
            }
        }
    }
    // Return the maximum length of the substring without repeating characters.
    return maxLen;
}

// Function to find the length of the longest substring without repeating characters using an optimized approach.
// Intuition:
// This function aims to find the length of the longest substring without repeating characters.
// It utilizes a sliding window approach to traverse the string while keeping track of the last occurrence index of each character.
// Approach:
// 1. Initialize variables `maxLength`, `left`, and `charAndIndex` map.
// 2. Iterate `right` pointer through the string:
//    a. If the current character is not present in the `charAndIndex` map or its last occurrence is before the `left` boundary,
//       update `charAndIndex` and `maxLength`.
//    b. If the current character is a duplicate, update `left` to the next index after the last occurrence of the current character.
// 3. Return `maxLength`.
// Time complexity: O(n) - Single pass through the input string.
// Space complexity: O(min(n, m)) - Additional space used to store characters and their last occurrence indices in the `charAndIndex` map, where `n` is the length of the string and `m` is the size of the character set.
int lengthOfLongestSubstringOpt(string s)
{
    // Get the length of the input string.
    int n = s.length();
    
    // Initialize variables for maximum length, left boundary, and character indices.
    int maxLength = 0;
    unordered_map<char, int> charAndIndex;
    int left = 0;

    // Loop through the string with the right pointer.
    for (int right = 0; right < n; right++)
    {
        // If the current character is not present in the map or its last occurrence is before the left boundary.
        if (charAndIndex.count(s[right]) == 0 || charAndIndex[s[right]] < left)
        {
            // Update the last occurrence index of the current character and maximum length.
            charAndIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        else
        {
            // Update the left boundary to the next index after the last occurrence of the current character.
            left = charAndIndex[s[right]] + 1;
            charAndIndex[s[right]] = right;
        }
    }

    // Return the maximum length of the substring without repeating characters.
    return maxLength;
}

int main()
{
    // Output the length of the longest substring without repeating characters for both approaches
    cout << "Brute Force: " << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Optimized: " << lengthOfLongestSubstringOpt("abcabcbb") << endl;
    return 0;
}
