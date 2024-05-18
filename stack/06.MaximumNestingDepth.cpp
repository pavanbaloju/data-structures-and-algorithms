#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Approach 1: Using a stack
int maxNestingDepthUsingStack(const string &s)
{
    stack<char> stk;  // Stack to keep track of parentheses
    int maxDepth = 0; // To keep track of the maximum depth

    for (char c : s)
    {
        if (c == '(')
        {
            stk.push(c); // Push opening parenthesis onto the stack
            if (stk.size() > maxDepth)
            { // Update maxDepth if current stack size is greater
                maxDepth = stk.size();
            }
        }
        else if (c == ')')
        {
            stk.pop(); // Pop closing parenthesis from the stack
        }
    }

    return maxDepth; // Return the maximum depth encountered
}

// Approach 2: Using a simple depth counter
int maxNestingDepthUsingCounter(const string &s)
{
    int currentDepth = 0; // To keep track of the current depth
    int maxDepth = 0;     // To keep track of the maximum depth

    for (char c : s)
    {
        if (c == '(')
        {
            currentDepth++; // Increase the depth for an opening parenthesis
            if (currentDepth > maxDepth)
            {
                maxDepth = currentDepth; // Update the maximum depth if current depth is greater
            }
        }
        else if (c == ')')
        {
            currentDepth--; // Decrease the depth for a closing parenthesis
        }
    }

    return maxDepth; // Return the maximum depth encountered
}

int main()
{
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    // Using the stack approach
    int depthUsingStack = maxNestingDepthUsingStack(s);
    cout << "The nesting depth of the string using stack is: " << depthUsingStack << endl;

    // Using the counter approach
    int depthUsingCounter = maxNestingDepthUsingCounter(s);
    cout << "The nesting depth of the string using counter is: " << depthUsingCounter << endl;

    return 0;
}
