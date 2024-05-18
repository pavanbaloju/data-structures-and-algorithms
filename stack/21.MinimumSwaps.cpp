#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minSwapsWithStack(string s)
{
    int n = s.length();
    int openCount = 0; // Count of opening brackets
    int swaps = 0;     // Number of swaps needed

    // Iterate through the string
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '[')
        {
            openCount++; // Increment the count of opening brackets
        }
        else
        {
            // If the current bracket is a closing bracket
            if (openCount > 0)
            {
                // If there are unmatched opening brackets
                swaps += i - openCount + 1; // Calculate the number of swaps needed to bring the closing bracket to the correct position
                openCount--;                // Decrement the count of unmatched opening brackets
            }
        }
    }

    return swaps; // Return the total number of swaps needed
}

int minSwapsWithoutStack(string s)
{
    int n = s.length();
    int openCount = 0; // Count of opening brackets
    int unmatched = 0; // Count of unmatched closing brackets
    int swaps = 0;     // Number of swaps needed

    // Iterate through the string
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '[')
        {
            openCount++; // Increment the count of opening brackets
        }
        else
        {
            // If the current bracket is a closing bracket
            if (openCount > 0)
            {
                // If there are unmatched opening brackets
                openCount--; // Decrement the count of unmatched opening brackets
            }
            else
            {
                // If there are no unmatched opening brackets, increment the count of unmatched closing brackets
                unmatched++;
            }
        }
    }

    // Calculate the number of swaps needed
    swaps = (unmatched + 1) / 2;

    return swaps; // Return the total number of swaps needed
}

int main()
{
    // Example string
    string s = "[][]][][";

    // Calculate the minimum number of swaps needed with stack
    int minSwapsWithStackNeeded = minSwapsWithStack(s);

    // Calculate the minimum number of swaps needed without stack
    int minSwapsWithoutStackNeeded = minSwapsWithoutStack(s);

    // Print the results
    cout << "Minimum number of swaps needed with stack: " << minSwapsWithStackNeeded << endl;
    cout << "Minimum number of swaps needed without stack: " << minSwapsWithoutStackNeeded << endl;

    return 0;
}
