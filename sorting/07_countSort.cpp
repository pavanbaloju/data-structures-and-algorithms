#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &nums)
{
    // int k = *max_element(nums.begin(), nums.end());
    int k = 2;
    vector<int> counts = vector<int>(k + 1);

    for (int num : nums)
    {
        counts[num] += 1;
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
        sorted[counts[num]] = num;
        counts[num]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}

void sortColors(vector<int> &nums)
{
    countSort(nums);
}

int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    for (int x : colors)
        cout << x << " ";
    return 0;
}