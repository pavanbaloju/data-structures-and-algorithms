#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s)
{
    stack<int> numStack;    // Stack to store the number of repetitions
    stack<string> strStack; // Stack to store the decoded strings
    string currentStr;      // Current decoded string
    int num = 0;            // Current number of repetitions

    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0'); // Calculate the number of repetitions
        }
        else if (isalpha(c))
        {
            currentStr += c; // Append the character to the current string
        }
        else if (c == '[')
        {
            numStack.push(num);        // Push the current number of repetitions to the stack
            strStack.push(currentStr); // Push the current string to the stack
            currentStr = "";           // Reset the current string
            num = 0;                   // Reset the current number of repetitions
        }
        else if (c == ']')
        {
            int k = numStack.top();          // Get the number of repetitions from the stack
            numStack.pop();                  // Pop the number of repetitions
            string prevStr = strStack.top(); // Get the previous string from the stack
            strStack.pop();                  // Pop the previous string
            // Repeat the current string k times and append it to the previous string
            for (int i = 0; i < k; ++i)
            {
                prevStr += currentStr;
            }
            currentStr = prevStr; // Update the current string
        }
    }

    return currentStr; // Return the decoded string
}

int main()
{
    // Example encoded string
    string encodedString = "3[a]2[bc]";

    // Decode the encoded string
    string decodedString = decodeString(encodedString);

    // Print the decoded string
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
