#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int calculate(string s)
{
    int n = s.size();
    int multiplier = 1;

    int res = 0;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            int curr = 0;
            while (i < n && isdigit(s[i]))
            {
                curr = curr * 10 + (s[i++] - '0');
            }
            i--;
            res += curr * multiplier;
        }
        else if (s[i] == '+')
        {
            multiplier = 1;
        }
        else if (s[i] == '-')
        {
            multiplier = -1;
        }
        else if (s[i] == '(')
        {
            st.push({res, multiplier});

            res = 0;
            multiplier = 1;
        }
        else if (s[i] == ')')
        {
            pair<int, int> prev = st.top();
            st.pop();
            res *= prev.second;
            res += prev.first;
        }
    }
    return res;
}

int main()
{
    string s = "5 - (1 + (1 - 1))";
    cout << calculate(s) << endl;
    return 0;
}