#include <iostream>
#include <vector>
using namespace std;

int lengthOfLISMemoUtil(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int notTake = 0 + lengthOfLISMemoUtil(ind + 1, prev, nums, dp);
    int take = 0;
    if (prev == -1 || nums[ind] > nums[prev])
    {
        take = 1 + lengthOfLISMemoUtil(ind + 1, ind, nums, dp);
    }

    return dp[ind][prev + 1] = max(take, notTake);
}

int lengthOfLISMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return lengthOfLISMemoUtil(0, -1, nums, dp);
}

int lengthOfLISTable(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = 0 + dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[ind] > nums[prev])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

int lengthOfLISOpt(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n + 1, 0);
    vector<int> cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = 0 + next[prev + 1];
            int take = 0;
            if (prev == -1 || nums[ind] > nums[prev])
            {
                take = 1 + next[ind + 1];
            }
            cur[prev + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}

int lengthOfLISOpt2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = -1;

    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[prev] < nums[ind])
            {
                dp[ind] = max(dp[ind], dp[prev] + 1);
                maxi = max(maxi, dp[ind]);
            }
        }
    }
    return maxi;
}

int printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    for (int ind = 0; ind <= n - 1; ind++)
    {
        hash[ind] = ind; // initializing with current index
        for (int prev = 0; prev <= ind - 1; prev++)
        {
            if (nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i <= n - 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
        cout << lastIndex << " " << hash[lastIndex] << endl;
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    // reverse the nums
    reverse(temp.begin(), temp.end());
    cout << "The subsequence elements are ";
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;

    return ans;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLISMemo(nums) << endl;
    cout << lengthOfLISTable(nums) << endl;
    cout << lengthOfLISOpt(nums) << endl;
    cout << lengthOfLISOpt2(nums) << endl;
    cout << printLIS(nums) << endl;
    return 0;
}