#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// Intuition:
// Rotating a matrix by 90 degrees can be done in two main steps:
// 1. Transpose the matrix.
// 2. Reverse each row of the transposed matrix.

// DSA Strategy/Pattern: Matrix manipulation

// Approach 1: Rotating the matrix using an auxiliary matrix
// 1. Create an empty matrix of the same size.
// 2. Traverse the original matrix and place each element in its new position in the auxiliary matrix.
// 3. Copy the auxiliary matrix back to the original matrix.

// Time Complexity: O(N^2), where N is the number of rows (or columns) of the matrix.
// Space Complexity: O(N^2), for the auxiliary matrix.

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();                                                               // Get the size of the matrix
    vector<vector<int>> rotated = vector<vector<int>>(n, vector<int>(matrix[0].size())); // Create an auxiliary matrix

    for (int row = 0; row < n; row++)
    { // Iterate through each row
        for (int col = 0; col < rotated[0].size(); col++)
        {                                                 // Iterate through each column
            rotated[col][row] = matrix[n - 1 - row][col]; // Place elements in the new position
        }
    }
    matrix = rotated; // Copy the rotated matrix back to the original matrix
}

// Approach 2: Rotating the matrix in place
// 1. Transpose the matrix (swap rows with columns).
// 2. Reverse each row of the transposed matrix.

// Time Complexity: O(N^2), where N is the number of rows (or columns) of the matrix.
// Space Complexity: O(1), as no extra space is used other than a few variables.

void rotateInplace(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // Get the size of the matrix

    // Transpose the matrix
    for (int row = 0; row < n - 1; row++)
    { // Iterate through each row (up to n-1)
        for (int col = row + 1; col < n; col++)
        {                                             // Iterate through each column (starting from row+1)
            swap(matrix[row][col], matrix[col][row]); // Swap elements to transpose
        }
    }

    // Reverse each row
    for (int row = 0; row < n; row++)
    {                                // Iterate through each row
        int left = 0, right = n - 1; // Initialize pointers for the start and end of the row
        while (left < right)
        {                                                    // While the pointers haven't met
            swap(matrix[row][left++], matrix[row][right--]); // Swap elements and move pointers inward
        }
    }
}

// Function to print the elements of a matrix
void print(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    { // Iterate through each row
        for (int x : row)
        {                     // Iterate through each element in the row
            cout << x << " "; // Print the element
        }
        cout << endl; // Print a newline after each row
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    cout << "Original Matrix:" << endl;
    print(matrix); // Print the original matrix

    // Rotate the matrix using an auxiliary matrix
    rotate(matrix);
    cout << "Matrix after rotating using an auxiliary matrix:" << endl;
    print(matrix); // Print the rotated matrix

    // Rotate the matrix in place
    rotateInplace(matrix);
    cout << "Matrix after rotating in place:" << endl;
    print(matrix); // Print the rotated matrix

    return 0;
}
