#include <iostream>
#include <vector>
using namespace std;

// checking for every two heights
int maxAreaBrute(vector<int> &height)
{
    int maxArea = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = 1; j < height.size(); j++)
        {
            maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        }
    }
    return maxArea;
}

int maxArea(vector<int> &height)
{
    int maxArea = INT_MIN;
    int i = 0, j = height.size() - 1;
    while (i < j)
    {
        maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return maxArea;
}

int main()
{
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxAreaBrute(nums) << endl;
    return 0;
}
