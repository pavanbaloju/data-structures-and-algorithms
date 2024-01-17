
#include <iostream>
#include <vector>

using namespace std;

int countCoinChangeMemoUtil(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return amount % coins[0] == 0;
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int notTaken = countCoinChangeMemoUtil(coins, ind - 1, amount, dp);

    int taken = 0;
    if (coins[ind] <= amount)
        taken = countCoinChangeMemoUtil(coins, ind, amount - coins[ind], dp);

    return dp[ind][amount] = notTaken + taken;
}

int countCoinChangeMemo(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return countCoinChangeMemoUtil(coins, n - 1, amount, dp);
}

int countCoinChangeTable(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = dp[ind - 1][target];
            int take = 0;
            if (coins[ind] <= target)
                take = dp[ind][target - coins[ind]];

            dp[ind][target] = notTake + take;
        }
    }
    return dp[n - 1][amount];
}

int countCoinChangeOpt(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = prev[target];
            int take = 0;
            if (coins[ind] <= target)
                take = cur[target - coins[ind]];

            cur[target] = notTake + take;
        }
        prev = cur;
    }
    return prev[amount];
}

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << countCoinChangeMemo(coins, amount) << endl;
    cout << countCoinChangeTable(coins, amount) << endl;
    cout << countCoinChangeOpt(coins, amount) << endl;

    return 0;
}
