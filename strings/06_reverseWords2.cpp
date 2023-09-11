#include <iostream>
#include <vector>
using namespace std;

void reverseWord(string &s, int start, int end)
{
    for (int i = start, j = end; i < j;)
    {
        swap(s[i++], s[j--]);
    }
}
string reverseWords(string s)
{
    int count = 0;
    for (int i = 0;; i++)
    {
        if (s[i] == ' ' || i == s.size())
        {
            if (count > 0)
            {
                reverseWord(s, i - count, i - 1);
                count = 0;
            }
        }
        else
        {
            count++;
        }
        if (i == s.size())
        {
            break;
        }
    }
    
    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s)<<"x";
    return 0;
}