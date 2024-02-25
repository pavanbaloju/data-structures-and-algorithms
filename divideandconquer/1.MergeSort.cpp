#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement the merge sort algorithm to sort an array of integers.

// Intuition:
// Merge sort is a divide-and-conquer algorithm that recursively divides the input array
// into two halves, sorts each half, and then merges the sorted halves.

// DSA Strategy:
// Merge Sort

// Approach:
// 1. Implement a merge function to merge two sorted halves of an array.
//    a. Create two temporary vectors 'left' and 'right' to store the elements of the
//       left and right halves.
//    b. Copy the elements from the left half of 'nums' to 'left' and from the right
//       half to 'right'.
//    c. Merge the elements from 'left' and 'right' back into 'nums' in sorted order.
// 2. Implement the mergeSort function to recursively divide and merge the array.
//    a. If 'start' is greater than or equal to 'end', return, as an array with one
//       element is considered sorted.
//    b. Calculate the middle index 'mid' as the average of 'start' and 'end'.
//    c. Recursively call mergeSort on the left and right halves of the array.
//    d. Merge the sorted left and right halves using the merge function.

// Time Complexity: O(n log n), where 'n' is the size of the array.
// Space Complexity: O(n), additional space for the temporary vectors.

// Function to merge two sorted halves of the array
void merge(vector<int> &nums, int start, int end)
{
    // Calculate the middle index
    int mid = (start + end) / 2;
    // Calculate the lengths of the left and right halves
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temporary vectors to store the left and right halves
    vector<int> left = vector<int>(len1);
    vector<int> right = vector<int>(len2);

    // Copy elements from the left half of 'nums' to 'left'
    for (int i = 0; i < len1; i++)
    {
        left[i] = nums[start + i];
    }
    // Copy elements from the right half of 'nums' to 'right'
    for (int i = 0; i < len2; i++)
    {
        right[i] = nums[mid + 1 + i];
    }

    int il = 0, ir = 0, idx = start;
    // Merge the sorted halves
    while (il < len1 && ir < len2)
    {
        // Compare elements from 'left' and 'right' and merge them into 'nums'
        if (left[il] <= right[ir])
        {
            nums[idx++] = left[il++];
        }
        else
        {
            nums[idx++] = right[ir++];
        }
    }

    // Copy the remaining elements from 'left' to 'nums'
    while (il < len1)
    {
        nums[idx++] = left[il++];
    }

    // Copy the remaining elements from 'right' to 'nums'
    while (ir < len2)
    {
        nums[idx++] = right[ir++];
    }
}

// Function to perform merge sort on the array
void mergeSort(vector<int> &nums, int start, int end)
{
    // Base case: if 'start' is greater than or equal to 'end', return
    if (start >= end)
    {
        return;
    }

    // Calculate the middle index
    int mid = (start + end) / 2;
    // Recursively call mergeSort on the left and right halves
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    // Merge the sorted halves
    merge(nums, start, end);
}

int main()
{
    // Input array to be sorted
    vector<int> nums = {9, 8, 7, 6, 5, 4};
    // Perform merge sort on the array
    mergeSort(nums, 0, nums.size() - 1);

    // Output the sorted array
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
