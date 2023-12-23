#include <iostream>
#include <unordered_map>
using namespace std;

bool hasDuplicates(unordered_map<char, int> visited, int i, int j)
{
    return visited.size() < j - i +1;
}

int lengthOfLongestSubstring(string s)
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
int lengthOfLongestSubstringOpt(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> visited;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (visited.count(s[right]) == 0 || visited[s[right]] < left) {
                visited[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = visited[s[right]] + 1;
                visited[s[right]] = right;
            }
        }
        
        return maxLength;
    }
int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstringOpt("abcabcbb") << endl;
    return 0;
}