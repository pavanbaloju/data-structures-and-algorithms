#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

// int count(vector<int> &nums, int i, int currSum, int target)
// {
//     if (i == nums.size())
//     {
//         return target == currSum;
//     }
//     return count(nums, i + 1, currSum + nums[i], target) 
//         + count(nums, i + 1, currSum - nums[i], target);
// }

// int findTargetSumWays(vector<int> &nums, int target)
// {
//     return count(nums, 0, 0, target);
// }
int count(vector<int> &nums, int i, int currSum, int target, vector<vector<int>> &dp, int &total)
{
    if (i == nums.size())
    {
        return target == currSum;
    }
    if (dp[i][currSum + total] != INT_MIN)
    {
        return dp[i][currSum + total];
    }
    dp[i][currSum + total] = count(nums, i + 1, currSum + nums[i], target, dp, total) + count(nums, i + 1, currSum - nums[i], target, dp, total);
    return dp[i][currSum + total];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int total = 0;
    for (int x : nums)
        total += x;
    vector<vector<int>> dp = vector<vector<int>>(nums.size(), vector<int>(2 * total + 1, INT_MIN));
    return count(nums, 0, 0, target, dp, total);
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3);
    return 0;
}