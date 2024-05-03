#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given two sorted arrays, merge them into a single sorted array.

// Intuition:
// We can merge the two sorted arrays using extra space or in-place.

// DSA Strategy/Pattern:
// Two Pointers

// Approach 1: Using Extra Space
// Explanation:
// 1. Initialize an empty vector 'merged' to store the merged array.
// 2. Initialize two pointers, 'i' and 'j', for the two input arrays, arr1 and arr2 respectively.
// 3. Compare elements at indices i and j of arr1 and arr2 respectively.
// 4. Push the smaller element into the 'merged' vector and move the corresponding pointer.
// 5. Repeat steps 3-4 until one of the arrays is fully processed.
// 6. Add the remaining elements from the non-empty array to the 'merged' vector.
// 7. Return the 'merged' vector.

vector<int> mergeArraysExtraSpace(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> merged;
    int i = 0, j = 0;
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

// Approach 2: In-place Merge
// Explanation:
// 1. Initialize pointers 'i', 'j', and 'k' to the end of the first array, end of the second array,
//    and end of the merged array respectively.
// 2. Compare elements at indices i and j of the two input arrays.
// 3. Place the larger element at index k of the first array and decrement the corresponding pointer.
// 4. Repeat step 3 until one of the arrays is fully processed.
// 5. Add the remaining elements from the second array to the first array if any.
// 6. Return the modified first array.

void mergeArraysInPlace(vector<int> &firstArray, vector<int> &secondArray)
{
    int m = firstArray.size();
    int n = secondArray.size();
    int i = m - 1, j = n - 1, k = m + n - 1;
    firstArray.resize(k + 1);
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
    cout << "Merged array using extra space: ";
    for (int num : mergedExtraSpace)
    {
        cout << num << " ";
    }
    cout << endl;

    // Merge arrays in-place
    mergeArraysInPlace(firstSortedArray, secondSortedArray);
    cout << "Merged array in-place: ";
    for (int num : firstSortedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
