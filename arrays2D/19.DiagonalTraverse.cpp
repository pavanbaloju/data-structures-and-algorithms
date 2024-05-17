#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement:
Given an m x n matrix, return an array of all the elements of the matrix in diagonal order.

Intuition:
Diagonal traversal involves alternating between moving upwards and downwards across the matrix.

DSA Strategy/Pattern:
Matrix traversal

Approach 1:
1. Start from the top-left corner of the matrix.
2. Use a flag `up` to determine the direction of traversal.
3. Traverse the matrix diagonally upwards until reaching the top or right boundary.
4. Then switch to traversing diagonally downwards until reaching the bottom or left boundary.
5. Continue this process until all elements are visited.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
O(m * n) for storing the result.
*/
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

/*
Approach 2:
1. Handle special cases for single row or single column matrices.
2. Use two indices to track the current position in the matrix.
3. Use a flag `isup` to alternate between moving upwards and downwards diagonally.
4. Continue this process until all elements are visited.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
O(m * n) for storing the result.
*/
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

// Function to print the result vector
void printResult(const vector<int> &res, const string &approach)
{
    cout << "Diagonal Order Traversal (" << approach << "): ";
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

int main()
{
    // Test the findDiagonalOrder functions with an example matrix.
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Approach 1: Find diagonal order traversal using the first method.
    vector<int> res1 = findDiagonalOrder(matrix);
    printResult(res1, "Approach 1");

    // Approach 2: Find diagonal order traversal using the second method.
    vector<int> res2 = findDiagonalOrder2(matrix);
    printResult(res2, "Approach 2");

    return 0;
}
