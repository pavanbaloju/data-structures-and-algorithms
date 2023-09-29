#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &nums, int placeVal)
{
    int k = 10;
    vector<int> counts = vector<int>(k);

    for (int num : nums)
    {
        counts[(num / placeVal) % k] += 1;
    }

    for (int i = 1; i < k; i++)
    {
        counts[i] += counts[i-1];
    }

    vector<int> sorted = vector<int>(nums.size());
    for (int num : nums)
    {
        sorted[counts[(num / placeVal) % k]] = num;
        counts[(num / placeVal) % k]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}
void radixSort(vector<int> &nums)
{
    int maxElem = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > maxElem)
        {
            maxElem = nums[i];
        }
    }

    int placeVal = 1;
    while (maxElem / placeVal > 0)
    {
        countingSort(nums, placeVal);
        placeVal *= 10;
    }
}
int maximumGap(vector<int> &nums)
{
    radixSort(nums);
    int maxGap = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] > maxGap)
        {
            maxGap = nums[i] - nums[i - 1];
        }
    }
    return maxGap;
}

int main()
{
    vector<int> nums = {3, 6, 9, 1};
    cout << maximumGap(nums);
    return 0;
}