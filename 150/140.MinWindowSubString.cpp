#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isInT(unordered_map<char, int> &tcount, char &ch)
{
    return tcount.find(ch) != tcount.end();
}

string minWindow(string s, string t)
{
    if (t == "")
        return "";

    unordered_map<char, int> tcount, window;

    for (char ch : t)
        tcount[ch] += 1;

    int have = 0, need = tcount.size(), minWindowSize = INT_MAX;
    vector<int> ans;

    int left = 0;
    for (int right = 0; right < s.size(); right++)
    {
        window[s[right]] += 1;
        if (isInT(tcount, s[right]) && window[s[right]] == tcount[s[right]])
            have++;

        while (have == need)
        {
            if ((right - left + 1) < minWindowSize)
            {
                ans = {left, right};
                minWindowSize = right - left + 1;
            }

            window[s[left]] -= 1;
            if (isInT(tcount, s[left]) && window[s[left]] < tcount[s[left]])
                have--;

            left++;
        }
    }

    return minWindowSize != INT_MAX ? s.substr(ans[0], ans[1] - ans[0] + 1) : "";
}

string minWindowOpt(string s, string t)
{
    int ss = s.length();
    int ts = t.length();
    if (ss < ts)
        return "";

    vector<int> tcount(128, 0), window(128, 0);

    for (char &ch : t)
        tcount[ch]++;

    int left = 0, start = -1, minLen = INT_MAX;
    int count = 0;
    for (int right = 0; right < ss; right++)
    {
        window[s[right]]++;

        if (window[s[right]] <= tcount[s[right]])
            count++;

        if (count == ts)
        {
            while (window[s[left]] > tcount[s[left]] || tcount[s[left]] == 0)
            {
                if (window[s[left]] > tcount[s[left]])
                    window[s[left]]--;
                left++;
            }

            int windowLen = right - left + 1;
            if (minLen > windowLen)
            {
                minLen = windowLen;
                start = left;
            }
        }
    }
    if (start == -1)
        return "";
    return s.substr(start, minLen);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindowOpt("ADOBECODEBANC", "ABC") << endl;
    return 0;
}