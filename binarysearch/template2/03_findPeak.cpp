#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    int n = nums.size() - 1;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n] > nums[n - 1])
        return n;

    int start = 1, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid - 1] > nums[mid])
        {
            end = mid - 1;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums);
}