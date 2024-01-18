#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int reverse = 0;
    int temp = x;
    while (x)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return temp == reverse;
}

int main()
{
    cout << isPalindrome(12321) << endl;
    return 0;
}