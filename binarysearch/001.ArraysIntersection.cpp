#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Problem Statement:
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Intuition:
// This problem can be solved using either a hash set or sorting with two pointers.
// 1. Using a hash set: Insert all elements of one array into a set, then iterate through the second array to find common elements.
// 2. Sorting with two pointers: Sort both arrays and use two pointers to find common elements efficiently.

// DSA Strategy/Pattern:
// Hash Set, Sorting with Two Pointers

// Approach 1 (Using Hash Set):
// Explanation:
// 1. Insert all elements of nums1 into the set to remove duplicates.
// 2. Iterate through nums2 and add common elements to the result vector.
// 3. Remove the element from the set to avoid duplicates.
// 4. Return the result vector.

// Time Complexity: O(m + n), where m and n are the sizes of nums1 and nums2, respectively.
// Space Complexity: O(min(m, n)), considering the space required for the set and result vector.

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_set<int> set;

    // Insert all elements of nums1 into the set to remove duplicates
    for (int num : nums1)
    {
        set.insert(num);
    }

    // Iterate through nums2 and add common elements to the result vector
    for (int num : nums2)
    {
        if (set.count(num))
        {
            res.push_back(num);
            set.erase(num); // Remove the element from the set to avoid duplicates
        }
    }

    return res;
}

// Approach 2 (Using Sorting with Two Pointers):
// Explanation:
// 1. Sort both arrays.
// 2. Use two pointers approach to find common elements efficiently.
// 3. Move the pointer of the array with the smaller element.
// 4. Copy common elements to the result vector.
// 5. Return the result vector.

// Time Complexity: O(m log m + n log n), where m and n are the sizes of nums1 and nums2, respectively, due to sorting.
// Space Complexity: O(min(m, n)), considering the space required for the result vector.

vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{
    // Sort both arrays
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> res;
    unordered_set<int> set;

    // Two pointers approach to find common elements
    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
    {
        if (nums1[i] == nums2[j])
        {
            set.insert(nums1[i]); // Add common element to set
            i++;
            j++;
        }
        else
        {
            // Move the pointer of the array with the smaller element
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }

    // Copy elements from set to result vector
    for (int num : set)
    {
        res.push_back(num);
    }

    return res;
}

// Main function
int main()
{
    // Test cases
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    // Output the intersection using both approaches
    vector<int> v = intersection(nums1, nums2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
