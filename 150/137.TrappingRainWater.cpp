#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/trapping-rain-water/

int trapBrute(vector<int> &arr)
{
    int n = arr.size();
    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}
int trapWithPrecalculate(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);

    for (int i = 1; i < n; ++i)
        leftMax[i] = max(height[i - 1], leftMax[i - 1]);

    for (int i = n - 2; i >= 0; --i)
        rightMax[i] = max(height[i + 1], rightMax[i + 1]);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int waterLevel = min(leftMax[i], rightMax[i]);
        if (waterLevel >= height[i])
            ans += waterLevel - height[i];
    }
    return ans;
}

int trap(vector<int> &height)
{
    if (height.size() <= 2)
        return 0;

    int n = height.size();
    int leftMax = height[0], rightMax = height[n - 1];
    int left = 1, right = n - 2, ans = 0;
    while (left <= right)
    {
        if (leftMax < rightMax)
        {
            if (height[left] > leftMax)
                leftMax = height[left];
            else
                ans += leftMax - height[left];
            ++left;
        }
        else
        {
            if (height[right] > rightMax)
                rightMax = height[right];
            else
                ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}

int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights) << endl;
    cout << trapBrute(heights) << endl;
    cout << trapWithPrecalculate(heights) << endl;
    return 0;
}