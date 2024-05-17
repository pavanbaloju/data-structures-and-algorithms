#include <iostream>
#include <vector>

using namespace std;

// Problem Statement:
// Given a 2D matrix where each row is sorted in ascending order and the first element of each row is greater than the last element of the previous row,
// determine if a target value exists in the matrix.

// Intuition:
// The matrix has a sorted structure, resembling a sorted array that has been split into rows.
// We can exploit this structure to perform a binary search on the flattened matrix.

// DSA Strategy/Pattern: Binary Search

// Approach:
// 1. Initialize left pointer to 0 and right pointer to m * n - 1, where m is the number of rows and n is the number of columns.
// 2. Perform binary search by calculating mid as the average of left and right.
// 3. Convert mid to 2D matrix indices: row = mid / n, col = mid % n.
// 4. Compare the target with the element at matrix[row][col].
// 5. If target matches, return true. If element is less than target, update left = mid + 1. If element is greater than target, update right = mid - 1.
// 6. Repeat steps 2-5 until left > right, indicating that the search space is exhausted.
// 7. Return false, indicating that the target does not exist in the matrix.

// Time Complexity: O(log(m*n)), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), as we are not using any additional space.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1; // Flatten the matrix

        // Perform binary search
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midElement = matrix[mid / n][mid % n]; // Convert flat index to 2D matrix index

            if (midElement == target)
            {
                return true; // Found the target
            }
            else if (midElement < target)
            {
                left = mid + 1; // Target is in the right half
            }
            else
            {
                right = mid - 1; // Target is in the left half
            }
        }

        return false; // Target not found
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;
    cout << "Result: " << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
