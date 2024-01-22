#include <iostream>
#include <vector>
using namespace std;

int maxProfitMemo(int ind, bool buy, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind >= nums.size())
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(0 + maxProfitMemo(ind + 1, true, nums, dp), -nums[ind] + maxProfitMemo(ind + 1, false, nums, dp));
    }
    else
    {
        profit = max(0 + maxProfitMemo(ind + 1, false, nums, dp), nums[ind] + maxProfitMemo(ind + 2, true, nums, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfitMemoi(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return maxProfitMemo(0, true, nums, dp);
}

int maxProfitTable(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                profit = max(0 + dp[ind + 1][1], -nums[ind] + dp[ind + 1][0]);
            }
            else
            {
                profit = max(0 + dp[ind + 1][0], nums[ind] + dp[ind + 2][1]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfitOpt(vector<int> nums)
{
    int n = nums.size();
    vector<int> next(2, 0), next2(2, 0), curr(2, 0);

    int profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        curr[1] = max(0 + next[1], -nums[ind] + next[0]);
        curr[0] = max(0 + next[0], nums[ind] + next2[1]);

        next2 = next;
        next = curr;
    }

    return curr[1];
}

int main()
{
    vector<int> nums = {1, 2, 3, 0, 2};

    cout << maxProfitMemoi(nums) << endl;
    cout << maxProfitTable(nums) << endl;
    cout << maxProfitOpt(nums) << endl;

    return 0;
}