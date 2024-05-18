#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minAddToMakeValidWithStack(string s)
{
    stack<char> stk;   // Stack to store unmatched parentheses
    int additions = 0; // Count of additions needed

    // Iterate through the string
    for (char c : s)
    {
        if (c == '(')
        {
            stk.push(c); // Push opening parenthesis onto the stack
        }
        else
        {
            // If the current character is a closing parenthesis
            if (!stk.empty() && stk.top() == '(')
            {
                // If there's a matching opening parenthesis on the stack, pop it
                stk.pop();
            }
            else
            {
                // If there's no matching opening parenthesis, we need to add one
                additions++;
            }
        }
    }

    // Add the remaining unmatched opening parentheses to the count of additions needed
    additions += stk.size();

    return additions;
}

int minAddToMakeValidWithoutStack(string s)
{
    int openCount = 0; // Count of unmatched opening parentheses
    int additions = 0; // Count of additions needed

    // Iterate through the string
    for (char c : s)
    {
        if (c == '(')
        {
            openCount++; // Increment the count of unmatched opening parentheses
        }
        else
        {
            // If the current character is a closing parenthesis
            if (openCount > 0)
            {
                // If there's a matching opening parenthesis, decrement the count of unmatched opening parentheses
                openCount--;
            }
            else
            {
                // If there's no matching opening parenthesis, we need to add one
                additions++;
            }
        }
    }

    // Add the remaining unmatched opening parentheses to the count of additions needed
    additions += openCount;

    return additions;
}

int main()
{
    // Example string
    string s = "())";

    // Calculate the minimum number of additions needed with stack
    int minAddWithStack = minAddToMakeValidWithStack(s);

    // Calculate the minimum number of additions needed without stack
    int minAddWithoutStack = minAddToMakeValidWithoutStack(s);

    // Print the results
    cout << "Minimum number of additions needed with stack: " << minAddWithStack << endl;
    cout << "Minimum number of additions needed without stack: " << minAddWithoutStack << endl;

    return 0;
}
