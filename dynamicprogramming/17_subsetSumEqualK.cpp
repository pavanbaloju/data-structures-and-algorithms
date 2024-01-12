#include <iostream>
#include <vector>
using namespace std;

// recurrsion + memo
bool solve(int ind, int target, vector<int> nums, vector<vector<int>> dp)
{
    if (target == 0)
        return dp[ind][target] = true;
    if (ind == 0)
        return dp[ind][target] = target == nums[0];

    bool hasSum = solve(ind - 1, target, nums, dp);
    if (target >= nums[ind])
        hasSum = hasSum || solve(ind - 1, target - nums[ind], nums, dp);

    return dp[ind][target] = hasSum;
}

bool subsetSumToK(vector<int> nums, int target)
{
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return solve(nums.size() - 1, target, nums, dp);
}

bool subsetSumToKTable(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (nums[0] <= k)
    {
        dp[0][nums[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            // exclude
            bool hasSum = dp[ind - 1][target];

            // include
            if (nums[ind] <= target)
            {
                hasSum = hasSum || dp[ind - 1][target - nums[ind]];
            }

            dp[ind][target] = hasSum;
        }
    }
    return dp[n - 1][k];
}

bool subsetSumToKOpt(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<bool> prev(k + 1, false);
    prev[0] = true;

    if (nums[0] <= k)
    {
        prev[nums[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int target = 1; target <= k; target++)
        {
            // exclude
            bool hasSum = prev[target];

            // include
            if (nums[ind] <= target)
            {
                hasSum = hasSum || prev[target - nums[ind]];
            }

            curr[target] = hasSum;
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 4;

    cout << subsetSumToK(nums, target) << endl;
    cout << subsetSumToKTable(nums, target) << endl;
    cout << subsetSumToKOpt(nums, target) << endl;

    return 0;
}