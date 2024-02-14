#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
// Problem Statement:
// Implement the Selection Sort algorithm to sort an array of integers in ascending order.

// Intuition:
// Iterate over the array and find the minimum element in the unsorted portion. Swap it with the first element of the unsorted portion.

// DSA Strategy:
// Sorting

// Approach:
// 1. Iterate over the array.
// 2. Find the minimum element in the unsorted portion.
// 3. Swap the minimum element with the first element of the unsorted portion.

// Time Complexity: O(N^2), where N is the number of elements in the array.
// Space Complexity: O(1)

void selectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int minIdx = i;
        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIdx])
            {
                minIdx = j;
            }   
        }
        // Swap the minimum element with the first element of the unsorted portion
        swap(nums[minIdx], nums[i]);
    }
}

// Bubble Sort
// Problem Statement:
// Implement the Bubble Sort algorithm to sort an array of integers in ascending order.

// Intuition:
// Compare adjacent elements and swap them if they are in the wrong order. Repeat this process until the array is sorted.

// DSA Strategy:
// Sorting

// Approach:
// 1. Iterate over the array and compare adjacent elements.
// 2. If they are in the wrong order, swap them.
// 3. Repeat this process until the array is sorted.

// Time Complexity: O(N^2), where N is the number of elements in the array.
// Space Complexity: O(1)

void bubbleSort(vector<int> &nums)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        // Compare adjacent elements and swap them if necessary
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    }
}

// Insertion Sort
// Problem Statement:
// Implement the Insertion Sort algorithm to sort an array of integers in ascending order.

// Intuition:
// Iterate over the array. For each element, insert it into its correct position in the sorted portion of the array.

// DSA Strategy:
// Sorting

// Approach:
// 1. Iterate over the array.
// 2. For each element, iterate backward and insert it into its correct position in the sorted portion.

// Time Complexity: O(N^2), where N is the number of elements in the array.
// Space Complexity: O(1)

void insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int j = i;
        // Insert nums[i] into its correct position in the sorted portion
        while (j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
}

// Main function
int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    // Sort the array using Selection Sort
    selectionSort(colors);
    // Print the sorted array
    for(int x:colors) cout<<x<<" ";
    return 0;
}
