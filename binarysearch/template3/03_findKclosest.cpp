#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int x)
{
    int start = 0, end = nums.size() - 1;
    int val = nums[start], idx = start;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int currDiff = abs(nums[mid] - x);
        int minDiff = abs(val - x);
        if (currDiff < minDiff || (currDiff == minDiff && nums[mid] < val))
        {
            val = nums[mid];
            idx = mid;
        }

        if (nums[mid] < x)
        {
            start = mid + 1;
        }
        else if (nums[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            break;
        }
    }
    return idx;
}

vector<int> findClosestElements(vector<int> &nums, int k, int x)
{
    int index = binarySearch(nums, x);
    int i = index, j = index;
    while (k-- > 1)
    {
        if (i == 0)
        {
            j++;
        }
        else if (j == nums.size() - 1 || (abs(x - nums[i - 1]) <= abs(x - nums[j + 1])))
        {
            i--;
        }
        else
        {
            j++;
        }
    }

    vector<int> res;
    for (int idx = i; idx < j+1; idx++)
        res.push_back(nums[idx]);
    return res;
}

int main()
{
    vector<int> nums = {1,1,1,10,10,10};
    cout << binarySearch(nums, 9) << endl;
    vector<int> res = findClosestElements(nums, 1, 9);

    for (int num : res)
    {
        cout << num << " ";
    }
    return 0;
}