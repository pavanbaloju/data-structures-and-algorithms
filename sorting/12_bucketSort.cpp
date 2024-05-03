#include <vector>
#include <iostream>
#include <algorithm> // Required for std::sort
using namespace std;

// Problem Statement:
// Implement Bucket Sort to sort an array of integers.

// Intuition:
// Bucket Sort divides the range of array elements into a number of buckets, each of which can contain multiple elements.
// Each bucket is then sorted individually, either using another sorting algorithm or recursively applying Bucket Sort.

// DSA Strategy/Pattern:
// Sorting, Bucket Sort

// Approach:
// 1. Create an array of buckets, where the number of buckets is specified by the parameter 'noOfBuckets'.
// 2. Determine the maximum element in the input array to calculate the range for distributing elements into buckets.
// 3. Distribute each element of the input array into its corresponding bucket based on the bucket index calculated using a formula.
// 4. Sort each bucket individually using a sorting algorithm (here, std::sort is used).
// 5. Concatenate all the sorted buckets to obtain the final sorted array.

// Time Complexity: O(n + nlogn), where n is the number of elements in the input array.
// Space Complexity: O(n + m), where n is the number of elements in the input array and m is the number of buckets.

// Function to perform Bucket Sort
void bucketSort(vector<int> &nums, int noOfBuckets)
{
    // Create an array of buckets
    vector<vector<int>> buckets(noOfBuckets);

    // Find the maximum element in the array
    int max = *max_element(nums.begin(), nums.end()) + 1;

    // Distribute elements into buckets
    for (int num : nums)
    {
        int bucketIndex = noOfBuckets * num / max;
        buckets[bucketIndex].push_back(num);
    }

    // Sort each bucket individually
    for (vector<int> &bucket : buckets)
        sort(bucket.begin(), bucket.end());

    // Concatenate sorted buckets to obtain the final sorted array
    int idx = 0;
    for (vector<int> bucket : buckets)
    {
        for (int num : bucket)
        {
            nums[idx++] = num;
        }
    }
}

int main()
{
    // Example usage
    vector<int> nums = {22, 50, 32, 28, 41, 12};
    
    // Perform Bucket Sort with 5 buckets
    bucketSort(nums, 5);

    // Print the sorted array
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
