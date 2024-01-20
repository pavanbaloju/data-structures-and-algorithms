#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubstring(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<int> prev(ts + 1, 0), curr(ts + 1, 0);
    int res = 0;

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                curr[ti] = prev[ti - 1] + 1;
                res = max(res, curr[ti]);
            }
            else
                curr[ti] = 0;
        }
        prev = curr;
    }
    return res;
}

int longestPalindromeSubstr(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return longestCommonSubstring(t, s);
}


int main()
{
    string s = "babad";
    cout << longestPalindromeSubstr(s) << endl;
    return 0;
}