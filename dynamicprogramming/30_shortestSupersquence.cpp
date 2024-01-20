#include <iostream>
#include <vector>
using namespace std;

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

string shortestCommonSupersequence(string s, string t)
{

    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, -1));
    int len = longestCommonSubsequenceTableUtil(s, t, dp);
    int i = ss;
    int j = ts;
    int index = ss + ts - len - 1;
    string ans = string(ss + ts - len, '$');

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[index--] = s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans[index--] = s[i - 1];
            i--;
        }
        else
        {
            ans[index--] = t[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        ans[index--] = s[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans[index--] = t[j - 1];
        j--;
    }

    return ans;
}

int main()
{

    string s1 = "brute";
    string s2 = "groot";

    cout << "The Longest Common Supersequence is " << shortestCommonSupersequence(s1, s2);
}