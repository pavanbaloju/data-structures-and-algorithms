#include <iostream>
#include <vector>
using namespace std;

bool isPallindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int solve(int i, int &n, string &s, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPallindrome(i, j, s))
        {
            mini = min(mini, 1 + solve(j + 1, n, s, dp));
        }
    }
    return dp[i] = mini;
}

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solve(0, n, s, dp) - 1;
}

int minCutTable(string str)
{
    int n = str.size();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPallindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[0] - 1;
}

int main()
{
    string s = "BABABCBADCEDE";
    cout << minCut(s) << endl;
    return 0;
}