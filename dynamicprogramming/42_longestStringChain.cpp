#include <iostream>
#include <vector>
using namespace std;

bool possible(string &s1, string &s2)
{
    int s1s = s1.size(), s2s = s2.size();
    if (s1s != s2s + 1)
        return false;

    int first = 0, second = 0;
    ;
    while (first < s1s)
    {
        if (second < s2s && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    return first == s1s && second == s2s;
}

static bool sorter(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), sorter);
    int n = words.size();
    vector<int> dp(n, 1);
    int maxi = -1;

    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (possible(words[ind], words[prev]))
            {
                dp[ind] = max(dp[ind], dp[prev] + 1);
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(words) << endl;
    return 0;
}