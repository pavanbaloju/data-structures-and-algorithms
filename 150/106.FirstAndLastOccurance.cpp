#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int lowerBound(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return {-1, -1};

    int first = lowerBound(nums, target);
    if (first >= nums.size() || nums[first] != target)
    {
        return {-1, -1};
    }
    int last = upperBound(nums, target) - 1;
    return {first, last};
}

vector<int> searchRange2(vector<int> &nums, int target)
{
    int first = lowerBound(nums, target);
    int last = lowerBound(nums, target + 1) - 1;
    if (first < nums.size() && nums[first] == target)
    {
        return {first, last};
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(nums, 8);
    for (int x : res)
        cout << x << " ";
    cout << endl;
    res = searchRange2(nums, 8);
    for (int x : res)
        cout << x << " ";
}