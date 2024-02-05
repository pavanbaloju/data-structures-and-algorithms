#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays using extra space
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

// Function to merge two sorted arrays in-place
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
