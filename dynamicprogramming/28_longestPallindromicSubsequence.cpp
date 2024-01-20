#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s, string t)
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

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return longestCommonSubsequence(s, t);
}
int minInsertions(string s)
{
    return s.size() - longestPalindromeSubsequence(s);
}

int main()
{
    cout << minInsertions("mbadm") << endl;
    return 0;
}