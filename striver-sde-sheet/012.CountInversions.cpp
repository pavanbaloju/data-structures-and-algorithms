#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of inversions in an array (Brute Force Approach)
// Intuition:
// The brute force approach involves iterating through each pair of elements in the array
// and counting the number of inversions.
// Approach:
// - Initialize a count variable to 0.
// - Use nested loops to iterate through each pair of elements in the array.
// - For each pair (i, j), if nums[i] > nums[j], increment the count.
// - Return the count of inversions.
// Time Complexity: O(n^2), where n is the size of the array.
// Space Complexity: O(1), no extra space used.
int numberOfInversions(vector<int> &nums)
{
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
                count++;
        }
    }
    return count;
}

// Function to merge two sorted halves of an array and count inversions (Merge Sort Approach)
// Intuition:
// The merge sort approach divides the array into two halves, sorts them recursively,
// and then merges them while counting the inversions.
// Approach:
// - Divide the array into two halves recursively until each half has only one element.
// - Merge the sorted halves while counting inversions.
// - During merging, if an element from the right half is smaller than an element from the left half,
//   it forms inversions with the remaining elements in the left half.
// - Return the total count of inversions.
// Time Complexity: O(n log n), where n is the size of the array.
// Space Complexity: O(n), additional space required for temporary arrays during merging.
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0; // Modification 1: Initialize inversion count.

    // Merge the two halves while counting inversions.
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
            count += (mid - left + 1); // Modification 2: Update inversion count.
            right++;
        }
    }

    // Copy remaining elements from left half, if any.
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half, if any.
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array.
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count; // Modification 3: Return inversion count.
}

// Function to perform merge sort and count inversions
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;

    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);      // Recursively sort left half.
    count += mergeSort(arr, mid + 1, high); // Recursively sort right half.
    count += merge(arr, low, mid, high);    // Merge two sorted halves and count inversions.
    return count;
}

// Function to count the number of inversions in an array (Optimal Merge Sort Approach)
// Intuition:
// The optimal merge sort approach efficiently counts inversions while performing merge operation.
// Approach:
// - Implement merge sort algorithm with an additional count variable to track inversions during merging.
// - Return the total count of inversions.
// Time Complexity: O(n log n), where n is the size of the array.
// Space Complexity: O(n), additional space required for temporary arrays during merging.
int numberOfInversionsOptimal(vector<int> &a)
{
    int n = a.size();
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};

    // Using Brute Force Approach
    cout << "Number of inversions (Brute Force): " << numberOfInversions(nums) << endl;

    // Using Optimal Merge Sort Approach
    cout << "Number of inversions (Optimal Merge Sort): " << numberOfInversionsOptimal(nums) << endl;

    return 0;
}
