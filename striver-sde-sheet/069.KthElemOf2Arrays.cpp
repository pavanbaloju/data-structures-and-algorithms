#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement:
// Given two sorted arrays 'nums1' and 'nums2' of size 'm' and 'n' respectively, and an integer 'k',
// return the 'k-th' (0-based) element of the merged sorted array formed by merging both arrays.

// Intuition:
// We can use the concept of binary search to efficiently find the k-th element in the merged sorted array.
// By comparing the middle elements of both arrays, we can determine which half contains the k-th element.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize 'left' to the maximum of 0 and 'k - n' and 'right' to the minimum of 'm' and 'k' to adjust for the smaller array.
// 2. While 'left' is less than 'right':
//    a. Calculate 'partitionX' as 'left + (right - left) / 2' and 'partitionY' as 'k - partitionX'.
//    b. Determine the maximum elements 'maxX' and 'maxY' from 'nums1' and 'nums2' respectively based on the partitions.
//    c. Determine the minimum elements 'minX' and 'minY' from 'nums1' and 'nums2' respectively based on the partitions.
//    d. If 'maxX' is less than or equal to 'minY' and 'maxY' is less than or equal to 'minX', it means the partitions are correct.
//       Return the maximum of 'maxX' and 'maxY' as the k-th element.
//    e. If 'maxX' is greater than 'minY', move 'right' to 'partitionX' to search in the left half of 'nums1'.
//    f. If 'maxY' is greater than 'minX', move 'left' to 'partitionX + 1' to search in the right half of 'nums1'.
// 3. If the k-th element is not found, return 0.

// Time Complexity: O(log(min(m, n))), where 'm' and 'n' are the sizes of the input arrays.
// Space Complexity: O(1).

// Function to find the k-th element in the merged sorted array of nums1 and nums2
int kthElementOfSortedArrays(vector<int> &nums1, vector<int> &nums2, int k)
{
    int m = nums1.size();
    int n = nums2.size();
    int left = max(0, k - n); // Adjusting left for smaller array
    int right = min(m, k);    // Adjusting right for smaller array

    while (left < right)
    {
        // Calculate the partition position for array nums1
        int partitionX = left + (right - left) / 2;

        // Calculate the corresponding partition position for array nums2
        int partitionY = k - partitionX;

        // Determine the maximum element on the left side of partitionX in nums1
        // If partitionX is at the beginning of nums1, set maxX to INT_MIN
        // Otherwise, set maxX to the element just before partitionX
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];

        // Determine the maximum element on the left side of partitionY in nums2
        // If partitionY is at the beginning of nums2, set maxY to INT_MIN
        // Otherwise, set maxY to the element just before partitionY
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        // Determine the minimum element on the right side of partitionX in nums1
        // If partitionX is at the end of nums1, set minX to INT_MAX
        // Otherwise, set minX to the element at partitionX
        int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        // Determine the minimum element on the right side of partitionY in nums2
        // If partitionY is at the end of nums2, set minY to INT_MAX
        // Otherwise, set minY to the element at partitionY
        int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX)
        {
            // Found the correct partition
            return max(maxX, maxY);
        }
        else if (maxX > minY)
        {
            // Move left in nums1
            right = partitionX;
        }
        else
        {
            // Move right in nums1
            left = partitionX + 1;
        }
    }

    int partitionX = left;
    int partitionY = k - partitionX;

    int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
    int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

    return max(maxX, maxY);
}

// Main function
int main()
{
    vector<int> nums1 = {1, 3, 8, 9, 15};
    vector<int> nums2 = {7, 11, 18, 19, 21, 25};
    int k = 7;

    cout << "k-th Element: " << kthElementOfSortedArrays(nums1, nums2, k) << endl; // Test kthElementOfSortedArrays function
    return 0;
}
