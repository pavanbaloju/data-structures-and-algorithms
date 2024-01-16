#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> &mat, int r, int c, int target)
{
    if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size())
        return false;

    if (target > mat[r][c])
    {
        return search(mat, r + 1, c, target);
    }
    else if (target < mat[r][c])
    {
        return search(mat, r, c - 1, target);
    }
    return true;
}
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    if (mat.size() == 0)
        return false;
    return search(mat, 0, mat[0].size() - 1, target);
}

bool searchMatrixItr(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int rowIndex = 0;
    int colIndex = cols - 1;

    while (rowIndex < rows && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
            return 1;

        if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    vector<vector<int>> empty = vector<vector<int>>();

    cout << searchMatrix(mat, 16) << endl;
    cout << searchMatrix(empty, 16) << endl;
    cout << searchMatrixItr(mat, 16) << endl;
    return 0;
}