#include <iostream>
#include <cctype>
using namespace std;

bool isSubsequence(string s, string t)
{
    if (s.size() > t.size())
    {
        return false;
    }
    int si = 0, ti = 0;
    while (si < s.size() && ti < t.size())
    {
        if (s[si] == t[ti])
        {
            si++;
            ti++;
        }
        else
        {
            ti++;
        }
    }
    return si == s.size();
}

int main()
{
    cout << isSubsequence("abc", "ahbgdc") << endl;
}