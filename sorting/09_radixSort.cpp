#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers, implement Radix Sort to sort the elements in non-decreasing order.

// Intuition:
// Radix Sort sorts numbers by processing individual digits, from the least significant digit to the most significant digit. 
// It utilizes a stable sorting algorithm (like Counting Sort) to sort based on each digit.

// DSA Strategy/Pattern:
// Sorting, Radix Sort

// Approach:
// 1. Iterate through each digit from the least significant digit (units place) to the most significant digit.
// 2. Apply Counting Sort for each digit position to sort the elements based on that digit.
// 3. After sorting each digit position, the array becomes sorted based on all digits processed so far.
// 4. Repeat the process for the next significant digit position until all digits are processed.

// Time Complexity: O(d * (n + k)), where d is the number of digits in the maximum element, n is the number of elements, and k is the radix (10 for decimal integers).
// Space Complexity: O(n + k), where n is the number of elements and k is the radix (10 for decimal integers).

// Function to perform Counting Sort based on a specific place value
void countingSort(vector<int> &nums, int placeVal)
{
    int k = 10; // Radix for decimal integers
    vector<int> counts(k);

    // Count occurrences of each digit at the specified place value
    for (int num : nums)
    {
        counts[(num / placeVal) % k]++;
    }

    // Calculate cumulative counts to determine the starting index for each digit
    int startIndex = 0;
    for (int i = 0; i < k; i++)
    {
        int c = counts[i];
        counts[i] = startIndex;
        startIndex += c;
    }

    // Perform sorting based on the specified place value
    vector<int> sorted(nums.size());
    for (int num : nums)
    {
        sorted[counts[(num / placeVal) % k]] = num;
        counts[(num / placeVal) % k]++;
    }

    // Update the original array with the sorted elements
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}

// Function to perform Radix Sort
void radixSort(vector<int> &nums)
{
    // Find the maximum element to determine the number of digits
    int maxElem = *max_element(nums.begin(), nums.end());

    int placeVal = 1;
    // Process each digit position from the least significant digit to the most significant digit
    while (maxElem / placeVal > 0)
    {
        countingSort(nums, placeVal);
        placeVal *= 10; // Move to the next significant digit position
    }
}

int main()
{
    // Example usage
    vector<int> nums = {256, 336, 736, 443, 831, 907};
    
    // Perform Radix Sort
    radixSort(nums);

    // Print the sorted array
    for (int x : nums)
        cout << x << " ";
    
    return 0;
}
