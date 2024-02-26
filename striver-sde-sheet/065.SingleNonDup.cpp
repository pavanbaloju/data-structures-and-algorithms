#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once. The array should be sorted in ascending order.

// Intuition:
// We can solve this problem using various approaches:
// 1. Brute force: Traverse the array and find the element that appears only once by checking consecutive elements.
// 2. XOR: Use bitwise XOR operation to find the element that appears only once.
// 3. Binary search: Use binary search to efficiently find the element that appears only once.

// DSA Strategy:
// We can solve this problem using three approaches:
// 1. Brute force:
//    - Traverse the array and find the element that appears only once by checking consecutive elements.
//    - Time Complexity: O(n), where n is the size of the array.
//    - Space Complexity: O(1).
// 2. XOR:
//    - Use bitwise XOR operation to find the element that appears only once.
//    - Time Complexity: O(n), where n is the size of the array.
//    - Space Complexity: O(1).
// 3. Binary search:
//    - Use binary search to efficiently find the element that appears only once.
//    - Time Complexity: O(log n), where n is the size of the array.
//    - Space Complexity: O(1).

// Approach 1: Brute Force
// - Traverse the array and find the element that appears only once by checking consecutive elements.
// Time Complexity: O(n)
// Space Complexity: O(1)

// Comments for each line in method
int singleNonDuplicateBruteForce(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i += 2)
    {
        if (i == n - 1 || nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1; // Not found
}

// Approach 2: XOR
// - Use bitwise XOR operation to find the element that appears only once.
// Time Complexity: O(n)
// Space Complexity: O(1)

// Comments for each line in method
int singleNonDuplicateXOR(vector<int> &nums)
{
    int result = 0;
    for (int num : nums)
    {
        result ^= num;
    }
    return result;
}

// Approach 3: Binary Search
// - Use binary search to efficiently find the element that appears only once.
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Comments for each line in method
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size(); // size of the array.

    // Edge cases:
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if arr[mid] is the single element:
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        // we are in the left: (even, odd)
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

// Main function
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    cout << "Using Brute Force: " << singleNonDuplicateBruteForce(nums) << endl;
    cout << "Using XOR: " << singleNonDuplicateXOR(nums) << endl;
    cout << "Using Binary Search: " << singleNonDuplicate(nums) << endl;

    return 0;
}
