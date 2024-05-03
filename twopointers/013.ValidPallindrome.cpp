#include <iostream>
#include <cctype> // For isalnum
using namespace std;

// Problem Statement:
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Intuition:
// We can use two pointers to traverse the string from both ends, skipping non-alphanumeric characters.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// Explanation:
// 1. Initialize two pointers, 'i' and 'j', at the beginning and end of the string respectively.
// 2. Use a while loop to iterate until 'i' is less than or equal to 'j'.
// 3. Inside the loop, skip non-alphanumeric characters using the isalnum function.
// 4. Compare characters at indices 'i' and 'j' ignoring case using the tolower function.
// 5. If the characters don't match, return false indicating that the string is not a palindrome.
// 6. If all characters match, move 'i' to the next alphanumeric character and 'j' to the previous alphanumeric character.
// 7. If the loop exits without returning false, return true indicating that the string is a palindrome.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1).

bool isPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (isalnum(s[i]) && isalnum(s[j]))
        {
            if (tolower(s[i++]) != tolower(s[j--]))
            {
                return false;
            }
        }
        else if (!isalnum(s[i]))
        {
            i++;
        }
        else if (!isalnum(s[j]))
        {
            j--;
        }
    }
    return true;
}

int main()
{
    // Test cases
    cout << isPalindrome("race car") << endl;   // Output: 1 (true)
    cout << isPalindrome("race a car") << endl; // Output: 0 (false)
    cout << isPalindrome(" ") << endl;          // Output: 1 (true)
    return 0;
}
