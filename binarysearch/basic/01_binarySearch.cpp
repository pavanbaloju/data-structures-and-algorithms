#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted (in ascending order) integer array 'nums' of 'n' elements and a 'target' value, 
// return the index of 'target' in 'nums' if it exists, otherwise return -1.

// Intuition:
// Since the array is sorted, binary search is an efficient approach to find the target value.

// DSA Strategy:
// Binary Search

// Approach 1: Recursive Binary Search

// Approach:
// 1. Define a function 'binarySearchRecursive' that takes the sorted array 'nums', the 'target' value,
//    and the indices 'start' and 'end' as parameters.
// 2. If 'start' is greater than 'end', return -1 (indicating that the target is not found).
// 3. Calculate 'mid' as the average of 'start' and 'end'.
// 4. If 'nums[mid]' is equal to 'target', return 'mid' (indicating that the target is found).
// 5. If 'target' is greater than 'nums[mid]', recursively call 'binarySearchRecursive' with parameters 
//    'nums', 'target', 'mid + 1', and 'end' (search in the right half of the array).
// 6. Otherwise, recursively call 'binarySearchRecursive' with parameters 'nums', 'target', 'start', 
//    and 'mid - 1' (search in the left half of the array).

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(log n) due to the recursive calls on the stack.

// Function to perform binary search recursively
int binarySearchRecursive(vector<int> &nums, int target, int start, int end)
{
    if (start > end)
    {
        return -1; // If start exceeds end, target not found
    }
    int mid = (start + end) / 2; // Calculate mid index
    if (nums[mid] == target)
    {
        return mid; // If target found at mid index, return mid
    }
    else if (target > nums[mid])
    {
        return binarySearchRecursive(nums, target, mid + 1, end); // Search in right half
    }
    else
    {
        return binarySearchRecursive(nums, target, start, mid - 1); // Search in left half
    }
}

// Approach 2: Iterative Binary Search

// Approach:
// 1. Define a function 'binarySearchIterative' that takes the sorted array 'nums', the 'target' value,
//    and the indices 'start' and 'end' as parameters.
// 2. Use a while loop to continue searching until 'start' becomes greater than 'end'.
// 3. Inside the loop, calculate 'mid' as the average of 'start' and 'end'.
// 4. If 'nums[mid]' is equal to 'target', return 'mid' (indicating that the target is found).
// 5. If 'target' is greater than 'nums[mid]', update 'start' to 'mid + 1' (search in the right half of the array).
// 6. If 'target' is less than 'nums[mid]', update 'end' to 'mid - 1' (search in the left half of the array).
// 7. If the loop exits without finding the target, return -1.

// Time Complexity: O(log n), where 'n' is the size of the array.
// Space Complexity: O(1).

// Function to perform binary search iteratively
int binarySearchIterative(vector<int> &nums, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate mid index
        if (nums[mid] == target)
        {
            return mid; // If target found at mid index, return mid
        }
        else if (target > nums[mid])
        {
            start = mid + 1; // Search in right half
        }
        else
        {
            end = mid - 1; // Search in left half
        }
    }
    return -1; // If target not found, return -1
}

// Main function
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6}; // Sorted array
    int target = 3; // Target value to search for

    // Search using recursive binary search
    int result1 = binarySearchRecursive(nums, target, 0, nums.size() - 1);
    cout << "Recursive Binary Search: " << result1 << endl;

    // Search using iterative binary search
    int result2 = binarySearchIterative(nums, target, 0, nums.size() - 1);
    cout << "Iterative Binary Search: " << result2 << endl;

    return 0;
}
