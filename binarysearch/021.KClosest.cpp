#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted array nums, two integers k and x, return the k closest elements to x in the array.
// The result should also be sorted in ascending order. If there is a tie, the smaller elements
// are always preferred.

// Intuition:
// We can use binary search to find the element closest to 'x'. Then, we can use a two-pointer
// approach to find the 'k' closest elements around that element.

// DSA Strategy:
// Binary Search, Two-Pointers

// Approach:
// 1. Implement a binary search function 'binarySearch' to find the element closest to 'x'.
//    a. Initialize 'start' as 0 and 'end' as 'nums.size() - 1'.
//    b. Initialize 'val' as 'nums[start]' and 'idx' as 'start'.
//    c. While 'start' is less than or equal to 'end':
//       i. Calculate the difference 'currDiff' between 'nums[mid]' and 'x'.
//       ii. Calculate the minimum difference 'minDiff' between 'val' and 'x'.
//       iii. Update 'val' and 'idx' if 'currDiff' is less than 'minDiff' or if they are equal
//            and 'nums[mid]' is smaller than 'val'.
//       iv. Adjust 'start' and 'end' based on whether 'nums[mid]' is less than, greater than,
//           or equal to 'x'.
// 2. Once we have found the element closest to 'x', initialize two pointers 'i' and 'j' to the
//    index of that element.
// 3. Using a while loop, iterate until 'k' closest elements are found:
//    a. If 'i' has reached the start of the array, increment 'j'.
//    b. If 'j' has reached the end of the array or if the element to the left of 'i' is closer
//       to 'x' than the element to the right of 'j', decrement 'i'.
//    c. Otherwise, increment 'j'.
// 4. Return the 'k' closest elements from index 'i' to index 'j' (inclusive).

// Time Complexity: O(log n + k), where 'n' is the size of the array.
// Space Complexity: O(k).

// Function to perform binary search and find the index of the element closest to 'x'
int binarySearch(vector<int> &nums, int x)
{
    int start = 0, end = nums.size() - 1;
    int val = nums[start], idx = start;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int currDiff = abs(nums[mid] - x);
        int minDiff = abs(val - x);
        // Update 'val' and 'idx' if 'nums[mid]' is closer to 'x'
        if (currDiff < minDiff || (currDiff == minDiff && nums[mid] < val))
        {
            val = nums[mid];
            idx = mid;
        }

        // Adjust 'start' and 'end' based on 'nums[mid]'
        if (nums[mid] < x)
        {
            start = mid + 1;
        }
        else if (nums[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            break;
        }
    }
    return idx;
}

// Function to find the 'k' closest elements to 'x' in the array
vector<int> findClosestElements(vector<int> &nums, int k, int x)
{
    // Find the index of the element closest to 'x'
    int index = binarySearch(nums, x);
    int i = index, j = index;
    // Iterate until 'k' closest elements are found
    while (k-- > 1)
    {
        // Move 'i' or 'j' pointers based on the closer element to 'x'
        if (i == 0)
        {
            j++;
        }
        else if (j == nums.size() - 1 || (abs(x - nums[i - 1]) <= abs(x - nums[j + 1])))
        {
            i--;
        }
        else
        {
            j++;
        }
    }

    // Collect the 'k' closest elements
    vector<int> res;
    for (int idx = i; idx <= j; idx++)
        res.push_back(nums[idx]);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 10, 10, 10};
    cout << binarySearch(nums, 9) << endl;
    vector<int> res = findClosestElements(nums, 1, 9);

    // Output the closest elements
    for (int num : res)
    {
        cout << num << " ";
    }
    return 0;
}
