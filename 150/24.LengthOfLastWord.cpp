#include <iostream>
using namespace std;

int lengthOfLastWord(string s)
{
    int len = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && len > 0)
            break;
        if (s[i] != ' ')
            len++;
    }
    return len;
}

int main()
{
    cout << lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << lengthOfLastWord("h") << endl;
    return 0;
}