#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement:
Given a binary matrix grid, you have to flip the matrix so that the resultant matrix has the maximum score.
Flipping operations include toggling all values in a row or a column. The score of the matrix is the sum of the binary
numbers represented by the rows.

Intuition:
To maximize the score, ensure the most significant bit of each row is 1, and for other columns, maximize the count of 1's.

DSA Strategy/Pattern:
Greedy Algorithm

Approach:
1. Iterate through each row and toggle it if the first element is 0 to ensure the first column has all 1's.
2. For each column (starting from the second), check the count of 1's and 0's, and toggle the column if 1's are less than 0's.
3. Calculate the final score by converting each row from binary to decimal and summing them up.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
O(1), no extra space required other than input.

*/

// Function to maximize the matrix score
int matrixScore(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Step 1: Ensure the first column is all 1's
    for (int i = 0; i < m; ++i)
    {
        if (grid[i][0] == 0)
        {
            // Toggle the entire row
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    // Step 2: For each column from the second onwards, maximize the number of 1's
    for (int j = 1; j < n; ++j)
    {
        int countOnes = 0;
        for (int i = 0; i < m; ++i)
        {
            if (grid[i][j] == 1)
            {
                countOnes++;
            }
        }
        if (countOnes < m - countOnes)
        {
            // Toggle the entire column
            for (int i = 0; i < m; ++i)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    // Calculate the final score
    int score = 0;
    for (int i = 0; i < m; ++i)
    {
        int rowValue = 0;
        for (int j = 0; j < n; ++j)
        {
            rowValue = (rowValue << 1) | grid[i][j];
        }
        score += rowValue;
    }

    return score;
}

int main()
{
    // Example input matrix
    vector<vector<int>> grid = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}};

    // Call the function to maximize the matrix score and print the result
    cout << "Highest possible score: " << matrixScore(grid) << endl;

    return 0;
}
