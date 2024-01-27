
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int mod = 1000000007;

int countWays(char &oper, bool countTrue, ll &lT, ll &lF, ll &rT, ll &rF)
{
    int ways = 0;
    if (oper == '&')
    {
        if (countTrue)
            ways = (lT * rT) % mod;
        else
            ways = (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod;
    }
    else if (oper == '|')
    {
        if (countTrue)
            ways = (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod;
        else
            ways = (lF * rF) % mod;
    }
    else
    {
        if (countTrue)
            ways = (lF * rT) % mod + (lT * rF) % mod;
        else
            ways = (lF * rF) % mod + (lT * rT) % mod;
    }
    return ways;
}

int f(int i, int j, bool countTrue, string &exp, vector<vector<vector<ll>>> &dp)
{

    if (i > j)
        return 0;

    if (i == j)
    {
        if (countTrue)
            return exp[i] == 'T' ? 1 : 0;
        else
            return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][countTrue] != -1)
        return dp[i][j][countTrue];

    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lT = f(i, ind - 1, true, exp, dp);
        ll lF = f(i, ind - 1, false, exp, dp);
        ll rT = f(ind + 1, j, true, exp, dp);
        ll rF = f(ind + 1, j, false, exp, dp);

        ways += countWays(exp[ind], countTrue, lT, lF, rT, rF) % mod;
    }
    return ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, true, exp, dp);
}

int evaluateExpTable(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j <= n - 1; j++)
        {
            for (int countTrue = 0; countTrue <= 1; countTrue++)
            {
                if (i == j)
                {
                    if (countTrue == 1)
                        dp[i][j][countTrue] = exp[i] == 'T';
                    else
                        dp[i][j][countTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2)
                {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    ways += countWays(exp[ind], countTrue, lT, lF, rT, rF) % mod;
                }
                dp[i][j][countTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

int main()
{
    string exp = "F|T^F";
    cout << evaluateExp(exp) << endl;
    cout << evaluateExpTable(exp) << endl;
    return 0;
}
