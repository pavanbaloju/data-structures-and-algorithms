#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> visited;
    int maxLen = 0, currLen = 0;
    for (int i = 0, j = 0; j < s.size();)
    {
        auto it = visited.find(s[j]);
        if (it == visited.end())
        {
            if (j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
            }
            visited.insert(s[j++]);
        }
        else
        {
            visited.erase(s[i]);
            i++;
        }
    }
    return maxLen;
}
int lengthOfLongestSubstring2(string s)
{
    if(s.length() == 0) return 0;
    unordered_map<char, int> visited;
    int maxLen = INT_MIN, currLen = 0;
    for (int i = 0, j = 0; j < s.length();j++)
    {
        visited[s[j]]++;
        if (visited.size() == j - i +1)
        {
            maxLen = max(maxLen, j - i +1);
        }
        else if(visited.size() < j - i +1)
        {
            while (visited.size() < j - i +1)
            {
                if(--visited[s[i]] == 0) {
                    visited.erase(s[i]);
                }
                i++;
            }
        }
    }
    return maxLen;
}

int main()
{
    cout << lengthOfLongestSubstring2("abcabcbb") << endl;
    cout << lengthOfLongestSubstring2("bbbbb") << endl;
    cout << lengthOfLongestSubstring2(" ") << endl;
    return 0;
}