#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> map;
    unordered_set<char> visited;
    for (int i = 0; i < s.size(); i++)
    {
        auto it = map.find(s[i]);
        if (it == map.end())
        {
            if (visited.find(t[i]) != visited.end())
            {
                return false;
            }
            map[s[i]] = t[i];
            visited.insert(t[i]);
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        s[i] = map[s[i]];
    }
    return s == t;
}
int main()
{
    cout << isIsomorphic("egg", "add");
    return 0;
}