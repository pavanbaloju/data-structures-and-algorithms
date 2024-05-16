#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 1. Add problem statement
    // Problem Statement:
    // Given a 2D matrix where each row is sorted in ascending order and each column is sorted in ascending order, determine if a target value is present in the matrix.

    // 2. Add Intuition
    // Intuition:
    // We can use binary search to efficiently search for the target element in the matrix.

    // 3. Add the DSA strategy/ pattern used to solve the problem in one line
    // DSA Strategy/Pattern:
    // Binary Search

    // 4. Add approach : clearly explain the algorithm step by step
    // Approach:
    // Step 1: Check if the matrix is empty. If so, return false.
    // Step 2: Initialize low pointer to 0 and high pointer to (m * n) - 1, where m is the number of rows and n is the number of columns.
    // Step 3: Perform binary search on the flattened matrix.
    // Step 4: Calculate middle index and value at middle index.
    // Step 5: If the middle element equals the target, return true.
    // Step 6: If the middle element is less than the target, adjust the search range accordingly to the right half.
    // Step 7: If the middle element is greater than the target, adjust the search range accordingly to the left half.
    // Step 8: Repeat steps 3-7 until low pointer is less than or equal to high pointer.
    // Step 9: If the target is not found, return false.

    // 5. Add time and space complexity
    // Time Complexity: O(log(m * n)), where m is the number of rows and n is the number of columns in the matrix.
    // Space Complexity: O(1)

    // Function to search for a target element in a 2D matrix
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Check if the matrix is empty
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns

        int low = 0, high = m * n - 1; // Initialize low and high pointers

        // Binary search
        while (low <= high)
        {
            int mid = low + (high - low) / 2;      // Calculate middle index
            int midVal = matrix[mid / n][mid % n]; // Calculate value at middle index

            // If target found, return true
            if (midVal == target)
                return true;
            // If middle element is less than target, search in the right half
            else if (midVal < target)
                low = mid + 1;
            // If middle element is greater than target, search in the left half
            else
                high = mid - 1;
        }

        // If target not found
        return false;
    }
};

int main()
{
    // Example usage
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 3;

    Solution sol;
    bool result = sol.searchMatrix(matrix, target);

    // Print result
    if (result)
        cout << "Target found in the matrix." << endl;
    else
        cout << "Target not found in the matrix." << endl;

    return 0;
}
