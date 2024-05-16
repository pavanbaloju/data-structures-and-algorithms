#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Statement:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Intuition:
// The problem can be solved by partitioning both arrays in such a way that elements on the left side of the partition are smaller or equal to elements on the right side.
// This approach resembles the binary search technique.

// DSA Strategy/Pattern: Binary Search

// Approach:
// 1. Ensure that nums1 is smaller or equal in size compared to nums2. If not, swap the arrays to ensure that nums1 is always the smaller one.
// 2. Use binary search to find the correct partition in nums1. Initialize the partition indices left and right to 0 and m respectively.
// 3. Perform binary search until left is less than or equal to right:
//    - Calculate partitionX as the midpoint between left and right.
//    - Calculate partitionY based on the total number of elements in both arrays and partitionX.
//    - Compute the maximum and minimum elements on the left and right sides after partitioning.
//    - If the partitions are correct (maxX <= minY and maxY <= minX), return the median:
//        - If the total number of elements is even, return the average of max(left) and min(right).
//        - If the total number of elements is odd, return max(left).
//    - If maxX is greater than minY, adjust the partition to the left (move right = partitionX - 1).
//    - If maxY is greater than minX, adjust the partition to the right (move left = partitionX + 1).
// 4. If the loop exits without finding the correct partitions, throw an invalid argument as the inputs are not valid.

// Time Complexity: O(log(min(m, n))), where m and n are the sizes of nums1 and nums2 respectively. Binary search is performed on the smaller array.
// Space Complexity: O(1), constant space is used.

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        // Ensure nums1 is smaller or equal in size compared to nums2
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Initialize the partition indices for binary search
        int left = 0;
        int right = m;

        // Perform binary search to find the correct partition
        while (left <= right)
        {
            int partitionX = left + (right - left) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            // Compute the elements on the left and right sides after partition
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Check if the partitions are correct
            if (maxX <= minY && maxY <= minX)
            {
                // Found the correct partitions
                if ((m + n) % 2 == 0)
                {
                    // Even number of elements, return the average of max(left) and min(right)
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                }
                else
                {
                    // Odd number of elements, return max(left)
                    return max(maxX, maxY);
                }
            }
            else if (maxX > minY)
            {
                // PartitionX needs to move to the left
                right = partitionX - 1;
            }
            else
            {
                // PartitionX needs to move to the right
                left = partitionX + 1;
            }
        }

        // This line should never be reached if the inputs are valid
        throw invalid_argument("Invalid input arrays");
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
