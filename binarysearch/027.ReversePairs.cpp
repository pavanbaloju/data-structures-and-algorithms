#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers, find the number of reverse pairs in the array.
// A reverse pair (i, j) is defined as i < j and nums[i] > 2 * nums[j].

// Function to merge two sorted halves of the array and count reverse pairs.
// Intuition:
// - During the merging step of merge sort, we count reverse pairs by comparing elements from the two halves.
// - If nums[left] > 2 * nums[right], then all elements from left to mid are greater than 2 * nums[right].
// - Increment the count by mid - left + 1.
// Approach:
// - Use merge sort to recursively divide the array into halves until each subarray has one element.
// - During the merge step, count reverse pairs and merge the two sorted halves.
// Time complexity: O(n log n), where n is the size of the array.
//   - The merge sort algorithm takes O(n log n) time.
//   - Counting reverse pairs during the merge step takes O(n) time.
// Space complexity: O(n), where n is the size of the array.
//   - Additional space is required for the temporary array used in the merge step.
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge the two sorted halves into a temporary array.
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy the remaining elements from the left half.
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy the remaining elements from the right half.
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements back to the original array.
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

// Function to count the number of reverse pairs across two sorted halves of the array.
// Intuition:
// - We have two sorted halves: the left half from low to mid and the right half from mid+1 to high.
// - For each element in the left half, we find the count of elements in the right half that satisfy the condition arr[i] > 2 * arr[right].
// - We maintain a pointer 'right' to iterate through the right half and increment it until we find an element greater than or equal to 2 * arr[i].
// - The count of reverse pairs for the current element arr[i] is (right - (mid + 1)), where mid is the mid-point between low and high.
// Approach:
// - Initialize the pointer 'right' to mid + 1.
// - Iterate through the left half (from low to mid) and count the number of reverse pairs.
// - Increment the 'right' pointer until it reaches the end of the right half or until the condition arr[i] > 2 * arr[right] is satisfied.
// - Increment the count by (right - (mid + 1)), which represents the number of elements in the right half that form a reverse pair with arr[i].
// - Return the total count of reverse pairs.
// Time complexity: O(n), where n is the size of the subarray (high - low + 1).
//   - The function iterates through the left half once and performs a constant number of operations for each element.
// Space complexity: O(1), no extra space used besides variables.
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1; // Initialize the pointer 'right' to the start of the right half.
    int count = 0;       // Initialize the count of reverse pairs to 0.

    // Iterate through the left half and count reverse pairs.
    for (int i = low; i <= mid; i++)
    {
        // Increment 'right' until we find an element greater than or equal to 2 * arr[i].
        while (right <= high && arr[i] > (long long)2 * arr[right])
            right++;

        // Add the count of reverse pairs for the current element.
        count += (right - (mid + 1));
    }
    return count; // Return the total count of reverse pairs.
}

// Function to perform merge sort and count reverse pairs in the array.
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;

    // Base case: If the range contains one or zero elements, return.
    if (low >= high)
        return count;

    // Divide the array into two halves and recursively sort them.
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);      // left half
    count += mergeSort(arr, mid + 1, high); // right half

    // Count reverse pairs across the sorted halves and merge them.
    count += countPairs(arr, low, mid, high); // Modification
    merge(arr, low, mid, high);               // merging sorted halves

    return count;
}

// Function to compute the number of reverse pairs in the given array.
int reversePairs(vector<int> &arr)
{
    int n = arr.size();
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    // Example usage
    vector<int> arr = {4, 1, 2, 3, 1};
    int siz = arr.size();
    int reversePairCount = reversePairs(arr);
    cout << "The number of reverse pairs is: " << reversePairCount << endl;
    return 0;
}
