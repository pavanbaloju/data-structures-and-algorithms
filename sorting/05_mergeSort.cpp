#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement Merge Sort to sort a given array of integers in non-decreasing order.

// Intuition:
// Merge Sort is a divide-and-conquer algorithm that recursively divides the array into two halves,
// sorts each half separately, and then merges the sorted halves.

// DSA Strategy:
// Merge Sort

// Approach:
// 1. Implement a function 'merge' to merge two sorted subarrays into a single sorted array.
//    a. Divide the array into two halves based on the middle index.
//    b. Merge the left and right halves while maintaining the order.
// 2. Implement a recursive function 'mergeSort' to sort the array using Merge Sort.
//    a. Divide the array into two halves recursively until each subarray contains only one element.
//    b. Merge the sorted halves using the 'merge' function.
// 3. In the main function, initialize the array and call 'mergeSort' to sort the array.

// Time Complexity: O(n log n), where n is the number of elements in the array.
//                  The 'merge' operation takes O(n) time, and there are O(log n) levels of recursion.
// Space Complexity: O(n), as additional space is used for creating temporary arrays during the merge operation.

// Function to merge two sorted subarrays into a single sorted array.
void merge(vector<int> &nums, int start, int end)
{
    // Calculate the middle index of the array.
    int mid = (start + end) / 2;
    // Calculate the lengths of the left and right subarrays.
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temporary arrays to store the left and right subarrays.
    vector<int> left(len1);
    vector<int> right(len2);

    // Copy elements from the original array to the left and right subarrays.
    for (int i = 0; i < len1; i++)
        left[i] = nums[start + i];

    for (int i = 0; i < len2; i++)
        right[i] = nums[mid + 1 + i];

    // Merge the left and right subarrays while maintaining the order.
    int il = 0, ir = 0, idx = start;
    while (il < len1 && ir < len2)
    {
        if (left[il] <= right[ir])
            nums[idx++] = left[il++]; // Copy the smaller element from the left subarray.
        else
            nums[idx++] = right[ir++]; // Copy the smaller element from the right subarray.
    }

    // Copy the remaining elements from the left subarray, if any.
    while (il < len1)
        nums[idx++] = left[il++];

    // Copy the remaining elements from the right subarray, if any.
    while (ir < len2)
        nums[idx++] = right[ir++];
}

// Recursive function to sort the array using Merge Sort.
void mergeSort(vector<int> &nums, int start, int end)
{
    // Base case: If the subarray contains only one element or is empty, no need to sort.
    if (start >= end)
        return;

    // Calculate the middle index of the subarray.
    int mid = (start + end) / 2;

    // Recursively sort the left and right halves of the array.
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    // Merge the sorted halves using the 'merge' function.
    merge(nums, start, end);
}

// Main function to demonstrate Merge Sort.
int main()
{
    // Initialize the input array.
    vector<int> nums = {9, 8, 7, 6, 5, 4};

    // Sort the array using Merge Sort.
    mergeSort(nums, 0, nums.size() - 1);

    // Print the sorted array.
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
