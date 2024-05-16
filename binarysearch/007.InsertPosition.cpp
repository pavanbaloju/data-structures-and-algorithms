#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// - Given a sorted array of distinct integers and a target value, return the index if the target is found.
//   If not, return the index where it would be if it were inserted in order.

// Approach: Binary Search
// - Problem Statement: Find the index to insert an element in a sorted array using binary search.
// - Intuition: Use binary search to find the lower bound of the target element.
// - DSA Strategy: Binary Search
// - Approach:
//   - Initialize the lower bound as the last index of the array.
//   - Perform binary search to find the lower bound of the target element.
//   - If the middle element is greater than or equal to the target element, update the lower bound and search in the left half.
//   - Otherwise, search in the right half.
//   - Return the lower bound index where the element should be inserted.
// - Time Complexity: O(log n), where n is the size of the array.
// - Space Complexity: O(1)

// Function to perform binary search and find the index to insert the element
int searchInsert(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int lowerBound = n; // Initialize the lower bound as the last index of the array

    // Binary search loop
    while (low <= high)
    {
        int mid = (low + high) / 2; // Calculate the middle index

        // If the middle element is greater than or equal to the target element
        if (arr[mid] >= x)
        {
            lowerBound = mid; // Update the lower bound to the middle index
            high = mid - 1;   // Move the high pointer to search in the left half
        }
        else
        {
            low = mid + 1; // Move the low pointer to search in the right half
        }
    }
    return lowerBound; // Return the lower bound index where the element should be inserted
}

int main()
{
    vector<int> nums = {1, 3, 4, 6};
    int num = 5;

    cout << "Index to insert " << num << ": " << searchInsert(nums, num) << endl;
    return 0;
}
