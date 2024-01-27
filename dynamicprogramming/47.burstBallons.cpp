#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        maxi = max(maxi, nums[i - 1] * nums[ind] * nums[j + 1] + solve(i, ind - 1, nums, dp) + solve(ind + 1, j, nums, dp));
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    return solve(1, n, nums, dp);
}

int maxCoinsTable(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                maxi = max(maxi, nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j]);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;

    nums = {3, 1, 5, 8};
    cout << maxCoinsTable(nums) << endl;
    return 0;
}