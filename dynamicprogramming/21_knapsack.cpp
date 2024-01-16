#include <iostream>
#include <vector>
using namespace std;

int knapsackUtil(vector<int> &weights, vector<int> &items, int item, int capacity, vector<vector<int>> &dp)
{
    if (capacity == 0)
        return 0;

    if (item == 0)
        return weights[item] <= capacity ? items[item] : 0;

    if (dp[item][capacity] != -1)
        return dp[item][capacity];

    int notTaken = knapsackUtil(weights, items, item - 1, capacity, dp);
    int taken = 0;

    if (weights[item] <= capacity)
        taken = items[item] + knapsackUtil(weights, items, item - 1, capacity - weights[item], dp);

    return dp[item][capacity] = max(notTaken, taken);
}

int knapsack(vector<int> &weights, vector<int> &items, int capacity)
{
    int n = items.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return knapsackUtil(weights, items, n - 1, capacity, dp);
}

int knapsackTable(vector<int> &weights, vector<int> &items, int capacity)
{
    int n = items.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int i = weights[0]; i <= capacity; i++)
        dp[0][i] = items[0];

    for (int item = 1; item < n; item++)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            int notTaken = dp[item - 1][cap];
            int taken = 0;

            if (weights[item] <= cap)
                taken = items[item] + dp[item - 1][cap - weights[item]];

            dp[item][cap] = max(notTaken, taken);
        }
    }
    return dp[n - 1][capacity];
}

int knapsackOpt(vector<int> &weights, vector<int> &items, int capacity)
{
    int n = weights.size();
    vector<int> prev(capacity + 1, 0);
    for (int i = weights[0]; i <= capacity; i++)
        prev[i] = items[0];

    for (int item = 1; item < n; item++)
    {
        for (int cap = capacity; cap >= 0; cap--)
        {
            int notTaken = prev[cap];
            int taken = INT_MIN;

            if (weights[item] <= cap)
                taken = items[item] + prev[cap - weights[item]];

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[capacity];
}

int main()
{
    vector<int> weights = {1, 2, 4, 5};
    vector<int> items = {5, 4, 8, 6};
    int capacity = 5;

    cout << knapsack(weights, items, capacity) << endl;
    cout << knapsackTable(weights, items, capacity) << endl;
    cout << knapsackOpt(weights, items, capacity) << endl;

    return 0;
}
