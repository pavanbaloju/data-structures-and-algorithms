#include <iostream>
#include <vector>
using namespace std;

int jumpMemo(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = jumpMemo(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            minSteps = min(jump, minSteps);
        }
    }

    return dp[ind] = minSteps;
}

int jumpTable(int n, vector<int> &height, vector<int> &dp, int k)
{
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = jumpMemo(i - j, height, dp, k) + abs(height[i] - height[i - j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }

    return dp[n - 1];
}

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << jumpMemo(n - 1, height, dp, 2) << endl;

    dp = vector<int>(n, -1);
    cout << jumpTable(n, height, dp, 2) << endl;
}
