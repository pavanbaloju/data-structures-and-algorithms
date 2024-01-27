#include <iostream>
#include <vector>
using namespace std;

int solve(int ind, int n, vector<int> &arr, int k, vector<int> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxVal = INT_MIN;
    int maxSum = INT_MIN;
    for (int i = ind; i < min(n, ind + k); i++)
    {
        len++;
        maxVal = max(maxVal, arr[i]);
        maxSum = max(maxSum, len * maxVal + solve(i + 1, n, arr, k, dp));
    }

    return dp[ind] = maxSum;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, n, arr, k, dp);
}

int maxSumAfterPartitioningTable(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxVal = INT_MIN;
        int maxSum = INT_MIN;
        for (int i = ind; i < min(ind + k, n); i++)
        {
            len++;
            maxVal = max(maxVal, arr[i]);
            maxSum = max(maxSum, len * maxVal + dp[i + 1]);
        }
        dp[ind] = maxSum;
    }
    return dp[0];
}

int main()
{
    vector<int> nums{1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(nums, 3) << endl;
    cout << maxSumAfterPartitioningTable(nums, 3) << endl;
    return 0;
}