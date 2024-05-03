#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array 'nums', rearrange its elements in such a way that all even numbers appear before all odd numbers.

// Intuition:
// We'll use a two-pointer approach where one pointer starts from the beginning and moves forward, 
// and another pointer starts from the end and moves backward. We swap elements if they are in the wrong order.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// Initialize two pointers, 'left' and 'right', pointing to the start and end of the array, respectively.
// Iterate until the two pointers meet:
//   If the left element is odd and the right element is even, swap them and move both pointers.
//   If the left element is even, move the left pointer forward.
//   If the right element is odd, move the right pointer backward.
// Return the sorted array.

// Complexity:
// Time complexity: O(n) - We traverse the array once.
// Space complexity: O(1) - We perform the operation in-place without using extra space.

// Function to rearrange the elements in the array such that all even numbers appear before all odd numbers.
vector<int> sortArrayByParity(vector<int> &nums)
{
    // Initialize two pointers at the start and end of the array
    int left = 0, right = nums.size() - 1;

    // Iterate until the two pointers meet
    while (left < right)
    {
        // If the left element is odd and the right element is even, swap them
        if (nums[left] % 2 == 1 && nums[right] % 2 == 0)
        {
            swap(nums[left], nums[right]);
            left++; // Move left pointer forward
            right--; // Move right pointer backward
        }
        else
        {
            // If the left element is even, move left pointer forward
            if (nums[left] % 2 == 0)
            {
                left++;
            }
            // If the right element is odd, move right pointer backward
            if (nums[right] % 2 == 1)
            {
                right--;
            }
        }
    }
    // Return the sorted array
    return nums;
}

int main()
{
    // Test the function with an example array.
    vector<int> arr = {5, 2, 3, 1, 2, 4};
    sortArrayByParity(arr);

    // Output the sorted array.
    for (int a : arr)
        cout << a << " ";
    return 0;
}
