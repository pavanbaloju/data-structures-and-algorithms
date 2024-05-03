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
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
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
    merge(nums, start, mid, end);
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
