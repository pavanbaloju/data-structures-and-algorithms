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
    reverseWord(s, 0, s.size()-1);
    string r = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==' ')
        {
            if (r!="" && r.back()!=' ')
            {
                r+=' ';
            }
            
        }
        else
        {
            r += s[i];
        }
        
    }
    if (r.back()==' ')
    {
        r.pop_back();
    }
    
    return r;
}

int main()
{
    string s = "  the sky   is blue  ";
    cout << reverseWords(s)<<"x";
    return 0;
}