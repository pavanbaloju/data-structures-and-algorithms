#include <iostream>
#include <stack>
using namespace std;

// Problem Statement:
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

// Intuition:
// Use a stack to keep track of opening brackets encountered in the string. Whenever a closing bracket is encountered, check if it matches the top of the stack. If it does, pop the stack; otherwise, the string is invalid.

// DSA Strategy:
// Stack

// Approach:
// 1. Create an empty stack to store opening brackets encountered.
// 2. Iterate through each character in the string:
//    a. If the character is an opening bracket ('(', '{', '['), push it onto the stack.
//    b. If the character is a closing bracket (')', '}', ']'):
//       i. If the stack is empty, return false (invalid).
//       ii. If the top of the stack matches the corresponding opening bracket for the current closing bracket, pop the stack.
//       iii. Otherwise, return false (invalid).
// 3. After iterating through the string, if the stack is empty, return true (valid); otherwise, return false (invalid).

// Time Complexity: O(n), where n is the length of the input string.
// Space Complexity: O(n), where n is the length of the input string (for the stack).

// Function to check the validity of brackets in a string
bool isValid(string s)
{
    stack<char> st; // Stack to store opening brackets encountered
    // Iterate through each character in the string
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        { // If the character is an opening bracket, push it onto the stack
            st.push(c);
        }
        else if (!st.empty() && ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')))
        {
            // If the character is a closing bracket and matches the top of the stack, pop the stack
            st.pop();
        }
        else
        {
            // If the character is a closing bracket and doesn't match the top of the stack, return false (invalid)
            return false;
        }
    }
    // Return true if the stack is empty (all opening brackets have been matched)
    return st.empty();
}

// Main function
int main()
{
    // Test the isValid function with a sample string
    cout << isValid("[]"); // Output: true (valid brackets)
    return 0;
}
