#include <iostream>
#include <vector>
using namespace std;

int maxProfitMemoUtil(int ind, bool buy, int txns, vector<int> &nums, vector<vector<vector<int>>> &dp)
{
    if (ind == nums.size() || txns == 0)
        return 0;

    if (dp[ind][buy][txns] != -1)
        return dp[ind][buy][txns];

    int profit = 0;
    if (buy)
    {
        profit = max(0 + maxProfitMemoUtil(ind + 1, true, txns, nums, dp), -nums[ind] + maxProfitMemoUtil(ind + 1, false, txns, nums, dp));
    }
    else
    {
        profit = max(0 + maxProfitMemoUtil(ind + 1, false, txns, nums, dp), nums[ind] + maxProfitMemoUtil(ind + 1, true, txns - 1, nums, dp));
    }
    return dp[ind][buy][txns] = profit;
}

int maxProfitMemo(int k, vector<int> &nums)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return maxProfitMemoUtil(0, true, k, nums, dp);
}

int maxProfitTable(int k, vector<int> &nums)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int txn = 1; txn <= k; txn++)
            {
                if (buy)
                {
                    profit = max(0 + dp[ind + 1][1][txn], -nums[ind] + dp[ind + 1][0][txn]);
                }
                else
                {
                    profit = max(0 + dp[ind + 1][0][txn], nums[ind] + dp[ind + 1][1][txn - 1]);
                }
                dp[ind][buy][txn] = profit;
            }
        }
    }
    return dp[0][1][k];
}

int maxProfitOpt(int k, vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> next(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int txn = 1; txn <= k; txn++)
            {
                if (buy)
                {
                    profit = max(0 + next[1][txn], -nums[ind] + next[0][txn]);
                }
                else
                {
                    profit = max(0 + next[0][txn], nums[ind] + next[1][txn - 1]);
                }
                curr[buy][txn] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}

// even, odd 
int maxProfitOpt2(int k, vector<int> &nums)
{
    int n = nums.size();
    int txns = 2 * k;
    vector<int> next(txns + 1, 0), curr(txns + 1, 0);

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int txn = txns - 1; txn >= 0; txn--)
        {
            if (txn % 2 == 0)
            {
                profit = max(0 + next[txn], -nums[ind] + next[txn + 1]);
            }
            else
            {
                profit = max(0 + next[txn], nums[ind] + next[txn + 1]);
            }
            curr[txn] = profit;
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    vector<int> nums = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << maxProfitMemo(2, nums) << endl;
    cout << maxProfitTable(2, nums) << endl;
    cout << maxProfitOpt(2, nums) << endl;
    cout << maxProfitOpt2(2, nums) << endl;

    return 0;
}