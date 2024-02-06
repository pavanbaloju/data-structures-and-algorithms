#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target element in a sorted 2D matrix using linear search
// Intuition:
// Since each row and each column of the matrix is sorted in ascending order,
// we can start from the top-right corner (or bottom-left corner) and iteratively move
// towards the target by comparing the current element with the target.
// If the current element is equal to the target, return true.
// If the current element is less than the target, move down to the next row.
// If the current element is greater than the target, move left to the previous column.
// Continue this process until the target is found or the indices go out of bounds.
// Approach:
// - Start from the top-right corner of the matrix.
// - While the current element is not out of bounds:
//     - If the current element is equal to the target, return true.
//     - If the current element is less than the target, move down to the next row.
//     - If the current element is greater than the target, move left to the previous column.
// - If the target is not found after traversing the entire matrix, return false.
// Time Complexity: O(m + n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), constant space is used.
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Get the number of rows and columns in the matrix
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Start from the top-right corner of the matrix
    int rowIndex = 0;
    int colIndex = cols - 1;

    // Iterate until the indices are within bounds
    while (rowIndex < rows && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
            return true; // If the current element equals the target, return true

        if (element < target)
        {
            rowIndex++; // If the current element is less than the target, move down to the next row
        }
        else
        {
            colIndex--; // If the current element is greater than the target, move left to the previous column
        }
    }

    return false; // If the target is not found after traversing the entire matrix, return false
}

// Function to search for a target element in a sorted 2D matrix using binary search
// Intuition:
// Since each row and each column of the matrix is sorted in ascending order,
// we can treat the 2D matrix as a 1D array and perform binary search.
// Consider the 2D matrix as a flattened sorted array and perform binary search on it.
// Approach:
// - Perform binary search on the flattened 2D matrix.
// - Convert the mid index to corresponding row and column indices.
// - Compare the target with the element at the mid index.
// - If the target is found, return true.
// - If the target is less than the mid element, search in the left half.
// - If the target is greater than the mid element, search in the right half.
// - Repeat until the target is found or the search space is exhausted.
// Time Complexity: O(log(m*n)), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), constant space is used.
bool searchMatrixBS(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target = 16;
    cout << "Using linear search from top-right corner: ";
    searchMatrix(matrix, target) ? cout << "Found\n" : cout << "Not found\n";

    cout << "Using binary search: ";
    searchMatrixBS(matrix, target) ? cout << "Found\n" : cout << "Not found\n";

    return 0;
}
