#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    int i = 0, j = s.size() - 1;

    while (i <= j)
    {
        if (isalnum(s[i]) && isalnum(s[j]))
        {
            if (tolower(s[i++]) != tolower(s[j--]))
            {
                return false;
            }
        }
        else if (!isalnum(s[i]))
        {
            i++;
        }
        else if (!isalnum(s[j]))
        {
            j--;
        }
    }
    return true;
}

int main()
{
    cout << isPalindrome("race car") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome(" ") << endl;
}