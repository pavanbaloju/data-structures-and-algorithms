#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given two sorted arrays, merge them into a single sorted array.

// Method 1: Merge Two Sorted Arrays Using Extra Space
// Approach:
// - Initialize an empty vector to store the merged array.
// - Use two pointers to iterate through both arrays simultaneously.
// - Compare elements from both arrays and push the smaller one into the merged vector.
// - Continue this process until one of the arrays is fully processed.
// - Add the remaining elements from the non-empty array to the merged vector.
// Time Complexity: O(m + n), where m and n are the sizes of the two input arrays.
// Space Complexity: O(m + n), where m and n are the sizes of the two input arrays.
vector<int> mergeArraysExtraSpace(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> merged;
    int i = 0, j = 0;

    // Merge elements until one of the arrays is fully processed
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            merged.push_back(arr1[i]);
            ++i;
        }
        else
        {
            merged.push_back(arr2[j]);
            ++j;
        }
    }

    // Add remaining elements from the non-empty array
    while (i < arr1.size())
    {
        merged.push_back(arr1[i]);
        ++i;
    }
    while (j < arr2.size())
    {
        merged.push_back(arr2[j]);
        ++j;
    }

    return merged;
}

// Method 2: Merge Two Sorted Arrays In-Place
// Approach:
// - Merge elements from the end of the first array and the end of the second array.
// - Compare elements from both arrays and place the larger one at the end of the first array.
// - Continue this process until one of the arrays is fully processed.
// - If there are remaining elements in the second array, copy them to the beginning of the first array.
// Time Complexity: O(m + n), where m and n are the sizes of the two input arrays.
// Space Complexity: O(1), as the merging is done in-place.
void mergeArraysInPlace(vector<int> &firstArray, vector<int> &secondArray)
{
    int m = firstArray.size();
    int n = secondArray.size();
    int i = m - 1;     // Pointer for firstArray
    int j = n - 1;     // Pointer for secondArray
    int k = m + n - 1; // Pointer for the merged array
    firstArray.resize(k + 1);

    // Merge elements until one of the arrays is fully processed
    while (i >= 0 && j >= 0)
    {
        if (firstArray[i] > secondArray[j])
        {
            firstArray[k--] = firstArray[i--];
        }
        else
        {
            firstArray[k--] = secondArray[j--];
        }
    }

    // Add remaining elements from secondArray to firstArray if any
    while (j >= 0)
    {
        firstArray[k--] = secondArray[j--];
    }
}

// Main function
int main()
{
    // First sorted array
    vector<int> firstSortedArray = {1, 3, 5, 7};

    // Second sorted array
    vector<int> secondSortedArray = {2, 4};

    // Merge arrays using extra space
    vector<int> mergedExtraSpace = mergeArraysExtraSpace(firstSortedArray, secondSortedArray);

    // Display merged array using extra space
    cout << "Merged array using extra space: ";
    for (int num : mergedExtraSpace)
    {
        cout << num << " ";
    }
    cout << endl;

    // Merge arrays in-place
    mergeArraysInPlace(firstSortedArray, secondSortedArray);

    // Display merged array in-place
    cout << "Merged array in-place: ";
    for (int num : firstSortedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
