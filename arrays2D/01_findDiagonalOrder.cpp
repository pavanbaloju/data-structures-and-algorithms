#include <iostream>
#include <vector>
using namespace std;

// Function to find the diagonal order traversal of a matrix.
// Intuition:
// The matrix can be traversed diagonally in two directions: upwards or downwards.
// We maintain a flag 'up' to determine the direction of traversal.
// For each diagonal traversal, we move either upwards or downwards, updating row and column indices accordingly.
// Approach:
// - Initialize variables for row (r), column (c), matrix dimensions (m and n), and result vector (res).
// - Initialize an index variable (i) for the result vector and a flag variable (up) for the traversal direction.
// - Iterate through the matrix diagonally until both row and column indices are within bounds.
// - For each diagonal traversal, update row and column indices based on the traversal direction.
// - Append matrix elements to the result vector as per the diagonal traversal.
// - Toggle the 'up' flag to switch between upwards and downwards traversal.
// - Return the result vector containing the diagonal order traversal.
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int r = 0, c = 0;
    int m = mat.size(), n = mat[0].size(), i = 0;
    vector<int> res(m * n);
    bool up = true;

    // Base case: If the matrix is empty, return an empty vector.
    if (!m || !n)
        return res;

    // Iterate through the matrix diagonally until both row and column indices are within bounds.
    while (r < m && c < n)
    {
        if (up)
        {
            // Traverse upwards until reaching the top or right boundary.
            while (r > 0 && c < n - 1)
            {
                res[i++] = mat[r][c];
                r--;
                c++;
            }
            // Append the current element and update indices for next traversal.
            res[i++] = mat[r][c];
            if (c == n - 1)
            {
                r++; // Move to the next row if at the last column.
            }
            else
            {
                c++; // Move to the next column if not at the last column.
            }
        }
        else
        {
            // Traverse downwards until reaching the bottom or left boundary.
            while (r < m - 1 && c > 0)
            {
                res[i++] = mat[r][c];
                r++;
                c--;
            }
            // Append the current element and update indices for next traversal.
            res[i++] = mat[r][c];
            if (r == m - 1)
            {
                c++; // Move to the next column if at the last row.
            }
            else
            {
                r++; // Move to the next row if not at the last row.
            }
        }
        // Toggle the flag to switch between upwards and downwards traversal.
        up = !up;
    }

    return res;
}

// Function to find the diagonal order traversal of a matrix using a different approach.
// Intuition:
// This approach traverses the matrix diagonally, moving either upwards or downwards.
// It maintains a flag 'isup' to determine the direction of traversal.
// The traversal continues until both row and column indices are within bounds.
// Approach:
// - Check for base cases: single row or single column matrix.
// - Initialize variables for row (i), column (j), traversal direction (isup), and result vector (vc).
// - Perform the diagonal traversal, updating row and column indices based on the traversal direction.
// - Append matrix elements to the result vector as per the diagonal traversal.
// - Toggle the 'isup' flag to switch between upwards and downwards traversal.
// - Return the result vector containing the diagonal order traversal.
vector<int> findDiagonalOrder2(vector<vector<int>> &mat)
{
    // Base cases: Single row or single column matrix.
    int m = mat.size(), n = mat[0].size();
    if (n == 1)
        return mat[0];
    if (m == 1)
    {
        vector<int> vc;
        for (int i = 0; i < n; i++)
        {
            vc.push_back(mat[i][0]);
        }
        return vc;
    }

    int i = 0, j = 1;
    vector<int> vc;
    vc.push_back(mat[0][0]);
    bool isup = false;

    // Iterate through the matrix diagonally until both row and column indices are within bounds.
    while (i < m && j < n)
    {
        vc.push_back(mat[i][j]);
        if (isup)
        {
            // Check conditions for upwards traversal and update indices accordingly.
            if (i == 0 || j == n - 1)
                isup = false;

            if (i == 0 && j != n - 1)
                j++; // Move to the next column if at the first row.
            else if (j == n - 1)
            {
                i++; // Move to the next row if at the last column.
            }
            else
            {
                i--; // Move diagonally upwards.
                j++; // Move diagonally upwards.
            }
        }
        else
        {
            // Check conditions for downwards traversal and update indices accordingly.
            if (j == 0 || i == m - 1)
                isup = true;

            if (j == 0 && i != m - 1)
                i++; // Move to the next row if at the first column.
            else if (i == m - 1)
            {
                j++; // Move to the next column if at the last row.
            }
            else
            {
                i++; // Move diagonally downwards.
                j--; // Move diagonally downwards.
            }
        }
    }
    return vc;
}

int main()
{
    // Test the findDiagonalOrder function with an example matrix.
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Approach 1: Find diagonal order traversal using the first method.
    vector<int> res1 = findDiagonalOrder(matrix);
    cout << "Diagonal Order Traversal (Approach 1): ";
    for (int x : res1)
        cout << x << " ";
    cout << endl;

    // Approach 2: Find diagonal order traversal using the second method.
    vector<int> res2 = findDiagonalOrder2(matrix);
    cout << "Diagonal Order Traversal (Approach 2): ";
    for (int x : res2)
        cout << x << " ";
    cout << endl;

    return 0;
}
