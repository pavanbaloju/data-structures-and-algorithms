#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int i;
    int l = strs.size() - 1;
    for (i = 0; i < strs[0].size();)
    {
        if (strs[l][i] != strs[0][i])
        {
            break;
        }
        i++;
    }
    return strs[0].substr(0, i);
}

int main()
{
    vector<string> strings = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strings);
    vector<string> v = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(v);
    return 0;
}