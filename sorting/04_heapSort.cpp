#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers, sort the array using the heap sort algorithm.

// Intuition:
// Use the max heap data structure to perform heap sort.

// DSA Strategy:
// Sorting, Heap

// Approach:
// 1. Implement the maxHeapify function to maintain the max heap property.
//    a. Find the indices of the left and right children of the current node.
//    b. Determine the largest element among the current node and its children.
//    c. If the largest element is not the current node, swap it with the largest child and recursively call maxHeapify on the affected child.
// 2. Implement the heapify function to convert an array into a max heap.
//    a. Start from the middle of the array and call maxHeapify for each element.
// 3. Implement the heap sort algorithm:
//    a. Convert the input array into a max heap using heapify.
//    b. For each element in the heap (starting from the end), swap it with the first element, decrease the heap size, and call maxHeapify on the root to maintain the max heap property.
// 4. Return the sorted array.

// Time Complexity: O(N log N), where N is the number of elements in the input array.
// Space Complexity: O(1)

// Function to maintain the max heap property
void maxHeapify(vector<int> &values, int heapSize, int index)
{
    // Find the indices of the left and right children
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // Initialize the largest element index as the current index
    int largest = index;
    // Check if the left child is within the heap boundary and greater than the current largest element
    if (left < heapSize && values[left] > values[largest])
    {
        largest = left;
    }
    // Check if the right child is within the heap boundary and greater than the current largest element
    if (right < heapSize && values[right] > values[largest])
    {
        largest = right;
    }
    // If the largest element is not the current node, swap it with the largest child and recursively call maxHeapify
    if (largest != index)
    {
        swap(values[largest], values[index]);
        maxHeapify(values, heapSize, largest);
    }
}

// Function to convert an array into a max heap
void heapify(vector<int> &values)
{
    // Start from the middle of the array and call maxHeapify for each element
    for (int i = values.size() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(values, values.size(), i);
    }
}

// Function to perform heap sort
vector<int> sortArray(vector<int> &nums)
{
    // Convert the input array into a max heap
    heapify(nums);

    // Perform heap sort
    for (int heapSize = nums.size() - 1; heapSize >= 0; heapSize--)
    {
        // Swap the root of the heap with the last element
        swap(nums[0], nums[heapSize]);
        // Restore the max heap property for the remaining heap
        maxHeapify(nums, heapSize, 0);
    }

    return nums;
}

// Main function
int main()
{
    // Input array
    vector<int> nums = {9, 8, 7, 6, 5, 4};
    
    // Sort the array using heap sort
    sortArray(nums);
    
    // Print the sorted array
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
