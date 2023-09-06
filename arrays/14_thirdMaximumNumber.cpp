#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int thirdMax(vector<int> &nums)
{
    long long first = numeric_limits<long long>::min();
    long long second = numeric_limits<long long>::min();
    long long third = numeric_limits<long long>::min();
    int count = nums.size();

    for (int i = 0; i < count; i++)
    {
        if (nums[i] == first || nums[i] == second || nums[i] == third)
        {
            continue;
        }
        else if (nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] > second)
        {
            third = second;
            second = nums[i];
        }
        else if (nums[i] > third)
        {
            third = nums[i];
        }
    }
    if (third == numeric_limits<long long>::min())
    {
        return first;
    }
    else
    {
        return third;
    }
}

int main()
{
    vector<int> nums = {2, 2, 3, 1};
    cout << thirdMax(nums);
    return 0;
}