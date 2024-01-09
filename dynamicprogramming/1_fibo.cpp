#include <iostream>
#include <vector>
using namespace std;

int fiboRecursive(int n)
{
    if (n <= 1)
        return n;

    return fiboRecursive(n - 1) + fiboRecursive(n - 2);
}

int fiboMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp));
}

int fiboTable(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fiboOpt(int n)
{
    int prev = 1, prev2 = 0;
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
    cout << fiboRecursive(n) << endl;

    vector<int> dp = vector<int>(n + 1, -1);
    cout << fiboMemo(n, dp) << endl;

    dp = vector<int>(n + 1, -1);
    cout << fiboTable(n, dp) << endl;

    cout << fiboOpt(n) << endl;

    return 0;
}