#include <iostream>
using namespace std;

double myPowBrute(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (n < 0)
    {
        return myPowBrute(1 / x, -n);
    }
    return x * myPowBrute(x, n - 1);
}

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    return n % 2 ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
}

int main()
{
    cout << myPowBrute(5, 3) << endl;
    cout << myPowBrute(5, -2) << endl;
    cout << myPow(0.001, 2147483647) << endl;
    return 0;
}