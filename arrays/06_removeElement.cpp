#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Intuition:
// The goal is to remove all occurrences of a specified value from an array.

// Approach 1: Using Swapping
// We'll use two pointers to iterate through the array and swap elements to remove the target value.

// Complexity:
// Time complexity: O(n)
// Space complexity: O(1)

// Function to remove all occurrences of a specified value from an array by swapping elements
int removeElement(vector<int> &nums, int val)
{
    int size = nums.size(); // Get the size of the array
    int end = size - 1;     // Initialize the end pointer to the last index of the array
    int i = 0;              // Initialize the start pointer to the first index of the array

    // Iterate through the array using two pointers
    while (i <= end)
    {
        // If the current element is equal to the target value, swap it with the element at the end
        // Decrement the size of the array to exclude the swapped element
        if (nums[i] == val)
        {
            swap(nums[i], nums[end]);
            end--;
            size--;
        }
        else
        {
            // Move the start pointer to the next element if the current element is not equal to the target value
            i++;
        }
    }

    return size; // Return the size of the modified array
}

// Approach 2: In-place Removal
// We'll iterate through the array and overwrite elements with non-target elements to remove occurrences of the target value.

// Complexity:
// Time complexity: O(n)
// Space complexity: O(1)

// Function to remove all occurrences of a specified value from an array in place
int removeElementInPlace(vector<int> &nums, int val)
{
    int size = nums.size(); // Get the size of the array
    int j = 0;              // Initialize the index for the updated array

    // Iterate through the original array
    for (int i = 0; i < size; i++)
    {
        // If the current element is not equal to the target value, copy it to the updated array
        if (nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }

    return j; // Return the size of the updated array
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
