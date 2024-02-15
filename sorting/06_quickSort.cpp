#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement Quick Sort to sort a given array of integers in non-decreasing order.

// Intuition:
// Quick Sort is a divide-and-conquer algorithm that selects a 'pivot' element and partitions
// the array into two subarrays such that elements less than the pivot come before it, and
// elements greater than the pivot come after it. It then recursively sorts the subarrays.

// DSA Strategy:
// Quick Sort

// Approach:
// 1. Implement a function 'partition' to partition the array around a pivot element.
//    a. Select the first element of the array as the pivot.
//    b. Move all elements less than or equal to the pivot to its left and greater elements to its right.
//    c. Return the index of the pivot after partitioning.
// 2. Implement a recursive function 'quickSort' to sort the array using Quick Sort.
//    a. Select a pivot using the 'partition' function.
//    b. Recursively sort the left and right subarrays.
// 3. In the main function, initialize the array and call 'quickSort' to sort the array.

// Time Complexity: O(n log n) on average, O(n^2) worst-case (due to poor pivot selection).
// Space Complexity: O(log n) due to the recursive stack space used for function calls.

// Function to partition the array around a pivot element.
int partition(vector<int> &nums, int start, int end)
{
    int pivot = nums[start]; // Select the first element as the pivot.
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] <= pivot)
        {
            count++; // Count the number of elements less than or equal to the pivot.
        }
    }

    int pivotIndex = start + count; // Calculate the pivot index after partitioning.
    swap(nums[pivotIndex], nums[start]); // Move the pivot element to its correct position.

    int i = start, j = end;
    // Move elements less than or equal to the pivot to its left and greater elements to its right.
    while (i < pivotIndex && j > pivotIndex)
    {
        while (nums[i] <= pivot)
        {
            i++;
        }
        while (nums[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(nums[i++], nums[j--]); // Swap out-of-place elements.
        }
    }
    return pivotIndex; // Return the pivot index after partitioning.
}

// Recursive function to sort the array using Quick Sort.
void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return; // Base case: If the subarray contains only one element or is empty, no need to sort.
    }

    int pivotIndex = partition(nums, start, end); // Select a pivot and partition the array.
    // Recursively sort the left and right subarrays.
    quickSort(nums, start, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, end);
}

// Main function to demonstrate Quick Sort.
int main()
{
    // Initialize the input array.
    vector<int> nums = {9, 98, 87, 6, 35, 4, 11, 23, 67, 99};

    // Sort the array using Quick Sort.
    quickSort(nums, 0, nums.size() - 1);

    // Print the sorted array.
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
