#include <iostream>
#include <vector>
using namespace std;

int trailingZeroes(int n)
{
    int zeroes = 0;
    while (n)
    {
        zeroes += n / 5;
        n /= 5;
    }
    return zeroes;
}

int trailingZeroes2(int n)
{
    int zeroes = 0;
    for (int deno = 5; n / deno > 0; deno *= 5)
    {
        zeroes += n / deno;
    }
    return zeroes;
}

int main()
{
    cout << trailingZeroes(10) << endl;
    cout << trailingZeroes2(100) << endl;
}
