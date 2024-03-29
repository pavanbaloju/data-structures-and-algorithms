#include <iostream>
#include <vector>
using namespace std;

int longest(int si, int ti, string &s, string &t, vector<vector<int>> &dp)
{
    if (si < 0 || ti < 0)
        return 0;

    if (dp[si][ti] != -1)
        return dp[si][ti];

    if (s[si] == t[ti])
        return dp[si][ti] = 1 + longest(si - 1, ti - 1, s, t, dp);

    return dp[si][ti] = 0 + max(longest(si - 1, ti, s, t, dp), longest(si, ti - 1, s, t, dp));
}

int longestCommonSubsequence(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss, vector<int>(ts, -1));
    return longest(ss - 1, ts - 1, s, t, dp);
}

int longestCommonSubsequenceTableUtil(string s, string t, vector<vector<int>> &dp)
{
    int ss = s.size(), ts = t.size();

    for (int si = 0; si <= ss; si++)
    {
        for (int ti = 0; ti <= ts; ti++)
        {
            if (si == 0 || ti == 0)
            {
                dp[si][ti] = 0;
            }
            else if (s[si - 1] == t[ti - 1])
            {
                dp[si][ti] = 1 + dp[si - 1][ti - 1];
            }
            else
            {
                dp[si][ti] = 0 + max(dp[si - 1][ti], dp[si][ti - 1]);
            }
        }
    }

    return dp[ss][ts];
}
int longestCommonSubsequenceTable(string s, string t)
{
    int ss = s.size(), ts = t.size();
    // +1 to shift base case ind == -1 to ind == 0
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, -1));
    return longestCommonSubsequenceTableUtil(s, t, dp);
}

int longestCommonSubsequenceOpt(string s, string t)
{
    int ss = s.size();
    int ts = t.size();
    vector<int> prev(ts + 1, 0), cur(ts + 1, 0);
    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
                cur[ti] = 1 + prev[ti - 1];
            else
                cur[ti] = max(prev[ti], cur[ti - 1]);
        }
        prev = cur;
    }

    return prev[ts];
}

string getLCS(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, -1));
    int len = longestCommonSubsequenceTableUtil(s, t, dp);

    string lcs = string(len, '$');
    int si = ss, ti = ts;
    while (si > 0 && ti > 0)
    {
        if (s[si - 1] == t[ti - 1])
        {
            lcs[--len] = s[si - 1];
            si--;
            ti--;
        }
        else if (dp[si - 1] > dp[ti - 1])
        {
            si--;
        }
        else
        {
            ti--;
        }
    }
    return lcs;
}

int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequenceTable("brute", "groot") << endl;
    cout << longestCommonSubsequenceOpt("abcde", "ace") << endl;
    cout << getLCS("abcde", "ace") << endl;
    return 0;
}