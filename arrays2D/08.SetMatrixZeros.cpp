#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem Statement:
// Given an m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Intuition:
// To efficiently set the entire row and column to 0 when a 0 is encountered, we can mark the first element
// of the corresponding row and column as a flag indicating that the whole row/column should be zeroed out.

// DSA Strategy/Pattern: Matrix Manipulation

// Approach 1: Using Additional Storage
// - Explanation:
//   - Use sets to store the indices of rows and columns that contain 0s.
//   - Iterate through the matrix and mark the rows and columns.
//   - Iterate through the matrix again and set the elements to 0 based on the marked rows and columns.
// - Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
// - Space Complexity: O(m+n), where m is the number of rows and n is the number of columns.

void setZeroes(vector<vector<int>> &matrix)
{
    set<int> rows, cols; // Sets to store indices of rows and columns containing 0s.

    // Iterate through the matrix to find 0s and mark their rows and columns.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.insert(i); // Mark row containing 0.
                cols.insert(j); // Mark column containing 0.
            }
        }
    }

    // Iterate through the matrix again to set 0s in marked rows and columns.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (rows.count(i) || cols.count(j))
            {
                matrix[i][j] = 0; // Set 0 if row or column is marked.
            }
        }
    }
}

// Approach 2: Optimized In-Place
// - Explanation:
//   - Use the first row and first column as markers to indicate if a row or column should be zeroed.
//   - Use a separate flag to handle the first column since it also serves as a marker.
// - Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
// - Space Complexity: O(1)

void setZeroesOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // Number of rows.
    int m = matrix[0].size(); // Number of columns.
    bool col0 = false;        // Flag to track if first column needs to be zeroed.

    // Mark rows and columns with 0s using the first row and column.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // Mark corresponding row.
                if (j == 0)
                    col0 = true; // Mark if first column contains 0.
                else
                    matrix[0][j] = 0; // Mark corresponding column.
            }
        }
    }

    // Set 0s in the matrix based on marks made in the first row and column.
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0; // Set 0 if corresponding row or column is marked.
            }
        }
    }

    // Handle first row and column separately.
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0; // Set entire first row to 0.
        }
    }
    if (col0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][0] = 0; // Set entire first column to 0 if needed.
        }
    }
}

// Function to print the elements of a matrix.
void print(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (int x : row)
            cout << x << " "; // Print each element separated by space.
        cout << endl;         // Move to the next row.
    }
}

// Main function
int main()
{
    // Sample matrix
    vector<vector<int>> matrix =
        {{0, 1, 2, 0},
         {3, 4, 5, 2},
         {1, 3, 1, 5}};

    cout << "Original Matrix:" << endl;
    print(matrix);
    cout << endl;

    // Call the optimized setZeroes function to modify the matrix in-place.
    setZeroesOpt(matrix);

    cout << "Modified Matrix:" << endl;
    // Print the modified matrix.
    print(matrix);

    return 0;
}
