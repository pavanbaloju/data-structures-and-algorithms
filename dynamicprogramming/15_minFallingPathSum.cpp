#include <vector>
#include <iostream>
using namespace std;

// memo
int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return INT_MAX;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = getMinUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = getMinUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = getMinUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
}

int getMinPathSumMemo(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        int ans = getMinUtil(n - 1, j, m, matrix, dp);
        mini = min(mini, ans);
    }
    return mini;
}

//table
int getMinPathSumTable(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = dp[i - 1][j];
            int leftDiagonal = INT_MAX;
            if (j - 1 >= 0)
            {
                leftDiagonal = dp[i - 1][j - 1];
            }

            int rightDiagonal = INT_MAX;
            if (j + 1 < m)
            {
                rightDiagonal = dp[i - 1][j + 1];
            }
            dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
        }
    }

    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}


//opt
int getMinPathSumOpt(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);
    vector<int> cur(m, 0);
    prev = matrix[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = prev[j];
            int leftDiagonal = INT_MAX;
            if (j - 1 >= 0)
            {
                leftDiagonal = prev[j - 1];
            }

            int rightDiagonal = INT_MAX;
            if (j + 1 < m)
            {
                rightDiagonal = prev[j + 1];
            }

            cur[j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }

    int mini = INT_MAX;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, prev[j]);
    }
    return mini;
}

int main()
{

    vector<vector<int>> matrix{{2, 1, 3},
                               {6, 5, 4},
                               {7, 8, 9}};

    cout << getMinPathSumMemo(matrix) << endl;
    cout << getMinPathSumTable(matrix) << endl;
    cout << getMinPathSumOpt(matrix) << endl;

    return 0;
}
