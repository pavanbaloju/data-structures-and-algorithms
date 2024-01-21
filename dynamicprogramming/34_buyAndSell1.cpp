#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> nums)
{
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int currProfit = nums[i] - minPrice;
        minPrice = min(nums[i], minPrice); 
        maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(nums);
    return 0;
}