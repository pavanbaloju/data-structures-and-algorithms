#include <iostream>
#include <vector>

using namespace std;

int coinChangeMemoUtil(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int notTaken = 0 + coinChangeMemoUtil(coins, ind - 1, amount, dp);

    int taken = 1e9;
    if (coins[ind] <= amount)
        taken = 1 + coinChangeMemoUtil(coins, ind, amount - coins[ind], dp);

    return dp[ind][amount] = min(notTaken, taken);
}

int coinChangeMemo(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = coinChangeMemoUtil(coins, n - 1, amount, dp);
    return ans >= 1e9 ? -1 : ans;
}

int coinChangeTable(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = dp[ind - 1][target];
            int take = 1e9;
            if (coins[ind] <= target)
                take = 1 + dp[ind][target - coins[ind]];

            dp[ind][target] = min(notTake, take);
        }
    }
    int ans = dp[n - 1][amount];
    return ans >= 1e9 ? -1 : ans;
}

int coinChangeOpt(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = prev[target];
            int take = 1e9;
            if (coins[ind] <= target)
                take = 1 + cur[target - coins[ind]];

            cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    return prev[amount] >= 1e9 ? -1 : prev[amount];
}

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChangeMemo(coins, amount) << endl;
    cout << coinChangeTable(coins, amount) << endl;
    cout << coinChangeOpt(coins, amount) << endl;

    return 0;
}
