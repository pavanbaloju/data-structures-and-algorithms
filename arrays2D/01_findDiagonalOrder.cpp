#include <iostream>
#include <vector>
using namespace std;

// 1, 2, 3
// 4, 5, 6
// 7, 8, 9

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int r = 0, c = 0;
    int m = mat.size(), n = mat[0].size(), i = 0;
    vector<int> res(m * n);
    bool up = true;
    if (!m || !n)
        return res;
    while (r < m && c < n)
    {
        if (up)
        {
            while (r > 0 && c < n - 1)
            {
                res[i++] = mat[r][c];
                r--;
                c++;
            }
            res[i++] = mat[r][c];
            if (c == n - 1)
            {
                r++;
            }
            else
            {
                c++;
            }
        }
        else
        {
            while (r < m - 1 && c > 0)
            {
                res[i++] = mat[r][c];
                r++;
                c--;
            }
            res[i++] = mat[r][c];
            if (r == m - 1)
            {
                c++;
            }
            else
            {
                r++;
            }
        }
        up = !up;
    }

    return res;
}

vector<int> findDiagonalOrder2(vector<vector<int>> &mat)
{
    if (mat.size() == 1)
        return mat[0];
    if (mat[0].size() == 1)
    {
        vector<int> vc;
        for (int i = 0; i < mat.size(); i++)
        {
            vc.push_back(mat[i][0]);
        }
        return vc;
    }

    int i = 0, j = 1;
    vector<int> vc;
    vc.push_back(mat[0][0]);
    bool isup = false;
    while (i < mat.size() && j < mat[0].size())
    {
        vc.push_back(mat[i][j]);
        if (isup)
        {
            if (i == 0 || j == mat[0].size() - 1)
                isup = false;

            if (i == 0 && j != mat[0].size() - 1)
                j++;
            else if (j == mat[0].size() - 1)
            {
                i++;
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {
            if (j == 0 || i == mat.size() - 1)
                isup = true;

            if (j == 0 && i != mat.size() - 1)
                i++;
            else if (i == mat.size() - 1)
            {
                j++;
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    return vc;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix = {{2}, {3}};
    vector<int> res = findDiagonalOrder(matrix);
    for (int x : res)
        cout << x << " ";
}