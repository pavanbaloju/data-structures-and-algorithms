#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

//using map
int firstUniqChar(string s)
{
    unordered_map<char, int> map;
    for (char c: s)
    {
        map[c]++;
    }
    for (char c: s)
    {
        if (map[c] == 1)
        {
            auto it = s.find(c);
            return it;
        }
    }
    return -1;
}

int firstUniqChar2(string s)
{
    vector<int> count(26, 0);
    for (char c:s)
    {
        count[c - 'a']++;
    }
    for (int i=0; i<s.size(); i++)
    {
        if (count[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    cout<<firstUniqChar("leetcode");
    cout<<firstUniqChar2("leetcode");
    return 0;
}