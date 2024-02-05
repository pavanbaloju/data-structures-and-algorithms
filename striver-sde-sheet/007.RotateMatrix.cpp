#include <iostream>
#include <vector>
using namespace std;

// Function to print the elements of a matrix
void print(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}

// Function to rotate the matrix by 90 degrees clockwise using brute force method
// Intuition:
// - To rotate the matrix by 90 degrees clockwise, we can first create a new matrix
//   of the same size as the original matrix.
// - Then, we iterate through each element of the original matrix and place it in the
//   corresponding position in the new matrix after rotation.
// - Finally, we update the original matrix with the rotated matrix.
// - This approach requires O(n^2) extra space, where 'n' is the size of the matrix.
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated = vector<vector<int>>(n, vector<int>(matrix[0].size()));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < rotated[0].size(); col++)
        {
            rotated[col][row] = matrix[n - 1 - row][col];
        }
    }
    matrix = rotated;
}

// Function to rotate the matrix by 90 degrees clockwise in place
// Intuition:
// - To rotate the matrix in place, we can perform two operations:
//   1. Transpose the matrix.
//   2. Reverse each row of the transposed matrix.
// - Transposing the matrix swaps elements across the diagonal, and reversing each row
//   ensures the rotation by 90 degrees.
// - This approach modifies the original matrix directly without using extra space.
void rotateInplace(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Transpose the matrix
    for (int row = 0; row < n - 1; row++)
        for (int col = row + 1; col < n; col++)
            swap(matrix[row][col], matrix[col][row]);

    // Reverse each row
    for (int row = 0; row < n; row++)
    {
        int left = 0, right = n - 1;
        while (left < right)
            swap(matrix[row][left++], matrix[row][right--]);
    }
}

int main()
{
    vector<vector<int>> matrix =
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15, 16}};

    // Rotate the matrix in place
    rotateInplace(matrix);

    // Print the rotated matrix
    print(matrix);

    return 0;
}
