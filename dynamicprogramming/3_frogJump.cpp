#include <iostream>
#include <vector>
using namespace std;

int jumpMemo(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int jumpTwo = INT_MAX;
    int jumpOne = jumpMemo(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = jumpMemo(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int jumpTable(int n, vector<int> &height, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        int one = dp[i - 1] + abs(height[i] - height[i - 1]);
        int two = i > 1 ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
        dp[i] = min(one, two);
    }

    return dp[n - 1];
}

int jumpOpt(int n, vector<int> &height)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int one = prev + abs(height[i] - height[i - 1]);
        int two = i > 1 ? prev2 + abs(height[i] - height[i - 2]) : INT_MAX;

        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << jumpMemo(n - 1, height, dp) << endl;

    dp = vector<int>(n, -1);
    cout << jumpTable(n, height, dp) << endl;
    cout << jumpOpt(n, height) << endl;
}
