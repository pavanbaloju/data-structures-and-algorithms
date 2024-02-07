#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a word within a string.
// Intuition:
// - We iterate through the string and identify each word by spaces.
// - For each word, we reverse its characters in-place using the reverseWord function.
// - After reversing all words, we reverse the entire string to obtain the desired result.
// Approach:
// - Iterate through the string, tracking the start and end indices of each word.
// - Use the reverseWord function to reverse each word in-place.
// - After reversing all words, reverse the entire string.
// - Lastly, remove extra spaces and trailing spaces from the result.
// Time complexity: O(n), where n is the length of the input string.
//   - We iterate through the string once to reverse each word and once to reverse the entire string.
// Space complexity: O(1), constant space used.
void reverseWord(string &s, int start, int end)
{
    for (int i = start, j = end; i < j;)
    {
        swap(s[i++], s[j--]); // Swap characters from start to end
    }
}

// Function to reverse words in a string.
string reverseWords(string s)
{
    int count = 0; // Variable to count characters in a word
    // Iterate through the string
    for (int i = 0;; i++)
    {
        // Check for space or end of string
        if (s[i] == ' ' || i == s.size())
        {
            if (count > 0)
            {
                reverseWord(s, i - count, i - 1); // Reverse the word
                count = 0; // Reset character count
            }
        }
        else
        {
            count++; // Increment character count
        }
        if (i == s.size())
        {
            break; // Break loop at end of string
        }
    }
    reverseWord(s, 0, s.size() - 1); // Reverse the entire string

    string r = ""; // Result string
    // Iterate through the string to remove extra spaces
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (r != "" && r.back() != ' ')
            {
                r += ' '; // Add space if the last character is not already a space
            }
        }
        else
        {
            r += s[i]; // Add character to result string
        }
    }
    if (r.back() == ' ')
    {
        r.pop_back(); // Remove trailing space
    }
    return r; // Return the result string
}

int main()
{
    string s = "  the sky   is blue  "; // Input string
    cout << reverseWords(s) << "x"; // Output the reversed words
    return 0;
}
