#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a matrix of integers, perform a spiral order traversal starting from the top-left corner.
// Spiral order traversal follows the pattern of moving in a clockwise spiral from the outermost layer to the innermost layer.

// Function to perform a spiral order traversal of the given matrix.
// Intuition:
// - Initialize four pointers (top, bottom, left, right) to track the boundaries of the current layer.
// - Traverse the outermost layer in a clockwise direction, starting from the top-left corner.
// - Move from left to right, then from top to bottom, then from right to left, and finally from bottom to top.
// - Update the boundary pointers after completing each traversal direction.
// - Repeat the process for the inner layers until all elements are traversed.
// Approach:
// - Use four pointers (top, bottom, left, right) to represent the top, bottom, left, and right boundaries of the current layer.
// - Iterate until the top and bottom pointers cross each other and the left and right pointers cross each other.
// - Within each iteration, traverse the current layer in a clockwise direction and add elements to the result vector.
// Time complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
//   - We visit each element of the matrix once.
// Space complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
//   - Additional space is used to store the result vector.
vector<int> spiralOrder(vector<vector<int>> &mat)
{
    vector<int> ans;       // Result vector to store the elements in spiral order.
    int n = mat.size();    // Number of rows in the matrix.
    int m = mat[0].size(); // Number of columns in the matrix.

    int top = 0, bottom = n - 1, left = 0, right = m - 1; // Initialize boundary pointers.

    // Traverse the matrix in a clockwise spiral order.
    while (top <= bottom && left <= right)
    {
        // Traverse from left to right.
        for (int col = left; col <= right && top <= bottom; col++)
        {
            ans.push_back(mat[top][col]);
        }
        top++; // Move the top boundary down.

        // Traverse from top to bottom.
        for (int row = top; row <= bottom && left <= right; row++)
        {
            ans.push_back(mat[row][right]);
        }
        right--; // Move the right boundary left.

        // Traverse from right to left.
        for (int col = right; col >= left && top <= bottom; col--)
        {
            ans.push_back(mat[bottom][col]);
        }
        bottom--; // Move the bottom boundary up.

        // Traverse from bottom to top.
        for (int row = bottom; row >= top && left <= right; row--)
        {
            ans.push_back(mat[row][left]);
        }
        left++; // Move the left boundary right.
    }
    return ans; // Return the result vector containing elements in spiral order.
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; // Example matrix.
    vector<int> res = spiralOrder(matrix);                                      // Perform spiral order traversal.

    // Output the elements in spiral order.
    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}
