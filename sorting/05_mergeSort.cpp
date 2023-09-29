#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    vector<int> left = vector<int>(len1);
    vector<int> right = vector<int>(len2);

    for (int i = 0; i < len1; i++)
    {
        left[i] = nums[start + i];
    }
    for (int i = 0; i < len2; i++)
    {
        right[i] = nums[mid + 1 + i];
    }

    int il = 0, ir = 0, idx = start;
    while (il < len1 && ir < len2)
    {
        if (left[il] <= right[ir])
        {
            nums[idx++] = left[il++];
        }
        else
        {
            nums[idx++] = right[ir++];
        }
    }

    while (il < len1)
    {
        nums[idx++] = left[il++];
    }

    while (ir < len2)
    {
        nums[idx++] = right[ir++];
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    merge(nums, start, end);
}

int main()
{
    vector<int> nums = {9, 8, 7, 6, 5, 4};
    mergeSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}