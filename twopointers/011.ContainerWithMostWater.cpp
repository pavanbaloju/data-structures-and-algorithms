#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute the maximum area of water that can be trapped between the bars.

// Intuition:
// To maximize the trapped water, we need to maximize the area formed between two bars of the elevation map. The area is determined by the minimum height of the two bars and the distance between them. 
// We can solve this problem efficiently using the two-pointer approach.

// DSA Strategy/Pattern:
// Two Pointers

// Approach (Brute-force):
// 1. Initialize maxArea to INT_MIN (a very small value) to track the maximum area.
// 2. Iterate through all pairs of heights:
//    a. Calculate the area between the two heights by taking the minimum height of the two bars multiplied by the distance between them.
//    b. Update maxArea if the calculated area is greater.
// 3. Return maxArea as the result.
// 4. Time Complexity: O(n^2) - We iterate through all pairs of heights.
// 5. Space Complexity: O(1) - Constant space is used.

int maxAreaBrute(vector<int> &height)
{
    int maxArea = INT_MIN;
    // Iterate through all pairs of heights
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = 1; j < height.size(); j++)
        {
            // Calculate the area between the two heights
            int area = min(height[i], height[j]) * (j - i);
            // Update maxArea if the calculated area is greater
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

// Approach (Optimal):
// 1. Initialize maxArea to INT_MIN (a very small value) to track the maximum area.
// 2. Initialize two pointers, i and j, to point to the start and end of the elevation map, respectively.
// 3. Iterate until the two pointers meet:
//    a. Calculate the area between the two heights by taking the minimum height of the two bars multiplied by the distance between them.
//    b. Update maxArea if the calculated area is greater.
//    c. Move the pointer pointing to the smaller height towards the center.
// 4. Return maxArea as the result.
// 5. Time Complexity: O(n) - We iterate through the elevation map once.
// 6. Space Complexity: O(1) - Constant space is used.

int maxArea(vector<int> &height)
{
    int maxArea = INT_MIN;
    int i = 0, j = height.size() - 1;
    // Iterate until the two pointers meet
    while (i < j)
    {
        // Calculate the area between the two heights
        int area = min(height[i], height[j]) * (j - i);
        // Update maxArea if the calculated area is greater
        maxArea = max(maxArea, area);

        // Move the pointer pointing to the smaller height towards the center
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
    // Calculate and print the maximum area using the brute-force method
    cout << "Maximum area (Brute-force): " << maxAreaBrute(nums) << endl;
    // Calculate and print the maximum area using the optimal method
    cout << "Maximum area (Optimal): " << maxArea(nums) << endl;
    return 0;
}
