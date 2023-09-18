#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numSquares(int n)
{
    vector<int> squares;
    for (int i = 1; i <= floor(sqrt(n)); i++)
    {
        squares.push_back(i * i);
    }
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int sq : squares)
        {
            if (p.first - sq == 0)
            {
                return p.second + 1;
            }
            q.push({p.first - sq, p.second + 1});
        }
    }
    return -1;
}
int numSquares2(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        int sq = i * i;
        for (int j = sq; j < n + 1; j++)
        {
            dp[j] = min(dp[j - sq] + 1, dp[j]);
        }
    }
    return dp[n];
}

int main()
{
    cout << numSquares2(12);
    return 0;
}