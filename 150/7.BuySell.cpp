#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> nums)
{
    int mini = -1, maxi = -1, min = INT_MAX, max = INT_MIN, maxProfit = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
            mini = i;
            max = INT_MIN;
            maxi = -1;
        }
        else if (mini != -1 && nums[i] > min && nums[i] > max)
        {
            max = nums[i];
            maxi = i;
            maxProfit = (max - min < maxProfit) ? maxProfit : max - min;
        }
    }
    return (maxProfit) ? maxProfit : 0;
}

int maxProfitOpt(vector<int> nums)
{
    int minPrice = INT_MAX, maxProfit = 0, currProfit = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        minPrice = min(nums[i], minPrice); 
        maxProfit = max(maxProfit, nums[i] - minPrice);
    }

    return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4, 0, 10};

    cout << maxProfitOpt(nums);
    return 0;
}