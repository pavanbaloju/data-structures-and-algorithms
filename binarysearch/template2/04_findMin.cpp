#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[start] < nums[end])
        {
            return nums[start];
        }
        if (nums[start] <= nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums);
}