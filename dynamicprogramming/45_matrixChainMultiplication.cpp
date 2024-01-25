#include <iostream>
#include <vector>
using namespace std;

int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = nums[i - 1] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k + 1, j, nums, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(1, n - 1, nums, dp);
}

int matrixMultiplicationTable(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = nums[i - 1] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k + 1, j, nums, dp);
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << matrixMultiplication(arr) << endl;
    cout << matrixMultiplicationTable(arr) << endl;
    return 0;
}