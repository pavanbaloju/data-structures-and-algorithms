#include <iostream>
#include <vector>
using namespace std;
// 1. Add problem statement
// Problem Statement:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// 2. Add Intuition
// Intuition:
// The problem can be solved by merging the two sorted arrays and then finding the median of the merged array.
// Alternatively, we can optimize the merge process and directly find the median using binary search.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Merge Sort, Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach 1 (Merge Approach):
// 1. Merge the two sorted arrays into a single sorted array.
// 2. If the size of the merged array is odd, return the middle element.
// 3. If the size of the merged array is even, return the average of the two middle elements.
//
// Approach 2 (Optimized Merge Approach):
// 1. Merge the two sorted arrays but optimize the process to find only the required median elements.
// 2. Find the median elements directly while merging the arrays.
//
// Approach 3 (Binary Search Approach):
// 1. Ensure that nums1 is the smaller array.
// 2. Perform binary search on nums1 to find the correct partition point.
// 3. Use partitioning to ensure that elements on the left side are smaller than elements on the right side.
// 4. Based on the total number of elements, calculate the median using the partitioning.

// 5. Add time and space complexity
// Time Complexity:
// Approach 1: O(m + n), where m and n are the sizes of the two arrays.
// Approach 2: O(m + n), where m and n are the sizes of the two arrays.
// Approach 3: O(log(min(m, n))), where m and n are the sizes of the two arrays.
// Space Complexity:
// Approach 1: O(m + n) for the merged array.
// Approach 2: O(1) additional space.
// Approach 3: O(1) additional space.

// Function to find the median of two sorted arrays by merging and finding median
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> arr3;

    // Merge the two sorted arrays into arr3
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
            arr3.push_back(nums1[i++]); // Add the element from nums1 to arr3 and increment the index of nums1
        else
            arr3.push_back(nums2[j++]); // Add the element from nums2 to arr3 and increment the index of nums2
    }
    while (i < n1)
        arr3.push_back(nums1[i++]); // Add the remaining elements from nums1 to arr3
    while (j < n2)
        arr3.push_back(nums2[j++]); // Add the remaining elements from nums2 to arr3

    int n = n1 + n2;
    if (n % 2)
        return (double)arr3[n / 2]; // If the size of arr3 is odd, return the middle element as the median

    return n % 2 ? (double)arr3[n / 2] // If the size of arr3 is even, return the average of the middle two elements as the median
                 : ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
}

// Approach 2: Optimized Merge and Find Median
// Explanation2:
// - Merge the arrays while finding the median simultaneously to optimize the process.
// Approach2:
// - Initialize variables to keep track of indices and counts for finding the median efficiently.
// - Merge the arrays nums1 and nums2 while updating the median indices.
// - Calculate the median based on the tracked indices and counts.
// Time Complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays.
// Space Complexity: O(1).

// Function to find the median of two sorted arrays by optimized merge and finding median
double findMedianSortedArraysBetter(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;

    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    int count = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (count == ind1)
                ind1el = nums1[i]; // Store the element from nums1 at index ind1
            if (count == ind2)
                ind2el = nums1[i]; // Store the element from nums1 at index ind2
            count++;
            i++;
        }
        else
        {
            if (count == ind1)
                ind1el = nums2[j]; // Store the element from nums2 at index ind1
            if (count == ind2)
                ind2el = nums2[j]; // Store the element from nums2 at index ind2
            count++;
            j++;
        }
    }

    while (i < n1)
    {
        if (count == ind1)
            ind1el = nums1[i]; // Store the remaining elements from nums1 at index ind1
        if (count == ind2)
            ind2el = nums1[i]; // Store the remaining elements from nums1 at index ind2
        count++;
        i++;
    }
    while (j < n2)
    {
        if (count == ind1)
            ind1el = nums2[j];
        if (count == ind2)
            ind2el = nums2[j];
        count++;
        j++;
    }

    return n % 2 ? (double)ind2el : ((double)(ind1el + ind2el)) / 2.0;
}

// Approach 3: Binary Search Approach
// Explanation3:
// - Use binary search to find the median efficiently.
// Approach3:
// - Ensure that nums1 is the smaller array for optimization.
// - Perform binary search on nums1 to find the partition points in both arrays.
// - Calculate the median based on the partition points.
// Time Complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays.
// Space Complexity: O(1).

// Function to find the median of two sorted arrays using binary search
double findMedianSortedArraysOpt(vector<int> &nums1, vector<int> &nums2)
{
    // Ensure nums1 is the smaller array for optimization
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;

    // Perform binary search on nums1 to find the correct partition
    while (left <= right)
    {
        // Calculate partition points for nums1 and nums2
        int partitionX = (left + right) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        // Calculate the maximum and minimum elements on the left and right sides of partitions
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX)
        {
            // Found the correct partition
            if ((m + n) % 2 == 0)
            {
                // If the total number of elements is even, return the average of maximum left and minimum right elements
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            }
            else
            {
                // If the total number of elements is odd, return the maximum element on the left side
                return max(maxX, maxY);
            }
        }
        else if (maxX > minY)
        {
            // Move left in nums1
            right = partitionX - 1;
        }
        else
        {
            // Move right in nums1
            left = partitionX + 1;
        }
    }

    return 0.0; // Invalid input
}

int main()
{
    // Test case
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};

    // Output the results of each approach
    cout << "Using Merge Approach: " << findMedianSortedArrays(a, b) << '\n';
    cout << "Using Optimized Merge Approach: " << findMedianSortedArraysBetter(a, b) << '\n';
    cout << "Using Binary Search Approach: " << findMedianSortedArraysOpt(a, b) << '\n';

    return 0;
}
