#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int i = 0, j = 0;
    while (i < haystack.size() && j < needle.size())
    {
        if (needle[j] == haystack[i])
        {
            j++;
            i++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return j == needle.size() ? i - j : -1;
}
int main()
{
    cout << strStr("sadbutsad", "sad") << endl;
    cout << strStr("aaa", "aaaa") << endl;
    cout << strStr("mississippi", "issip") << endl;
    return 0;
}