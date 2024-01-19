#include <iostream>
#include <vector>
using namespace std;

bool isPallindrome(string &s, int start, int end)
{
    for (int k = 0; k < (end - start + 1) / 2; k++)
    {
        if (s[start + k] != s[end - k])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{
    int n = s.size();
    int maxLen = 0;
    int lstart = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPallindrome(s, i, j))
            {
                int len = j - i + 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    lstart = i;
                }
            }
        }
    }
    return s.substr(lstart, maxLen);
}

string longestPalindromeTable(string str)
{
    int n = str.size();

    // dp[start][end]
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1;
    for (int start = 0; start < n; ++start)
        dp[start][start] = true;

    int lstart = 0;
    for (int start = 0; start < n - 1; ++start)
    {
        int end = start + 1;
        if (str[start] == str[end])
        {
            dp[start][end] = true;
            lstart = start;
            maxLength = 2;
        }
    }

    for (int len = 2; len <= n; ++len)
    {
        for (int start = 0; start < n - len + 1; ++start)
        {
            int end = start + len - 1;
            if (dp[start + 1][end - 1] && str[start] == str[end])
            {
                dp[start][end] = true;
                if (len > maxLength)
                {
                    lstart = start;
                    maxLength = len;
                }
            }
        }
    }
    return str.substr(lstart, maxLength);
}

int pallindromeLen(int i, int j, string s)
{
    int left = i;
    int right = j;

    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return right - left - 1;
}

string longestPalindromeOpt(string s)
{
    int lstart = 0, lend = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int oddLength = pallindromeLen(i, i, s);
        if (oddLength > lend - lstart + 1)
        {
            int dist = oddLength / 2;
            lstart = i - dist;
            lend = i + dist;
        }

        int evenLength = pallindromeLen(i, i + 1, s);
        if (evenLength > lend - lstart + 1)
        {
            int dist = (evenLength / 2) - 1;
            lstart = i - dist;
            lend = i + 1 + dist;
        }
    }
    return s.substr(lstart, lend - lstart + 1);
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    cout << longestPalindromeTable(s) << endl;
    cout << longestPalindromeOpt(s) << endl;
    return 0;
}