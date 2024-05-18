#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s)
{
    stack<int> stk; // Stack to store intermediate results
    int result = 0; // Final result
    int sign = 1;   // Current sign of the expression, initialized to positive

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (isdigit(c))
        {
            // Calculate the entire number and add it to the result
            int num = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            result += sign * num;
            --i; // Decrement i to compensate for the ++i in the loop
        }
        else if (c == '+')
        {
            sign = 1; // Update sign to positive
        }
        else if (c == '-')
        {
            sign = -1; // Update sign to negative
        }
        else if (c == '(')
        {
            // Push the current result and sign onto the stack
            stk.push(result);
            stk.push(sign);
            // Reset result and sign for the new sub-expression
            result = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            // Calculate the result for the sub-expression
            int prevSign = stk.top();
            stk.pop();
            int prevResult = stk.top();
            stk.pop();
            result = prevResult + (prevSign * result);
        }
    }

    return result;
}

int main()
{
    // Example expression
    string expr = "1 + (2 - 3)";

    // Calculate the result
    int result = calculate(expr);

    // Print the result
    cout << "Result: " << result << endl;

    return 0;
}
