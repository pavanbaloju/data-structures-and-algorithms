#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(vector<int> &nums, int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (target > nums[mid])
    {
        return binarySearch(nums, target, mid + 1, end);
    }
    else
    {
        return binarySearch(nums, target, start, mid - 1);
    }
}

int binarySearchIterative(vector<int> &nums, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    return binarySearchIterative(nums, target, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << search(nums, 3);
}
