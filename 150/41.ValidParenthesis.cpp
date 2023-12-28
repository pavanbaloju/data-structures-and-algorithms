#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty() 
            || (ch == ')' && st.top() != '(') 
            || (ch == '}' && st.top() != '{') 
            || (ch == ']' && st.top() != '['))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    cout << isValid("()()()") << endl;
    cout << isValid("((()))()") << endl;
    cout << isValid("()())))") << endl;
    cout << isValid("(((()()") << endl;
    cout << isValid("(((()((") << endl;
    cout << isValid(")((()()") << endl;

    return 0;
}