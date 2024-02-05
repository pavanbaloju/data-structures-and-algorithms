#include <iostream>
#include <vector>
#include <set>
using namespace std;

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

// Method 1: Set Zeroes (Brute Force)
// Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(m + n) - The sets 'rows' and 'cols' may store at most m + n elements.
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

// Method 2: Set Zeroes (Optimized)
// Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1) - Only constant extra space is used.
void setZeroesOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // Number of rows.
    int m = matrix[0].size(); // Number of columns.
    bool col0 = false;        // Flag to track if first column needs to be zeroed.

    // Mark rows and columns with 0s using first row and column.
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

    // Set 0s in matrix based on marks made in first row and column.
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

// Main function
int main()
{
    // Sample matrix
    vector<vector<int>> matrix =
        {{0, 1, 2, 0},
         {3, 4, 5, 2},
         {1, 3, 1, 5}};

    // Call the optimized setZeroes function to modify the matrix in-place.
    setZeroesOpt(matrix);

    // Print the modified matrix.
    print(matrix);

    return 0;
}
