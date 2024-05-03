#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array 'nums' and a value 'val', remove all instances of that value in-place and return the new length.

// Intuition:
// The goal is to remove all occurrences of a specified value from an array.

// Approach 1: Using Swapping
// We'll use two pointers to iterate through the array and swap elements to remove the target value.

// Approach 2: In-place Removal
// We'll iterate through the array and overwrite elements with non-target elements to remove occurrences of the target value.

// DSA Strategy/Pattern:
// Two Pointers, Array Traversal

// Approach 1:
// 1. Initialize 'start' and 'end' pointers to the start and end indices of the array, respectively.
// 2. Iterate until 'start' is less than or equal to 'end':
//    a. If 'nums[start]' is equal to 'val', swap 'nums[start]' with 'nums[end]', decrement 'end' and 'size'.
//    b. If 'nums[start]' is not equal to 'val', increment 'start'.
// 3. Return 'size' as the new length of the modified array.

// Approach 2:
// 1. Initialize 'start' pointer to the index for the updated array.
// 2. Iterate through the original array ('right' pointer):
//    a. If 'nums[right]' is not equal to 'val', copy 'nums[right]' to 'nums[start]' and increment 'start'.
// 3. Return 'start' as the new length of the modified array.

// Complexity:
// Time complexity: O(n) - We traverse the array once.
// Space complexity: O(1) - We perform the removal in-place without using extra space.

// Function to remove all occurrences of a specified value from an array by swapping elements
int removeElement(vector<int> &nums, int val)
{
    int size = nums.size(); // Get the size of the array
    int end = size - 1;     // Initialize the end pointer to the last index of the array
    int start = 0;              // Initialize the start pointer to the first index of the array

    // Iterate through the array using two pointers
    while (start <= end)
    {
        // If the current element is equal to the target value, swap it with the element at the end
        // Decrement the size of the array to exclude the swapped element
        if (nums[start] == val)
        {
            swap(nums[start], nums[end]);
            end--;
            size--;
        }
        else
        {
            // Move the start pointer to the next element if the current element is not equal to the target value
            start++;
        }
    }

    return size; // Return the size of the modified array
}

// Function to remove all occurrences of a specified value from an array in place
int removeElementInPlace(vector<int> &nums, int val)
{
    int size = nums.size(); // Get the size of the array
    int start = 0;              // Initialize the index for the updated array

    // Iterate through the original array
    for (int right = 0; right < size; right++)
    {
        // If the current element is not equal to the target value, copy it to the updated array
        if (nums[right] != val)
        {
            nums[start] = nums[right];
            start++;
        }
    }

    return start; // Return the size of the updated array
}

int main()
{
    // Test cases
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

    // Call the function to remove the target value from the array
    int newSize = removeElementInPlace(nums, 2);

    // Output the elements of the modified array
    for (int i = 0; i < newSize; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
