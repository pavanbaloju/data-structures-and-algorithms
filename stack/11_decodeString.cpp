#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ']')
        {
            st.push(s[i]);
        }
        else
        {
            string subStr = "";
            while (st.top() != '[')
            {
                subStr = st.top() + subStr;
                st.pop();
            }
            st.pop();

            string num = "";
            while (!st.empty() && isdigit(st.top()))
            {
                num = st.top() + num;
                st.pop();
            }
            int k = stoi(num);
            while (k--)
            {
                for (char c : subStr)
                    st.push(c);
            }
        }
    }
    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main()
{
    cout << decodeString("3[a2[c]]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}