#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted array 'nums', remove the duplicates in-place such that each element appears only once and return the new length.

// Intuition:
// We'll use two pointers to iterate through the array and remove duplicates by overwriting elements.

// DSA Strategy/Pattern:
// Two Pointers, Array Traversal

// Approach:
// Initialize 'left' pointer to 1 (since the first element is always non-duplicate).
// Iterate through the array with 'right' pointer starting from index 1:
//   If the current element is different from the previous one,
//   store it in the position indicated by 'left' and increment 'left'.
// Return the value of 'left', which represents the size of the array without duplicates.

// Complexity:
// Time complexity: O(n) - We traverse the array once.
// Space complexity: O(1) - We perform the removal in-place without using extra space.

// Function to remove duplicates from a sorted array in-place
int removeDuplicates(vector<int> &nums)
{
    int left = 1; // Pointer for the next position to store a non-duplicate element
    int n = nums.size();
    for (int right = 1; right < n; right++)
    {
        // If the current element is different from the previous one,
        // store it in the position indicated by 'left' and increment 'left'.
        if (nums[right] != nums[right - 1])
        {
            nums[left] = nums[right];
            left++;
        }
    }
    return left; // Return the size of the array without duplicates
}

int main()
{
    // Test case
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    // Output the array after removing duplicates
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
