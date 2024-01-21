#include <iostream>
#include <vector>
using namespace std;

int minDistanceMemo(int si, int ti, string s, string t, vector<vector<int>> &dp)
{
    if (si < 0)
        return ti + 1;
    if (ti < 0)
        return si + 1;

    if (dp[si][ti] != -1)
        return dp[si][ti];

    if (s[si] == t[ti])
        return minDistanceMemo(si - 1, ti - 1, s, t, dp);

    return 1 + min(minDistanceMemo(si, ti - 1, s, t, dp), min(minDistanceMemo(si - 1, ti, s, t, dp), minDistanceMemo(si - 1, ti - 1, s, t, dp)));
}

int minDistance(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, -1));
    return minDistanceMemo(ss - 1, ts - 1, s, t, dp);
}

int minDistanceTable(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<vector<int>> dp(ss + 1, vector<int>(ts + 1, -1));

    for (int ti = 0; ti <= ts; ti++)
    {
        dp[0][ti] = ti;
    }
    for (int si = 0; si <= ss; si++)
    {
        dp[si][0] = si;
    }

    for (int si = 1; si <= ss; si++)
    {
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                dp[si][ti] = dp[si - 1][ti - 1];
            }
            else
            {
                dp[si][ti] = 1 + min(dp[si][ti - 1], min(dp[si - 1][ti], dp[si - 1][ti - 1]));
            }
        }
    }
    return dp[ss][ts];
}

int minDistanceOpt(string s, string t)
{
    int ss = s.size(), ts = t.size();
    vector<int> prev(ts + 1, 0), curr(ts + 1, 0);

    for (int ti = 0; ti <= ts; ti++)
    {
        prev[ti] = ti;
    }

    for (int si = 1; si <= ss; si++)
    {
        curr[0] = si;
        for (int ti = 1; ti <= ts; ti++)
        {
            if (s[si - 1] == t[ti - 1])
            {
                curr[ti] = prev[ti - 1];
            }
            else
            {
                curr[ti] = 1 + min(curr[ti - 1], min(prev[ti], prev[ti - 1]));
            }
        }
        prev = curr;
    }
    return prev[ts];
}

int main()
{
    string str1 = "horse";
    string str2 = "ros";
    cout << minDistance(str1, str2) << endl;
    cout << minDistanceTable(str1, str2) << endl;
    cout << minDistanceOpt(str1, str2) << endl;
    return 0;
}
