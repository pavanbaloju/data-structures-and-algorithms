#include <iostream>
#include <vector>
#include <set>
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

// o(mn) & o(m + n)
void setZeroes(vector<vector<int>> &matrix)
{
    set<int> rows, cols;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (rows.count(i) || cols.count(j))
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// o(mn) && o(1)
void setZeroesOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool col0 = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j == 0)
                    col0 = true;
                else
                    matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (col0 == true)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix =
        {{0, 1, 2, 0},
         {3, 4, 5, 2},
         {1, 3, 1, 5}};
    setZeroesOpt(matrix);
    print(matrix);
    return 0;
}