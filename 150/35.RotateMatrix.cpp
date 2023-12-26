#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}

// brute force
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(matrix[0].size()));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            mat[j][i] = matrix[n - 1 - i][j];
        }
    }
    matrix = mat;
}

void rotateInplace(vector<vector<int>> &mat)
{
    int n = mat.size();
    //transpose
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    //reverse each row
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = n - 1;
        while (left < right)
            swap(mat[i][left++], mat[i][right--]);
    }
}

int main()
{
    vector<vector<int>> matrix =
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15, 16}};
    rotateInplace(matrix);
    print(matrix);
    return 0;
}