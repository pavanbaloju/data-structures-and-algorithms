#include <iostream>
#include <vector>
using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given a 2D matrix where each row is sorted in ascending order and each column is sorted in ascending order, determine if a target value is present in the matrix.

// 2. Add Intuition
// Intuition:
// We can use either a linear search or binary search approach to find the target value in the matrix.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Search Algorithm (Linear Search or Binary Search)

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// Linear Search Approach:
// Step 1: Start from the top-right corner of the matrix.
// Step 2: If the current element equals the target, return true.
// Step 3: If the current element is less than the target, move down to the next row.
// Step 4: If the current element is greater than the target, move left to the previous column.
// Step 5: Repeat steps 2-4 until the indices are within bounds.
// Step 6: If the target is not found after traversing the entire matrix, return false.
//
// Binary Search Approach:
// Step 1: Perform binary search on the flattened 2D matrix.
// Step 2: Convert the mid index to row and column indices.
// Step 3: If the element at the mid index equals the target, return true.
// Step 4: If the element at the mid index is less than the target, adjust the search range accordingly.
// Step 5: If the element at the mid index is greater than the target, adjust the search range accordingly.
// Step 6: Repeat steps 2-5 until the target is found or the search range is exhausted.
// Step 7: If the target is not found after the binary search, return false.

// 5. Add time and space complexity
// Time Complexity: O(n + m), where n is the number of rows and m is the number of columns in the matrix for linear search. 
//                  O(log(n * m)) for binary search.
// Space Complexity: O(1) for both approaches.

// Function to search for a target element in a 2D matrix
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
        // If the current element equals the target, return true
        if (element == target)
            return true;

        // If the current element is less than the target, move down to the next row
        if (element < target)
        {
            rowIndex++;
        }
        // If the current element is greater than the target, move left to the previous column
        else
        {
            colIndex--;
        }
    }

    // If the target is not found after traversing the entire matrix, return false
    return false;
}

// Function to search for a target element in a 2D matrix using binary search
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

        // If the middle element equals the target, return true
        if (matrix[row][col] == target)
            return true;
        // If the middle element is less than the target, search in the right half
        else if (matrix[row][col] < target)
            low = mid + 1;
        // If the middle element is greater than the target, search in the left half
        else
            high = mid - 1;
    }
    // If the target is not found, return false
    return false;
}

int main()
{
    // Define the 2D matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    // Define the target element to search for
    int target = 16;

    // Explanation for Linear Search Approach
    cout << "Using linear search from top-right corner: ";
    searchMatrix(matrix, target) ? cout << "Found\n" : cout << "Not found\n";

    // Explanation for Binary Search Approach
    cout << "Using binary search: ";
    searchMatrixBS(matrix, target) ? cout << "Found\n" : cout << "Not found\n";

    return 0;
}
