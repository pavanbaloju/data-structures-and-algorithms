#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target, int start, int end)
{
    if (nums.size() == 0)
        return -1;
    while (start + 1 < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }

    // End Condition: start == end
    if (nums[start] == target)
    {
        return start;
    }
    if (nums[end] == target)
    {
        return end;
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << search(nums, 3);
}