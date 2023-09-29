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

    int startIndex = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int c = counts[i];
        counts[i] = startIndex;
        startIndex += c;
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
    int maxElem = *max_element(nums.begin(), nums.end());

    int placeVal = 1;
    while (maxElem / placeVal > 0)
    {
        countingSort(nums, placeVal);
        placeVal *= 10;
    }
}
int main()
{
    vector<int> nums = {256, 336, 736, 443, 831, 907};
    radixSort(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}