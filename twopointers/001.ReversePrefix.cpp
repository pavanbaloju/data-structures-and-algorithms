#include <string>
using namespace std;

// Problem Statement:
// Given a string 'word' and a character 'ch', reverse the segment of 'word' starting from the beginning of the string up to the first occurrence of 'ch' (inclusive).

// Intuition:
// We can use a two-pointer approach to find the index of the first occurrence of 'ch' and then reverse the segment from the beginning of the string up to that index.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// 1. Initialize 'start' and 'end' pointers to 0.
// 2. Iterate through the string to find the index of the first occurrence of 'ch':
//    a. When the character at the current index is equal to 'ch', update 'end' to the current index and break from the loop.
// 3. Reverse the segment of the string from index 0 to the index of 'ch' (inclusive) using two pointers:
//    a. While 'start' is less than 'end':
//       i. Swap characters at indices 'start' and 'end'.
//       ii. Increment 'start' and decrement 'end'.
// 4. Return the modified 'word' after reversing the segment.
// 5. Time Complexity: O(n) - We iterate through the string once to find the index of 'ch' and reverse the segment.
// 6. Space Complexity: O(1) - Constant space is used.

string reversePrefix(string word, char ch) {
    int start = 0, end = 0;

    // Find the index of the first occurrence of the character 'ch'
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == ch) {
            end = i;
            break;
        }
    }

    // Reverse the segment from index 0 to the index of 'ch' (inclusive)
    while (start < end) {
        // Swap characters at indices 'start' and 'end'
        swap(word[start++], word[end--]);
    }

    // Return the modified word after reversing the segment
    return word;
}

// Example usage:
int main() {
    string word = "abcdefd";
    char ch = 'd';
    string result = reversePrefix(word, ch);
    return 0;
}
