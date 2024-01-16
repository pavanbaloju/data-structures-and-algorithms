#include <vector>
#include <iostream>
using namespace std;

int findWaysUtil(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (ind == 0)
        return (nums[0] == target) ? 1 : 0;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, nums, dp);

    int taken = 0;
    if (nums[ind] <= target)
        taken = findWaysUtil(ind - 1, target - nums[ind], nums, dp);

    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

int findWaysTable(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }
            dp[ind][target] = notTaken + taken;
        }
    }
    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            cout << dp[ind][target] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][k];
}
int findWaysOpt(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> prev(k + 1, 0);

    prev[0] = 1;

    if (num[0] <= k)
    {
        prev[num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> cur(k + 1, 0);
        cur[0] = 1;
        for (int target = 1; target <= k; target++)
        {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
            {
                taken = prev[target - num[ind]];
            }

            cur[target] = notTaken + taken;
        }

        prev = cur;
    }

    return prev[k];
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int k = 3;
    cout << findWays(nums, k) << endl;
    cout << findWaysTable(nums, k) << endl;
    cout << findWaysOpt(nums, k) << endl;
    return 0;
}
