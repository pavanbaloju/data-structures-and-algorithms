#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//using stack
int minParentheses(string p)
{
    stack<int> stk;
    int ans = 0;

    for (int i = 0; i < p.length(); ++i)
    {

        if (p[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            if (!stk.empty())
            {
                stk.pop();
            }
            else
            {
                ans += 1;
            }
        }
    }
    ans += stk.size();

    return ans;
}

int minAddToMakeValid(string s)
{
    int left = 0, right = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            left++;
        }
        else
        {
            if (left > 0)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
    }
    return left + right;
}

int main()
{
    string s = "((()";
    cout << minAddToMakeValid(s) << "\n";

    s = ")))";
    cout << minAddToMakeValid(s) << "\n";

    s = "))()";
    cout << minParentheses(s) << "\n";
    return 0;
}
