#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string s : tokens)
    {
        if (s.size() > 1 || isdigit(s[0]))
        {
            st.push(stoi(s));
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (s[0])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens);
    return 0;
}