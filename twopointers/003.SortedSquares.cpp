#include <iostream>
#include <vector>
#include <cmath> // Required for abs()

using namespace std;

// Problem Statement:
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Intuition:
// Since the input array is sorted and can contain negative numbers, we can use a two-pointer approach to efficiently square the elements in non-decreasing order.

// DSA Strategy/Pattern:
// Two Pointers

// Approach:
// 1. Initialize a result array of the same size as the input array.
// 2. Initialize two pointers, l and r, pointing to the start and end of the input array respectively.
// 3. Iterate through the input array from end to start (from right to left).
// 4. Compare the absolute values of elements at pointers l and r.
// 5. Square the element with the greater absolute value and store it in the result array at index k (where k is the current iteration index).
// 6. Move the corresponding pointer (l or r) towards the center of the array.
// 7. Repeat steps 4-6 until all elements are squared and stored in the result array.
// 8. Return the result array.

// Time Complexity: O(n), where n is the number of elements in the input array.
//                  Since we iterate through the input array once, the time complexity is linear.
// Space Complexity: O(n), where n is the number of elements in the input array.
//                   Additional space is required to store the result array.

vector<int> sortedSquares(vector<int> &A)
{
    vector<int> res(A.size()); // Initialize result array.

    int left = 0, right = A.size() - 1; // Pointers to the start and end of the input array.

    // Iterate through the input array from end to start.
    for (int k = A.size() - 1; k >= 0; k--)
    {
        // Compare absolute values of elements at pointers.
        if (abs(A[right]) > abs(A[left]))
        {
            res[k] = A[right] * A[right]; // Square the element at the right pointer and store it in the result array.
            right--;                      // Move the right pointer to the left.
        }
        else
        {
            res[k] = A[left] * A[left]; // Square the element at the left pointer and store it in the result array.
            left++;                     // Move the left pointer to the right.
        }
    }

    return res; // Return the result array.
}

int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> res = sortedSquares(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
