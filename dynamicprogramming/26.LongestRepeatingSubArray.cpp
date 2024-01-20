#include <iostream>
#include <vector>
using namespace std;

int longest(int si, int ti, vector<int> &s, vector<int> &t, int count)
{
    if (si < 0 || ti < 0)
        return count;

    if (s[si] == t[ti])
        count = longest(si - 1, ti - 1, s, t, count + 1);

    count = max(count, max(longest(si, ti - 1, s, t, 0), longest(si - 1, ti, s, t, 0)));
    return count;
}

int findLength(vector<int>& s, vector<int>& t)
{
    int ss = s.size(), ts = t.size();
    return longest(ss - 1, ts - 1, s, t, 0);
}

int findLengthTable(vector<int>& s, vector<int>& t)
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

int findLengthOpt(vector<int>& s, vector<int>& t)
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
    vector<int> s{1, 2, 3, 2, 1}, t{3, 2, 1, 4, 7};
    cout << findLength(s, t) << endl;
    cout << findLengthTable(s, t) << endl;
    cout << findLengthOpt(s, t) << endl;
    return 0;
}