#include <iostream>
#include <vector>
using namespace std;

int solveMemo(int ind, vector<int> &nums, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    int pick = nums[ind] + solveMemo(ind - 2, nums, dp);
    int nonPick = 0 + solveMemo(ind - 1, nums, dp);
    return dp[ind] = max(pick, nonPick);
}

int maxSumMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMemo(n - 1, nums, dp);
}

int solveTable(vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1];
}

int maxSumTable(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveTable(nums, dp);
}

int maxSumOpt(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i], curr = 0;
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    vector<int> nums{2, 1, 4, 9};
    cout << maxSumMemo(nums) << endl;
    cout << maxSumTable(nums) << endl;
    cout << maxSumOpt(nums) << endl;
    return 0;
}
