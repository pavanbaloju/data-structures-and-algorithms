#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int start, int end)
{
    int pivot = nums[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(nums[pivotIndex], nums[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (nums[i] <= pivot)
        {
            i++;
        }
        while (nums[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(nums[i++], nums[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivotIndex = partition(nums, start, end);
    quickSort(nums, start, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, end);
}

int main()
{
    vector<int> nums = {
        9,
        98,
        87,
        6,
        35,
        4,
        11,
        23,
        67,
        99,
    };
    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}