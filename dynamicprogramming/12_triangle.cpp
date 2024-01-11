#include <iostream>
#include <vector>
using namespace std;

// recursion
int minPathSum(int row, int col, vector<vector<int>> &triangle)
{
    if (row == triangle.size() - 1)
        return triangle[row][col];

    return triangle[row][col] + min(minPathSum(row + 1, col, triangle), minPathSum(row + 1, col + 1, triangle));
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    return minPathSum(0, 0, triangle);
}

// recursion + memo
int minPathSumMemo(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (dp[row][col] != -1)
        return dp[row][col];

    dp[row][col] = triangle[row][col];
    if (row == triangle.size() - 1)
        return dp[row][col];

    return dp[row][col] += min(minPathSumMemo(row + 1, col, triangle, dp), minPathSumMemo(row + 1, col + 1, triangle, dp));
}

int minimumTotalMemo(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
    return minPathSumMemo(0, 0, triangle, dp);
}

// table
int minPathSumTable(vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    int R = triangle.size();
    dp[R - 1] = triangle[R - 1];
    for (int i = R - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}

int minimumTotalTable(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
    return minPathSumTable(triangle, dp);
}

// opt
int minimumTotalOpt(vector<vector<int>> &triangle)
{
    int R = triangle.size();
    vector<int> prevRow = triangle[R - 1];
    for (int i = R - 2; i >= 0; i--)
    {
        vector<int> currRow = vector<int>(i + 1);
        for (int j = i; j >= 0; j--)
        {
            currRow[j] = triangle[i][j] + min(prevRow[j + 1], prevRow[j]);
        }
        prevRow = currRow;
    }
    return prevRow[0];
}

int main()
{
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};

    cout << minimumTotal(triangle) << endl;
    cout << minimumTotalMemo(triangle) << endl;
    cout << minimumTotalTable(triangle) << endl;
    cout << minimumTotalOpt(triangle) << endl;

    return 0;
}