#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array 'nums', reverse its elements in-place.

// Intuition:
// We can use a two-pointer approach to swap elements from the start and end of the array until they meet at the center.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// 1. Initialize 'start' and 'end' pointers to the start and end indices of the array, respectively.
// 2. Iterate until 'start' is less than 'end':
//    a. Swap elements at indices 'start' and 'end'.
//    b. Move 'start' pointer to the right (increment) and 'end' pointer to the left (decrement).
// 3. Time Complexity: O(n/2) = O(n), where 'n' is the size of the array. We traverse half of the array.
// 4. Space Complexity: O(1) - Constant space is used.

void reverseArray(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        // Swap elements at start and end indices
        swap(nums[start], nums[end]);
        // Move towards the center of the array
        start++;
        end--;
    }
}

// Example usage:
int main()
{
    return 0;
}
