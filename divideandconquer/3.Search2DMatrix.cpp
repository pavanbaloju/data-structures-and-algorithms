#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a matrix mat of m x n elements (m rows, n columns), where each row and column 
// is sorted in ascending order, and a target value target, return true if the target 
// value is present in the matrix. Otherwise, return false.

// Intuition:
// Since each row and column of the matrix is sorted, we can start our search from the 
// top-right corner or the bottom-left corner of the matrix. By making use of this 
// sorted property, we can eliminate certain rows or columns at each step of the search, 
// narrowing down our search space.

// DSA Strategy:
// 1. Recursive Approach:
//    - Start the search from the top-right corner of the matrix.
//    - If the target value is greater than the current element, move down one row.
//    - If the target value is less than the current element, move left one column.
//    - Repeat the above steps until the target value is found or until we go out of 
//      bounds of the matrix.
// 2. Iterative Approach:
//    - Start the search from the top-right corner of the matrix.
//    - While the row index is within bounds and the column index is within bounds:
//        - Get the element at the current position.
//        - If the element is equal to the target value, return true.
//        - If the element is less than the target value, move down one row.
//        - If the element is greater than the target value, move left one column.
//    - If the loop exits, return false, indicating that the target value is not present 
//      in the matrix.

// Time Complexity:
// Both approaches have a time complexity of O(m + n), where m is the number of rows and 
// n is the number of columns in the matrix. This is because in the worst case, we may 
// traverse through all the rows and columns once.

// Space Complexity:
// Both approaches have a space complexity of O(1), as they use only a constant amount 
// of extra space for variables.

// Recursive function to search for the target value in the matrix
bool search(vector<vector<int>> &mat, int r, int c, int target) {
    // Base case: If the current row or column index is out of bounds, return false
    if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size())
        return false;

    // If the target value is greater than the current element,
    // move down one row
    if (target > mat[r][c]) {
        return search(mat, r + 1, c, target);
    }
    // If the target value is less than the current element,
    // move left one column
    else if (target < mat[r][c]) {
        return search(mat, r, c - 1, target);
    }
    // If the target value is equal to the current element, return true
    return true;
}

// Function to determine if the target value is present in the matrix using recursion
bool searchMatrix(vector<vector<int>> &mat, int target) {
    // If the matrix is empty, return false
    if (mat.size() == 0)
        return false;
    // Start the search from the top-right corner of the matrix
    return search(mat, 0, mat[0].size() - 1, target);
}

// Function to determine if the target value is present in the matrix using iteration
bool searchMatrixItr(vector<vector<int>> &matrix, int target) {
    // Get the number of rows and columns in the matrix
    int row = matrix.size();
    int col = matrix[0].size();

    // Start the search from the top-right corner of the matrix
    int rowIndex = 0;
    int colIndex = col - 1;

    // While the row index is within bounds and the column index is within bounds
    while (rowIndex < row && colIndex >= 0) {
        // Get the element at the current position
        int element = matrix[rowIndex][colIndex];
        // If the element is equal to the target value, return true
        if (element == target) {
            return true;
        }
        // If the element is less than the target value, move down one row
        else if (element < target) {
            rowIndex++;
        }
        // If the element is greater than the target value, move left one column
        else {
            colIndex--;
        }
    }
    // If the loop exits, return false, indicating that the target value is not present
    // in the matrix
    return false;
}

int main() {
    // Define a matrix
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    
    // Define an empty matrix
    vector<vector<int>> empty = vector<vector<int>>();

    // Test the searchMatrix function with the recursive approach
    cout << searchMatrix(mat, 16) << endl;
    cout << searchMatrix(empty, 16) << endl;

    // Test the searchMatrixItr function with the iterative approach
    cout << searchMatrixItr(mat, 16) << endl;

    return 0;
}
