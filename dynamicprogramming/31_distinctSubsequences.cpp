#include <iostream>
#include <vector>
using namespace std;

const int prime = 1e9 + 7;

int numDistinctUtil(int si, int ti, string &s, string &t, vector<vector<int>> &dp)
{
    if (ti < 0)
        return 1;
    if (si < 0)
        return 0;

    if (dp[si][ti] != -1)
        return dp[si][ti];

    if (s[si] == t[ti])
        return numDistinctUtil(si - 1, ti - 1, s, t, dp) + numDistinctUtil(si - 1, ti, s, t, dp);

    return numDistinctUtil(si - 1, ti, s, t, dp);
}

int numDistinct(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss, vector<int>(ts, -1));
    return numDistinctUtil(ss - 1, ts - 1, s, t, dp);
}

int numDistinctTable(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, 0));

    for (int si = 0; si < ss; si++)
    {
        dp[si][0] = 1;
    }

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                dp[si][ti] = (dp[si - 1][ti - 1] + dp[si - 1][ti]) % prime;
            }
            else
            {
                dp[si][ti] = dp[si - 1][ti];
            }
        }
    }

    return dp[ss][ts];
}

int numDistinctOpt(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<int> prev(ts + 1, 0), curr(ts + 1, 0);

    prev[0] = curr[0] = 1;

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                curr[ti] = (prev[ti - 1] + prev[ti]) % prime;
            }
            else
            {
                curr[ti] = prev[ti];
            }
        }
        prev = curr;
    }

    return prev[ts];
}

int numDistinctOpt2(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<int> dp(ts + 1, 0);

    dp[0] = 1;

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = ts; ti > 0; ti--)
        {
            if (s[si - 1] == t[ti - 1])
            {
                dp[ti] = (dp[ti - 1] + dp[ti]) % prime;
            }
        }
    }

    return dp[ts];
}

int main()
{
    cout << numDistinct("rabbbit", "rabbit") << endl;
    cout << numDistinctTable("babgbag", "bag") << endl;
    cout << numDistinctOpt("babgbag", "bag") << endl;
    cout << numDistinctOpt2("babgbag", "bag") << endl;
    return 0;
}