#include <iostream>
#include <vector>
using namespace std;


void reverseString(vector<char> &s)
{
    int i=0, j = s.size() - 1;
    while (i<j)
    {
       swap(s[i++], s[j--]);
    }
}

int main()
{
    vector<char> s = {'a','b','c','d', 'e'};
    reverseString(s);
    for(char c:s) cout<<c;
    return 0;
}