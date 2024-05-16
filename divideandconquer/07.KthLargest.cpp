#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Problem Statement:
// Given an array of integers nums and an integer k, return the kth largest element in the array.

// Intuition:
// The problem can be solved using the quickselect algorithm, which is a variant of the quicksort algorithm.
// Quickselect is an efficient algorithm to find the kth smallest or largest element in an unordered list.

// DSA Strategy:
// Quickselect

// Approach:
// 1. Adjust k to zero-based index.
// 2. Implement a recursive function 'quickselect' to perform quick select.
//    - Choose a pivot and partition the array around it.
//    - Recursively search in the left or right subarray based on the pivot index.
// 3. Implement a partition function to partition the array around a pivot.
// 4. In the main function, call 'findKthLargest' with the input array and k.
// 5. Print the result.

// Time Complexity: O(n) on average, O(n^2) in the worst case, where n is the size of the array.
// Space Complexity: O(log n) for the recursion stack.

class Solution
{
public:
    // Function to find the kth largest element in the array
    int findKthLargest(vector<int> &nums, int k)
    {
        // Adjust k to zero-based index
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }

private:
    // Recursive function to perform quick select
    int quickselect(vector<int> &nums, int left, int right, int k)
    {
        // Base case: if the subarray has only one element
        if (left == right)
        {
            return nums[left];
        }

        // Partition the array around a pivot
        int pivotIndex = partition(nums, left, right);

        // Check if the pivot is the kth largest element
        if (pivotIndex == k)
        {
            return nums[pivotIndex];
        }
        // If the pivot index is greater than k, search the left subarray
        else if (pivotIndex > k)
        {
            return quickselect(nums, left, pivotIndex - 1, k);
        }
        // If the pivot index is less than k, search the right subarray
        else
        {
            return quickselect(nums, pivotIndex + 1, right, k);
        }
    }

    // Function to partition the array around a pivot
    int partition(vector<int> &nums, int left, int right)
    {
        // Randomly select a pivot index
        int pivotIndex = left + rand() % (right - left + 1);
        int pivotValue = nums[pivotIndex];

        // Move the pivot to the end of the array
        swap(nums[pivotIndex], nums[right]);

        // Partition the array
        int i = left;
        for (int j = left; j < right; ++j)
        {
            if (nums[j] > pivotValue)
            {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[right]);

        return i;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);

    // Output the result
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
