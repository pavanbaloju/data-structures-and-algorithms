#include <iostream>
#include <vector>
using namespace std;

// bubble sort
void sort(vector<int> &nums)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    }
}

int heightChecker(vector<int> &heights)
{
    vector<int> expected;
    expected = heights;
    sort(expected);

    int c = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            c++;
        }
    }
    return c;
}

int main()
{
    vector<int> heights = {5, 1, 2, 3, 4};
    cout << heightChecker(heights);
    return 0;
}