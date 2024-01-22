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

int maxProfitMemo(vector<int> nums)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return maxProfitMemoUtil(0, true, 2, nums, dp);
}

int maxProfitTable(vector<int> nums)
{
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // no need to do again
    // for (int ind = 0; ind <= n; ind++)
    // {
    //     for (int buy = 0; buy <= 1; buy++)
    //     {
    //         dp[ind][buy][0] = 0;
    //     }
    // }
    // for (int buy = 0; buy <= 1; buy++)
    // {
    //     for (int txn = 0; txn <= 2; txn++)
    //     {
    //         dp[0][buy][txn] = 0;
    //     }
    // }

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int txn = 1; txn <= 2; txn++)
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
    return dp[0][1][2];
}

int maxProfitOpt(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int txn = 1; txn <= 2; txn++)
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
    return next[1][2];
}

int maxProfitOpt2(vector<int> nums)
{
    int n = nums.size();
    vector<int> next(5, 0), curr(5, 0);

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int txn = 3; txn >= 0; txn--)
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

    cout << maxProfitMemo(nums) << endl;
    cout << maxProfitTable(nums) << endl;
    cout << maxProfitOpt(nums) << endl;
    cout << maxProfitOpt2(nums) << endl;

    return 0;
}