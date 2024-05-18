#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> stk; // Stack to store indices of heights

    int maxArea = 0; // Variable to store the maximum area

    // Iterate through each bar in the histogram
    for (int i = 0; i <= n; ++i)
    {
        // Push the current index onto the stack if it's either empty 
        // or the current height is greater than or equal to the height at the index on top of the stack
        if (stk.empty() || (i < n && heights[i] >= heights[stk.top()]))
        {
            stk.push(i);
        }
        else
        {
            // If the current height is less than the height at the index on top of the stack, 
            // calculate the area of the rectangle with height equal to the height at the index on top of the stack
            int topIndex = stk.top();
            stk.pop();

            // Calculate the width of the rectangle
            int width = stk.empty() ? i : i - stk.top() - 1;

            // Calculate the area of the rectangle
            int area = heights[topIndex] * width;

            // Update the maximum area if necessary
            maxArea = max(maxArea, area);

            // Decrement the loop counter to revisit the current index
            --i;
        }
    }

    return maxArea;
}

// Function to calculate the maximum rectangle area in a binary matrix
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int m = matrix.size();
    int n = matrix[0].size();

    // Convert characters to integers (0 for '0', 1 for '1')
    vector<vector<int>> heights(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j)
    {
        heights[0][j] = matrix[0][j] - '0'; // Convert character to integer
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            heights[i][j] = matrix[i][j] == '1' ? heights[i - 1][j] + 1 : 0; // Update height based on previous row
        }
    }

    // Calculate the maximum rectangle area using largestRectangleArea function for each row
    int maxArea = 0;
    for (int i = 0; i < m; ++i)
    {
        maxArea = max(maxArea, largestRectangleArea(heights[i])); // Update maxArea
    }

    return maxArea;
}

int main()
{
    // Example binary matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    // Calculate the maximum rectangle area in the binary matrix
    int maxArea = maximalRectangle(matrix);

    // Print the result
    cout << "Maximum rectangle area in the binary matrix: " << maxArea << endl;

    return 0;
}
