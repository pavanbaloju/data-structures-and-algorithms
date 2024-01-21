#include <iostream>
#include <vector>
using namespace std;

bool isAllStars(string &s, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (s[j] != '*')
            return false;
    }
    return true;
}

bool isMatchMemo(int si, int pi, string &s, string &p, vector<vector<int>> &dp)
{
    if (si < 0 && pi < 0)
        return true;
    if (pi < 0 && si >= 0)
        return false;
    if (si < 0 && pi >= 0)
        return isAllStars(p, pi);

    if (dp[si][pi] != -1)
        return dp[si][pi];

    if (s[si] == p[pi] || p[pi] == '?')
        return dp[si][pi] = isMatchMemo(si - 1, pi - 1, s, p, dp);

    if (p[pi] == '*')
        return dp[si][pi] = isMatchMemo(si - 1, pi, s, p, dp) || isMatchMemo(si, pi - 1, s, p, dp);

    return dp[si][pi] = false;
}

bool isMatch(string s, string p)
{
    int ss = s.size(), ps = p.size();
    vector<vector<int>> dp(ss, vector<int>(ps, -1));
    return isMatchMemo(ss - 1, ps - 1, s, p, dp);
}

bool isMatchTable(string s, string p)
{
    int ss = s.size(), ps = p.size();
    vector<vector<bool>> dp(ss + 1, vector<bool>(ps + 1, false));

    dp[0][0] = true;

    for (int si = 1; si <= ss; si++)
        dp[si][0] = false;

    for (int pi = 1; pi <= ps; pi++)
        dp[0][pi] = isAllStars(p, pi - 1);

    for (int si = 1; si <= ss; si++)
    {
        for (int pi = 1; pi <= ps; pi++)
        {
            if (s[si - 1] == p[pi - 1] || p[pi - 1] == '?')
            {
                dp[si][pi] = dp[si - 1][pi - 1];
            }
            else
            {
                if (p[pi - 1] == '*')
                {
                    dp[si][pi] = dp[si - 1][pi] || dp[si][pi - 1];
                }
            }
        }
    }
    return dp[ss][ps];
}

bool isMatchOpt(string s, string p)
{
    int ss = s.size(), ps = p.size();
    vector<bool> prev(ps + 1, false), curr(ps + 1, false);

    prev[0] = true;

    for (int pi = 1; pi <= ps; pi++)
        prev[pi] = isAllStars(p, pi - 1);

    for (int si = 1; si <= ss; si++)
    {
        for (int pi = 1; pi <= ps; pi++)
        {
            if (s[si - 1] == p[pi - 1] || p[pi - 1] == '?')
            {
                curr[pi] = prev[pi - 1];
            }
            else
            {
                if (p[pi - 1] == '*')
                {
                    curr[pi] = prev[pi] || curr[pi - 1];
                }
                else
                {
                    curr[pi] = false;
                }
            }
        }
        prev = curr;
    }
    return prev[ps];
}

int main()
{
    cout << isMatch("abdefcd", "ab*cd") << endl;
    cout << isMatchTable("abdefcd", "ab*cd") << endl;
    cout << isMatchOpt("abdefcd", "ab*cd") << endl;
    return 0;
}