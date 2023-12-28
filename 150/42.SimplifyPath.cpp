#include <iostream>
#include <stack>
#include <vector>

using namespace std;
string simplifyPath(string path)
{

    stack<string> st;
    string res;

    for (int i = 0; i < path.size(); ++i)
    {
        if (path[i] == '/')
            continue;
        string curr;
        while (i < path.size() && path[i] != '/')
        {
            curr += path[i];
            ++i;
        }
        if (curr == ".")
            continue;
        else if (curr == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(curr);
    }

    while (!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }
    if (res.size() == 0)
        return "/";

    return res;
}

int main()
{
    cout << simplifyPath("/") << endl;
    cout << simplifyPath("/ab/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("") << endl;

    return 0;
}