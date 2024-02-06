#include <iostream>
#include <vector>
#include <algorithm> // Required for sort function
using namespace std;

// Function to find the maximum sum of pairs from the given array.
// Given an integer array nums of 2n integers, 
// group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) 
// such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
// 
// Intuition:
// We can maximize the sum of pairs by pairing the smallest numbers together.
// To achieve this, we first sort the array in non-decreasing order.
// Then, we iterate through the sorted array, adding every alternate element to the sum.
// Since the array is sorted, every alternate element will be one of the smallest elements.
// Approach:
// - Sort the input array in non-decreasing order.
// - Iterate through the sorted array, adding every alternate element to the sum.
// - Return the sum.
// Time complexity: O(n log n) due to sorting, where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sort the array

    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) // Iterate through the sorted array, adding every alternate element
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    // Test the arrayPairSum function with an example array.
    vector<int> arr = {6, 2, 6, 5, 1, 2};
    cout << arrayPairSum(arr); // Output the result
    return 0;
}
