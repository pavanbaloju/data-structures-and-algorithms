#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> nums)
{
    int minPrice = INT_MAX, maxProfit = 0, currProfit = 0, totalProfit = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i-1])
        {
            totalProfit += nums[i] - nums[i-1];
        }
    }
    return totalProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(nums);
    return 0;
}