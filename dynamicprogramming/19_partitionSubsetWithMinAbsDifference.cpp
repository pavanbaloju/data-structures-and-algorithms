#include <iostream>
#include <vector>
using namespace std;
//fails for -ve numbers

bool subsetSumUtil(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
        return dp[ind][target] = (nums[0] == target);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, nums, dp);

    bool taken = false;
    if (nums[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - nums[ind], nums, dp);

    return dp[ind][target] = notTaken || taken;
}

int minimumDifference(vector<int>& nums)
{
    int n = nums.size();
    int m = INT_MAX;
    int totSum = 0;

    for (int i = 0; i < n; i++)
        totSum += nums[i];

    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    for (int i = 0; i <= totSum; i++)
        subsetSumUtil(n - 1, i, nums, dp);

    int mini = 1e9;
    for (int sum = 0; sum <= totSum; sum++)
    {
        if (dp[n - 1][sum] == true)
        {
            // sum : partition1 sum
            // total - sum: partition2 sum
            int diff = abs(sum - (totSum - sum));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << "The minimum absolute difference is: " << minimumDifference(nums);

    return 0;
}
