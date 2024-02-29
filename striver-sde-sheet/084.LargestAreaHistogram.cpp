#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem Statement:
// Given an array of non-negative integers representing the heights of bars in a histogram, find the largest rectangle area formed by the bars.

// Intuition:
// To find the largest rectangle area, we need to consider each bar as the potential height of a rectangle and calculate its width by finding the range of bars that can extend to the left and right of the current bar without decreasing in height. We can use a stack-based approach to efficiently find these ranges.

// DSA Strategy:
// Monotonic increasing Stack

// Approach 1:
// Brute-force approach to find the largest rectangle area in a histogram
// Explanation:
// For each bar in the histogram, we iterate through all bars to the right 
// and calculate the area of the rectangle formed by considering the current bar and the range of bars from its right (inclusive) to the current bar's index (inclusive).
// Time Complexity: O(n^2), where n is the number of bars in the histogram.
// Space Complexity: O(1)
int largestRectangleAreaBruteForce(vector<int> &heights)
{
    int maxArea = 0;
    int n = heights.size();
    // Iterate through each bar in the histogram
    for (int i = 0; i < n; ++i)
    {
        int minHeight = heights[i]; // Initialize the minimum height as the height of the current bar
        // Iterate through the bars to the right of the current bar
        for (int j = i; j < n; ++j)
        {
            minHeight = min(minHeight, heights[j]); // Update the minimum height if necessary
            // Calculate the area of the rectangle formed by considering the current bar and the range of bars from i to j
            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }
    return maxArea;
}

// Approach 2:
// Efficient stack-based approach to find the largest rectangle area in a histogram
// Explanation:
// We use a stack to maintain indices of bars in non-decreasing order of heights. 
// For each bar, we keep popping bars from the stack while the current bar is smaller than the bar at the top of the stack. 
// For each popped bar, we calculate the area of the rectangle formed by considering it as the height 
// and the range of bars from its right (exclusive) to the current bar's index (inclusive) as the width. 
// We repeat this process until the stack is empty. We update the maximum area whenever a rectangle with a larger area is found.
// Time Complexity: O(n), where n is the number of bars in the histogram.
// Space Complexity: O(n), where n is the number of bars in the histogram (for the stack).
int largestRectangleArea(vector<int> &heights)
{
    stack<int> s;
    heights.push_back(0); // Add a sentinel value to handle the case when all heights are increasing
    int maxArea = 0;
    int n = heights.size();
    // Iterate through each bar in the histogram
    for (int i = 0; i < n; ++i)
    {
        // Keep popping bars from the stack while the current bar is smaller than the bar at the top of the stack
        while (!s.empty() && heights[s.top()] > heights[i])
        {
            int height = heights[s.top()];               // Get the height of the bar at the top of the stack
            s.pop();                                     // Pop the bar from the stack
            int width = s.empty() ? i : i - s.top() - 1; // Calculate the width of the rectangle
            maxArea = max(maxArea, height * width);      // Calculate the area of the rectangle and update maxArea if necessary
        }
        s.push(i); // Push the index of the current bar onto the stack
    }
    return maxArea;
}

int main()
{
    // Example histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Calculate and print the largest rectangle area using brute-force approach
    cout << "Maximum area using brute-force approach: " << largestRectangleAreaBruteForce(heights) << endl;

    // Calculate and print the largest rectangle area using stack-based approach
    cout << "Maximum area using stack-based approach: " << largestRectangleArea(heights) << endl;

    return 0;
}
