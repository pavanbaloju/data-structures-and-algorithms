#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Sort an array of integers containing only 0, 1, and 2, without using any built-in sorting function.

// Intuition:
// Counting Sort is an efficient sorting algorithm for sorting arrays of integers with a limited range.
// Since the input array contains only elements 0, 1, and 2, we can use Counting Sort to sort it in linear time.

// DSA Strategy:
// Counting Sort

// Approach:
// 1. Implement a function 'countSort' to perform Counting Sort.
//    a. Count the frequency of each element (0, 1, 2) in the input array.
//    b. Compute the starting index for each element in the sorted array based on their frequencies.
//    c. Iterate through the input array and place each element in its correct position in the sorted array.
//    d. Update the input array with the sorted elements.
// 2. Implement a function 'sortColors' as a wrapper function that calls 'countSort' to sort the input array.
// 3. In the main function, initialize the input array and call 'sortColors' to sort it.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n), additional space is used for counting frequencies and the sorted array.

// Function to perform Counting Sort on an array containing only elements 0, 1, and 2.
void countSort(vector<int> &nums)
{
    int k = 2; // Maximum value in the input array.
    vector<int> counts(k + 1); // Initialize an array to store the frequency of each element.

    // Step 1: Count the frequency of each element in the input array.
    for (int num : nums)
    {
        counts[num]++;
    }

    // Step 2: Compute the starting index for each element in the sorted array.
    int startIndex = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int c = counts[i];
        counts[i] = startIndex;
        startIndex += c;
    }

    // Step 3: Iterate through the input array and place each element in its correct position in the sorted array.
    vector<int> sorted(nums.size());
    for (int num : nums)
    {
        sorted[counts[num]] = num;
        counts[num]++;
    }

    // Step 4: Update the input array with the sorted elements.
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}

// Function to sort an array containing elements 0, 1, and 2 using Counting Sort.
void sortColors(vector<int> &nums)
{
    countSort(nums); // Call the countSort function to perform sorting.
}

// Main function to demonstrate sorting of colors (0, 1, and 2).
int main()
{
    // Initialize the input array containing colors (0, 1, and 2).
    vector<int> colors = {2, 0, 2, 1, 1, 0};

    // Sort the colors using Counting Sort.
    sortColors(colors);

    // Print the sorted array of colors.
    for (int color : colors)
    {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}
