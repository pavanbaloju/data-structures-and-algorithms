#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    cuts.push_back(n);
    cuts.push_back(0);
    sort(cuts.begin(), cuts.end());

    return solve(1, c, cuts, dp);
}

int minCostTable(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int main()
{
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << minCost(n, cuts) << endl;

    cuts = {1, 3, 4, 5};
    cout << minCostTable(n, cuts) << endl;
    return 0;
}