#include <iostream>
#include <vector>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int maxi = -1;
    vector<int> dp(n, 1), counts(n, 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[ind] > nums[prev] && dp[ind] < dp[prev] + 1)
            {
                dp[ind] = dp[prev] + 1;
                counts[ind] = counts[prev];
            }
            else if (nums[ind] > nums[prev] && dp[ind] == dp[prev] + 1)
            {
                counts[ind] += counts[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }

    int numOfLIS = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            numOfLIS += counts[i];
    }
    return numOfLIS;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}