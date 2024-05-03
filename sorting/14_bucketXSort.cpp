#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

// Problem Statement:
// Implement Bucket Sort to sort an array of floating-point numbers.

// Intuition:
// Bucket Sort divides the range of array elements into a number of buckets, each of which can contain multiple elements.
// Each bucket is then sorted individually, typically using another sorting algorithm like Insertion Sort.

// DSA Strategy/Pattern:
// Sorting, Bucket Sort

// Approach:
// 1. Create an array of empty buckets, where the number of buckets is equal to the size of the input array.
// 2. Distribute elements of the input array into the buckets based on their values.
//    - Each element is placed into a bucket based on a function of its value, such as multiplying it by the size of the array.
// 3. Sort elements within each bucket using a stable sorting algorithm (here, Insertion Sort is used).
// 4. Concatenate all the sorted buckets to obtain the final sorted array.

// Time Complexity: O(n^2), where n is the number of elements in the input array. 
//                  The worst-case time complexity arises when all elements are placed in a single bucket and sorted using Insertion Sort.
// Space Complexity: O(n), where n is the number of elements in the input array. 

// Insertion sort for sorting elements within a bucket
void insertionSort(vector<float>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            --j;
        }
        bucket[j + 1] = key;
    }
}

// Bucket sort function
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create buckets
    vector<vector<float>> buckets(n);

    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort elements within each bucket using insertion sort
    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i]);
    }

    // Merge sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    // Example usage
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    // Print the original array
    cout << "Original array:" << endl;
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the array using Bucket Sort
    bucketSort(arr);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
