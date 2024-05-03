#include <iostream>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given a string, find the length of the longest substring without repeating characters.

// Intuition:
// The problem can be efficiently solved using a sliding window approach where we maintain a window containing unique characters.
// As we move the right pointer forward, we expand the window and update the maximum length of the substring without repeating characters.
// If we encounter a repeating character, we shrink the window from the left until it becomes valid again.

// DSA Strategy/Pattern:
// Sliding Window Technique

// Approach:
// Brute Force:
// Explanation:
// 1. Initialize a map to store characters and their counts, along with variables for maximum length and current length.
// 2. Loop through the string using two pointers, `i` and `j`, defining the current substring.
// 3. Increment the count of the character at index `j` in the map.
// 4. If the size of the map equals the length of the current substring (`j - i + 1`), update the maximum length.
// 5. If the size of the map is greater than the length of the current substring, move the `i` pointer until the map size becomes valid.
// 6. Return the maximum length.
// Time Complexity: O(n) - Single pass through the input string.
// Space Complexity: O(min(n, m)) - Additional space used to store characters and their counts in the map, where `n` is the length of the string and `m` is the size of the character set.
int lengthOfLongestSubstring(string s)
{
    // If the input string is empty, return 0
    if (s.length() == 0)
        return 0;

    // Initialize a map to store characters and their counts
    unordered_map<char, int> uniqueCount;
    // Initialize variables for maximum length and current length
    int maxLen = INT_MIN, currLen = 0;

    // Two pointers approach to iterate through the string
    for (int left = 0, right = 0; right < s.length(); right++)
    {
        // Increment the count of the character at index 'j' in the map
        uniqueCount[s[right]]++;

        // If the number of unique characters equals the length of the current substring
        if (uniqueCount.size() == right - left + 1)
        {
            // Update the maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        // If there are less unique characters than the length of the current substring
        else if (uniqueCount.size() < right - left + 1)
        {
            // Move the 'i' pointer until the substring becomes valid
            while (uniqueCount.size() < right - left + 1)
            {
                // Decrease the count of the character at index 'i'
                uniqueCount[s[left]]--;

                // If the count becomes zero, remove the character from the map
                if (uniqueCount[s[left]] == 0)
                {
                    uniqueCount.erase(s[left]);
                }
                // Move the 'i' pointer
                left++;
            }
        }
    }
    // Return the maximum length of the substring without repeating characters
    return maxLen;
}

// Optimized Approach:
// Explanation:
// 1. Initialize variables for maximum length, left boundary, and character indices.
// 2. Loop through the string with the right pointer.
// 3. If the current character is not present in the map or its last occurrence is before the left boundary,
//    update the last occurrence index of the current character and maximum length.
// 4. If the current character is a duplicate, update the left boundary to the next index after the last occurrence of the current character.
// 5. Return the maximum length.
// Time Complexity: O(n) - Single pass through the input string.
// Space Complexity: O(min(n, m)) - Additional space used to store characters and their last occurrence indices in the map,
//                   where 'n' is the length of the string and 'm' is the size of the character set.

int lengthOfLongestSubstringOpt(string s)
{
    int n = s.length();
    int maxLength = 0;
    unordered_map<char, int> charAndIndex;
    int left = 0;

    // Iterate through the string with the right pointer
    for (int right = 0; right < n; right++)
    {
        // Check if the current character is not present in the map or its last occurrence is before the left boundary
        if (charAndIndex.count(s[right]) == 0 || charAndIndex[s[right]] < left)
        {
            // Update the last occurrence index of the current character and maximum length
            charAndIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        else
        {
            // Update the left boundary to the next index after the last occurrence of the current character
            left = charAndIndex[s[right]] + 1;
            charAndIndex[s[right]] = right;
        }
    }
    // Return the maximum length of the substring without repeating characters
    return maxLength;
}

// Main function
int main()
{
    // Output the length of the longest substring without repeating characters for both approaches
    cout << "Brute Force: " << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Optimized: " << lengthOfLongestSubstringOpt("abcabcbb") << endl;
    return 0;
}
