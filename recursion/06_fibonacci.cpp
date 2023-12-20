#include <iostream>
#include <map>
using namespace std;

map<int, int> memo;

int fib(int n)
{
    if (memo.count(n))
    {
        return memo[n];
    }

    if (n < 2)
    {
        return memo[n] = n;
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main()
{
    memo = map<int, int>();
    cout << fib(2);
    return 0;
}