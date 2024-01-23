#include <iostream>
#include <vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    int ans = -1;
    int lastIndex = -1;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > ans)
        {
            ans = dp[ind];
            lastIndex = ind;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    return temp;
}

int main()
{
    vector<int> nums = {1, 2, 8, 3, 16, 4};
    vector<int> ans = largestDivisibleSubset(nums);
    for (int n : ans)
        cout << n << " ";
    cout << endl;
    return 0;
}