#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp1(n, 1), dp2(n, 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[ind] > nums[prev])
            {
                dp1[ind] = max(dp1[ind], dp1[prev] + 1);
            }
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = n - 1; prev > ind; prev--)
        {
            if (nums[ind] > nums[prev])
            {
                dp2[ind] = max(dp2[ind], dp2[prev] + 1);
            }
        }
    }

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp1[i] == 1 || dp2[i] == 1)
            continue;
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int minimumMountainRemovals(vector<int> &nums)
{
    return nums.size() - lengthOfLIS(nums);
}

int main()
{
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << minimumMountainRemovals(nums) << endl;
    return 0;
}