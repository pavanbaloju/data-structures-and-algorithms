#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Approach 1: Merge Arrays and Find Median
// Explanation1:
// - Merge the two sorted arrays into a single sorted array and then find the median.
// Approach1:
// - Initialize an empty array arr3 to store the merged result.
// - Merge the arrays nums1 and nums2 into arr3 while maintaining sorted order.
// - Calculate the median based on the size of the merged array.
// Time Complexity: O(m + n), where m and n are the sizes of the input arrays.
// Space Complexity: O(m + n).

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
            arr3.push_back(nums1[i++]);
        else
            arr3.push_back(nums2[j++]);
    }
    while (i < n1)
        arr3.push_back(nums1[i++]);
    while (j < n2)
        arr3.push_back(nums2[j++]);

    int n = n1 + n2;
    if (n % 2)
        return (double)arr3[n / 2];

    return n % 2 ? (double)arr3[n / 2]
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

    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                ind1el = nums1[i];
            if (cnt == ind2)
                ind2el = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = nums2[j];
            if (cnt == ind2)
                ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = nums1[i];
        if (cnt == ind2)
            ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = nums2[j];
        if (cnt == ind2)
            ind2el = nums2[j];
        cnt++;
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
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArraysOpt(nums2, nums1);

    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;

    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // Boundary checks
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
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
