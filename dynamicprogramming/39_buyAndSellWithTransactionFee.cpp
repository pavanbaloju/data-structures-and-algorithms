#include <iostream>
#include <vector>
using namespace std;

int maxProfitMemo(int ind, bool buy, int fee, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(0 + maxProfitMemo(ind + 1, true, fee, nums, dp), -nums[ind] - fee + maxProfitMemo(ind + 1, false, fee, nums, dp));
    }
    else
    {
        profit = max(0 + maxProfitMemo(ind + 1, false, fee, nums, dp), nums[ind] + maxProfitMemo(ind + 1, true, fee, nums, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfitMemoi(vector<int> &nums, int fee)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return maxProfitMemo(0, true, fee, nums, dp);
}

int maxProfitTable(vector<int> &nums, int fee)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(0 + dp[ind + 1][1], -nums[ind] + dp[ind + 1][0] - fee);
            }
            else
            {
                profit = max(0 + dp[ind + 1][0], nums[ind] + dp[ind + 1][1]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfitOpt(vector<int> &nums, int fee)
{
    int n = nums.size();
    vector<int> next(2, 0), curr(2, 0);
    next[0] = next[1] = 0;

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(0 + next[1], -nums[ind] + next[0] - fee);
            }
            else
            {
                profit = max(0 + next[0], nums[ind] + next[1]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int fee = 2;

    cout << maxProfitMemoi(nums, fee) << endl;
    cout << maxProfitTable(nums, fee) << endl;
    cout << maxProfitOpt(nums, fee) << endl;
    return 0;
}