#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int totalSum = 0,leftSum = 0, count = nums.size();

    for (int i = 0; i < count; i++)
    {
        totalSum += nums[i];
    }

    for (int i = 0; i < count; i++)
    {
        if (totalSum - nums[i] == 2 * leftSum)
        {
           return i;
        }
        else{
            leftSum += nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int p = pivotIndex(nums);
    cout << p;
    return 0;
}