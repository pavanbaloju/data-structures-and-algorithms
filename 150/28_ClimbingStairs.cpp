#include <iostream>
#include <map>
using namespace std;

map<int, int> memo;

int climbStairs(int n)
{
    if (memo.count(n))
    {
        return memo[n];
    }

    if (n <= 2)
    {
        return memo[n] = n;
    }
    return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
}
int main()
{
    memo = map<int, int>();
    cout << climbStairs(3);
    return 0;
}