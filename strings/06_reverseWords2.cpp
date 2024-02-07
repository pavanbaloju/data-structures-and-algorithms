#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a word within a string.
// Intuition:
// To reverse a word within a string, we iterate through the characters of the word and swap the characters from start to end.
// Approach:
// We use two pointers, 'start' and 'end', which initially point to the start and end of the word, respectively.
// We iterate through the characters of the word using these pointers and swap the characters until they meet in the middle.
void reverseWord(string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
        swap(s[i], s[j]); // Swap characters from start to end
    }
}

// Function to reverse words in a string.
// Intuition:
// To reverse words in a string, we first reverse each individual word within the string.
// After reversing each word, we reverse the entire string to restore the original order of words.
// Approach:
// We iterate through the string, identifying each word by finding spaces.
// For each word, we use the reverseWord function to reverse the characters within the word.
// Finally, we return the modified string containing the reversed words.
string reverseWords(string s) {
    int wordStart = 0; // Starting index of the current word
    int wordLength = 0; // Length of the current word

    // Iterate through the string
    for (int i = 0; i <= s.size(); ++i) {
        // Check for space or end of string
        if (i == s.size() || s[i] == ' ') {
            // If there is a valid word
            if (wordLength > 0) {
                reverseWord(s, wordStart, i - 1); // Reverse the current word
                wordLength = 0; // Reset the word length
            }
            wordStart = i + 1; // Update the start index of the next word
        } else {
            ++wordLength; // Increment the word length
        }
    }

    return s; // Return the modified string
}

int main() {
    string s = "Let's take LeetCode contest"; // Input string
    cout << reverseWords(s) << "x"; // Output the modified string
    return 0;
}
