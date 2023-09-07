#include <iostream>
#include <vector>

using namespace std;
int dominantIndex(vector<int> &nums)
{
    int max = -1, max2 = -1, count = nums.size();
    for (int i = 0; i < count; i++)
    {
        if (max == -1 || nums[i] > nums[max])
        {
            max2 = max;
            max = i;
        }
        else if (max2 == -1 || nums[i] > nums[max2])
        {
            max2 = i;
        }
    }

    if (nums[max] >= 2 * nums[max2])
    {
        return max;
    }
    else
    {
        return -1;
    }
}

int dominantIndex2(vector<int> &nums)
{
    int max = INT_MIN,maxi= -1, count = nums.size();
    for (int i = 0; i < count; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            maxi= i;
        }
    }
    for (int i = 0; i < count; i++)
    {
       if (i == maxi)
       {
        continue;
       }
       else if (max <nums[i]*2)
       {
        return -1;
       }
       
    }
    return maxi;
}

int main()
{
    vector<int> nums = {2, 1};
    int p = dominantIndex(nums);
    cout << p;
    return 0;
}