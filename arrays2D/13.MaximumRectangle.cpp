#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Problem Statement:
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Intuition:
// To efficiently find the largest rectangle containing only 1's in a 2D binary matrix, we can utilize the largest rectangle in histogram problem.
// We iterate through each row of the matrix and treat it as the base of a histogram.
// Then, we calculate the histogram heights for each column in that row, where the height represents the number of consecutive 1's from the current row to the top.
// By applying the largest rectangle in histogram algorithm to each histogram, we can determine the largest rectangle containing only 1's in the matrix.

// DSA Strategy/Pattern: Stack, Dynamic Programming

class Solution
{
public:
    // Approach 1: Using Largest Rectangle in Histogram as Helper
    // - Iterate through each row of the matrix.
    // - For each row, calculate the histogram heights for each column, where the height represents the number of consecutive 1's from the current row to the top.
    // - Apply the largest rectangle in histogram algorithm to each histogram to find the maximum area rectangle containing only 1's.
    // Time Complexity: O(m*n), where m is the number of rows and n is the number of columns in the matrix.
    // Space Complexity: O(n), where n is the number of columns in the matrix.
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0); // Heights of histograms

        int maxArea = 0;
        // Iterate through each row
        for (int i = 0; i < m; ++i)
        {
            // Update heights for each column
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j] = 0; // Reset height if the cell is '0'
                }
            }
            // Calculate the maximum area rectangle for the current row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    // Helper function to find the largest area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.push_back(0); // Append a 0 to the end to handle the case of increasing heights until the end
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << "Largest rectangle area: " << sol.maximalRectangle(matrix) << endl;

    return 0;
}
