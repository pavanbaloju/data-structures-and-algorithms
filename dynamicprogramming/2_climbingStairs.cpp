#include <iostream>
#include <vector>
using namespace std;

// this is a fibonacci problem starts with 1, 1
int climbStairs(int n)
{
    int prev = 1, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n = 5;
    cout << climbStairs(n) << endl;

    return 0;
}