#include <iostream>
#include <vector>
using namespace std;

vector<int> coinChange(int V, vector<int> coins)
{
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> ans;

    for (int i = 0; i < coins.size(); i++)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans = coinChange(88, coins);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}