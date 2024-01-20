#include <iostream>
#include <vector>
using namespace std;

int longest(int si, int ti, string &s, string &t, int count)
{
    if (si < 0 || ti < 0)
        return count;

    if (s[si] == t[ti])
        count = longest(si - 1, ti - 1, s, t, count + 1);

    count = max(count, max(longest(si, ti - 1, s, t, 0), longest(si - 1, ti, s, t, 0)));
    return count;
}

int longestCommonSubstring(string s, string t)
{
    int ss = s.size(), ts = t.size();
    return longest(ss - 1, ts - 1, s, t, 0);
}

int longestCommonSubstringTable(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, 0));
    int res = 0;

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                dp[si][ti] = dp[si - 1][ti - 1] + 1;
                res = max(res, dp[si][ti]);
            }
            else
                dp[si][ti] = 0;
        }
    }
    return res;
}

int longestCommonSubstringOpt(string s, string t)
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

int main()
{
    cout << longestCommonSubstring("ababacde", "edcababa") << endl;
    cout << longestCommonSubstringTable("abcde", "abce") << endl;
    cout << longestCommonSubstringOpt("abcde", "abce") << endl;
    return 0;
}