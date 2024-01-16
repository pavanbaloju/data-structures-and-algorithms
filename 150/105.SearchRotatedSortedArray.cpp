#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target == nums[mid])
            return mid;

        // left sorted
        if (nums[start] <= nums[mid])
        {
            // target present in left
            if (nums[start] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            // target present in right
            else
            {
                start = mid + 1;
            }
        }
        // right sorted
        else
        {
            // target present in right
            if (nums[mid] <= target && target <= nums[end])
            {
                start = mid + 1;
            }
            // target present in left
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0);
    return 0;
}