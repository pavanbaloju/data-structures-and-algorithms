#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return an empty string. If there are multiple minimum window substrings, return any of them.

// Intuition:
// This problem can be solved efficiently using the sliding window technique.
// We maintain a window that expands towards the right as long as it contains all the characters required by t.
// When all characters are found, we shrink the window from the left until it's no longer valid.
// We keep track of the minimum window size and return the substring that satisfies the conditions.

// DSA Strategy/Pattern:
// Sliding Window

// Approach:
// Explanation1:
// 1. Create a function `isInT` to check if a character is present in the target string `t`.
// 2. Initialize counts of characters in `t` and the sliding window `window`.
// 3. Iterate through `t` and store character counts in the `tcount` map.
// 4. Initialize variables `have`, `need`, and `minWindowSize`.
// 5. Iterate through `s` using the end pointer.
// 6. Expand the window by adding characters to `window` and check if the current character meets its count requirement.
// 7. Shrink the window from the left until it's no longer valid.
// 8. Update `minWindowSize` and the indices of the minimum window substring if a smaller window is found.
// 9. Return the minimum window substring.


// Function to check if a character is present in the target string.
bool isInT(unordered_map<char, int> &tcount, char &ch)
{
    return tcount.find(ch) != tcount.end();
}

// Function to find the minimum window substring in s that contains all the characters in t.
string minWindow(string s, string t)
{
    // If t is empty, return an empty string.
    if (t == "")
        return "";

    // Initialize counts of characters in t and the sliding window.
    unordered_map<char, int> tcount, window;
    for (char ch : t)
        tcount[ch] += 1;

    // Initialize variables for counting characters in the window and tracking the minimum window size.
    int have = 0, need = tcount.size(), minWindowSize = INT_MAX;
    // Store the indices of the minimum window substring.
    vector<int> ans;

    // Initialize the left pointer of the window.
    int left = 0;
    // Iterate through the string using the right pointer.
    for (int right = 0; right < s.size(); right++)
    {
        // Expand the window by adding characters to the window map.
        window[s[right]] += 1;
        // Check if the current character in the window is in t and meets its count requirement.
        if (isInT(tcount, s[right]) && window[s[right]] == tcount[s[right]])
            have++;

        // Shrink the window from the left until the window is no longer valid.
        while (have == need)
        {
            // Update the minimum window size and its indices if a smaller window is found.
            if ((right - left + 1) < minWindowSize)
            {
                ans = {left, right};
                minWindowSize = right - left + 1;
            }

            // Remove the leftmost character from the window and update the count.
            window[s[left]] -= 1;
            if (isInT(tcount, s[left]) && window[s[left]] < tcount[s[left]])
                have--;

            // Move the left pointer to shrink the window.
            left++;
        }
    }

    // Return the minimum window substring.
    return minWindowSize != INT_MAX ? s.substr(ans[0], ans[1] - ans[0] + 1) : "";
}

// Approach:
// Explanation2:
// 1. Store the lengths of input strings.
// 2. If the length of `s` is less than `t`, return an empty string.
// 3. Initialize arrays to store counts of characters in `t` and the sliding window `window`.
// 4. Update the count of each character in `t`.
// 5. Initialize pointers and variables to track the minimum window substring.
// 6. Iterate through `s` using the right pointer.
// 7. Add the current character to `window` and update the count.
// 8. If all characters in `t` are found in the current window, shrink the window from the left until it's no longer valid.
// 9. Update the minimum window size and its start index.
// 10. Return the minimum window substring.

// Time Complexity: O(n + m) - Two passes through the input strings, where n is the length of s and m is the length of t.
// Space Complexity: O(1) - Constant space is used.

// Optimized function to find the minimum window substring.
string minWindowOpt(string s, string t)
{
    // Store the lengths of input strings.
    int ss = s.length(), ts = t.length();
    // If the length of s is less than t, return an empty string.
    if (ss < ts)
        return "";

    // Initialize arrays to store counts of characters in t and the sliding window.
    vector<int> tcount(128, 0), window(128, 0);
    // Update the count of each character in t.
    for (char &ch : t)
        tcount[ch]++;

    // Initialize pointers and variables to track the minimum window substring.
    int left = 0, start = -1, minLen = INT_MAX;
    int count = 0;

    // Iterate through the string using the right pointer.
    for (int right = 0; right < ss; right++)
    {
        // Add the current character to the window and update the count.
        window[s[right]]++;
        if (window[s[right]] <= tcount[s[right]])
            count++;

        // If all characters in t are found in the current window.
        if (count == ts)
        {
            // Shrink the window from the left until it is no longer valid.
            while (window[s[left]] > tcount[s[left]] || tcount[s[left]] == 0)
            {
                if (window[s[left]] > tcount[s[left]])
                    window[s[left]]--;
                left++;
            }

            // Update the minimum window size and its start index.
            int windowLen = right - left + 1;
            if (minLen > windowLen)
            {
                minLen = windowLen;
                start = left;
            }
        }
    }

    // If no valid window is found, return an empty string. Otherwise, return the minimum window substring.
    if (start == -1)
        return "";
    return s.substr(start, minLen);
}

// Main function
int main()
{
    // Test cases
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;   // Output: "BANC"
    cout << minWindowOpt("ADOBECODEBANC", "ABC") << endl; // Output: "BANC"
    return 0;
}
