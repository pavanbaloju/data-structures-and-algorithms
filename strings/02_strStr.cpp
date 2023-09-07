#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    for (int i = 0, j = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
        }
        else
        {
            i = i - j;
            j = 0;
        }
        if (j == needle.size())
        {
            return i - needle.size() + 1;
        }
    }
    return -1;
}
int main()
{
    cout << strStr("sadbutsad", "sad") << endl;
    cout << strStr("aaa", "aaaa") << endl;
    cout << strStr("mississippi", "issip") << endl;
    return 0;
}