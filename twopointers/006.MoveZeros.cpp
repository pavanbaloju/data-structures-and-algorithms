#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array 'nums', move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Intuition:
// We'll use a two-pointer approach where one pointer iterates through the array and another pointer places non-zero elements.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// Initialize two pointers, 'left' and 'right', both pointing to the start of the array.
// Iterate through the array with the 'right' pointer:
//   If the current element is non-zero, move it to the position indicated by 'left' and increment 'left'.
// After iterating through the array, fill the remaining positions from 'left' to the end with zeroes.

// Complexity:
// Time complexity: O(n) - We traverse the array once.
// Space complexity: O(1) - We perform the operation in-place without using extra space.

// Function to move all zeroes to the end of the array while maintaining the order of non-zero elements.
void moveZeroes(vector<int> &nums)
{
    // Two-pointer approach: 'right' for iterating through the array, 'left' for placing non-zero elements.
    int right = 0, left = 0, n = nums.size();

    // Iterate through the array with the 'right' pointer.
    while (right < n)
    {
        // If the current element is non-zero, move it to the position indicated by 'left'.
        if (nums[right] != 0)
        {
            nums[left] = nums[right];
            left++;
        }
        right++;
    }

    // Fill the remaining positions from 'left' to the end with zeroes.
    while (left < n)
    {
        nums[left++] = 0;
    }
}

int main()
{
    // Example usage
    vector<int> arr = {0, 1, 0, 3, 12};

    // Move zeroes to the end of the array.
    moveZeroes(arr);

    // Output the modified array.
    for (int a : arr)
        cout << a << " ";

    return 0;
}
