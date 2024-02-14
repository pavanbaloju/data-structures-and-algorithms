#include <iostream>
#include <vector>
using namespace std;

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

void sort(vector<int> &nums)
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

// Problem Statement:
// Given an array of integers representing the heights of students, determine how many students are not standing in the correct positions.
// A student is considered to be in the correct position if their height is in non-decreasing order from the left to the right.

// Intuition:
// Sort the array of heights using a sorting algorithm (Bubble Sort in this case). Then, compare the sorted heights with the original heights to count the number of mismatches.

// DSA Strategy:
// Sorting

// Approach:
// 1. Copy the original array of heights to a new array.
// 2. Sort the new array using Bubble Sort.
// 3. Compare the sorted heights with the original heights.
// 4. Count the number of mismatches.
// 5. Return the count.

// Time Complexity: O(N^2), where N is the number of heights.
// Space Complexity: O(N), where N is the number of heights.

int heightChecker(vector<int> &heights)
{
    // Copy the original heights to a new array
    vector<int> expected;
    expected = heights;
    // Sort the new array
    sort(expected);

    // Count the number of mismatches
    int count = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != expected[i])
        {
            count++;
        }
    }
    return count;
}

// Main function
int main()
{
    // Input heights
    vector<int> heights = {5, 1, 2, 3, 4};
    // Calculate the number of students not standing in the correct positions
    cout << heightChecker(heights);
    return 0;
}
