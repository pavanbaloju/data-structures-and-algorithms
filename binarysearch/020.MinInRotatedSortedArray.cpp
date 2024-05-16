#include <iostream>
#include <vector>
using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given a rotated sorted array of distinct integers, find the minimum element in the array.

// 2. Add Intuition
// Intuition:
// We can use binary search to efficiently find the minimum element in the rotated sorted array.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// Step 1: Initialize start and end pointers to the first and last indices of the array, respectively.
// Step 2: Initialize ans to the maximum possible value.
// Step 3: Perform binary search until start is less than or equal to end.
// Step 4: Calculate the middle index.
// Step 5: If the element at start index is less than or equal to the element at mid index,
//         it means the minimum element lies in the right half. Update ans with the minimum of current ans and the element at start index,
//         and move start pointer to mid + 1.
// Step 6: Otherwise, the minimum element lies in the left half. Update ans with the minimum of current ans and the element at mid index,
//         and move end pointer to mid - 1.
// Step 7: Repeat steps 3-6 until start is less than or equal to end.
// Step 8: Return ans, which contains the minimum element.

// 5. Add time and space complexity
// Time Complexity: O(log n), where n is the size of the array.
// Space Complexity: O(1)

// Function to find the minimum element in a rotated sorted array
int findMin(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    int ans = INT_MAX; // Initialize ans to the maximum possible value
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate the middle index
        // If the element at start index is less than or equal to the element at mid index,
        // it means the minimum element lies in the right half
        if (arr[start] <= arr[mid])
        {
            ans = min(ans, arr[start]); // Update ans with the minimum of current ans and the element at start index
            start = mid + 1; // Move start pointer to mid + 1
        }
        // Otherwise, the minimum element lies in the left half
        else
        {
            ans = min(ans, arr[mid]); // Update ans with the minimum of current ans and the element at mid index
            end = mid - 1; // Move end pointer to mid - 1
        }
    }
    return ans; // Return the minimum element
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3}; // Example rotated sorted array
    int ans = findMin(arr); // Call findMin function to find the minimum element
    cout << "The minimum element is: " << ans << "\n"; // Print the minimum element
    return 0;
}
