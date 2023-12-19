#include <iostream>
using namespace std;

void reverseString(string &s, int left, int right)
{
    if (left > right)
        return;

    swap(s[left++], s[right--]);
    return reverseString(s, left, right);
}

int main()
{
    string s = "hellos";
    reverseString(s, 0, s.size() - 1);
    cout << s << endl;
    return 0;
}