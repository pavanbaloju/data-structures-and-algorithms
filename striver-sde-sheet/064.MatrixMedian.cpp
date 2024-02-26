#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a matrix of integers where each row is sorted in ascending order, find the median of the matrix.
// The median is the value separating the higher half from the lower half of the numbers.

// Intuition:
// To find the median of the matrix, we can use two approaches:
// 1. Brute force: Flatten the matrix into a single array, sort it, and then find the median.
// 2. Binary search: Use binary search to find the median directly without flattening the matrix.

// DSA Strategy:
// We can solve this problem using two approaches:
// 1. Brute force:
//    - Flatten the matrix into a single array.
//    - Sort the array.
//    - Find the median based on the size of the array.
// 2. Binary search:
//    - Find the minimum and maximum values in the matrix.
//    - Use binary search to find the median value.
//    - Count the number of elements less than or equal to the mid value in the matrix.
//    - Adjust the search space based on the count until we find the median.

// Approach 1: Brute Force
// - Flatten the matrix into a single array.
// - Sort the array.
// - Find the median based on the size of the array.
// Time Complexity: O(m*n*log(m*n)), where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(m*n) for storing the flattened matrix.

// Comments for each line in method

// Function to find the median using brute force
double findMedianBrute(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // Flatten the matrix into a single array
    vector<int> nums;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nums.push_back(matrix[i][j]);
        }
    }

    // Sort the array
    sort(nums.begin(), nums.end());

    // Find the median based on the size of the array
    int size = nums.size();
    if (size % 2 == 0)
    {
        return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
    }
    else
    {
        return nums[size / 2];
    }
}

// Approach 2: Binary Search
// - Find the minimum and maximum values in the matrix.
// - Use binary search to find the median value.
// - Count the number of elements less than or equal to the mid value in the matrix.
// - Adjust the search space based on the count until we find the median.
// Time Complexity: O(m*log(range)), where m is the number of rows and range is the difference between the minimum and maximum values in the matrix.
// Space Complexity: O(1).

// Comments for each line in method

// Function to find the median using binary search
double findMedianBinary(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // Find the minimum and maximum values in the matrix
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][n - 1]);
    }

    // Calculate the desired count to find the median
    int desiredCount = (m * n + 1) / 2;

    // Use binary search to find the median value
    while (minVal < maxVal)
    {
        int midVal = minVal + (maxVal - minVal) / 2;
        int count = 0;

        // Count the number of elements less than or equal to the mid value in the matrix
        for (int i = 0; i < m; i++)
        {
            int noOfElementsLessThanOrEqualToMid = upper_bound(matrix[i].begin(), matrix[i].end(), midVal) - matrix[i].begin();
            count += noOfElementsLessThanOrEqualToMid;
        }

        // Adjust the search space based on the count
        if (count < desiredCount)
        {
            minVal = midVal + 1;
        }
        else
        {
            maxVal = midVal;
        }
    }

    return minVal;
}

// Main function
int main()
{
    // Example usage
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    double median = findMedianBrute(matrix);
    cout << "Median: " << median << endl;
    median = findMedianBinary(matrix);
    cout << "Median (using binary search): " << median << endl;

    return 0;
}
