#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool check(int a[], int b[])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
bool isAnagramArray(string s, string t)
{
    int fs[26] = {0};
    if (s.length() != t.length())
        return false;
    for (int i = 0; i < s.length(); i++)
    {
        fs[s[i] - 'a']++;
    }
    int ft[26] = {0};
    for (int i = 0; i < t.length(); i++)
    {
        ft[t[i] - 'a']++;
    }

    return check(fs, ft) == true;
}

bool isAnagram(string s, string t)
{
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    for (char c : t)
        freq[c]--;

    for (auto p : freq)
        if (p.second)
            return false;

    return true;
}

int main()
{
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagramArray("anagram", "nagaram") << endl;
    return 0;
}