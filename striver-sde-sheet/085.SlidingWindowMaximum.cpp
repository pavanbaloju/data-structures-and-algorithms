#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem Statement:
// Given an array of integers nums and an integer k, return the maximum elements of each sliding window of size k.

// Intuition:
// We can use a deque to efficiently find the maximum elements in each sliding window. We maintain the deque such that it stores the indices of elements in the current window, and we ensure that the front of the deque always contains the index of the maximum element in the current window.

// DSA Strategy:
// Monotonic Decreasing Deque

// Approach:
// 1. Create a deque to store indices of elements in the current window.
// 2. Traverse through the input array:
//    a. Remove the index from the front of deque if it's outside the current window.
//    b. Remove indices of smaller elements from the back of deque.
//    c. Add the current index to the back of deque.
//    d. If the window size is reached, add the maximum element to the answer vector.
// 3. Return the vector containing maximum elements in each window.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(k), where k is the size of the sliding window.

// Function to find the maximum elements in each sliding window of size k
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;     // Vector to store the maximum elements in each window
    deque<int> dq;       // Deque to store indices of elements in the current window
    int n = nums.size(); // Size of the input array

    // Traverse through the input array
    for (int i = 0; i < n; i++)
    {
        // Remove the index from the front of deque if it's outside the current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove indices of smaller elements from the back of deque
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add the current index to the back of deque
        dq.push_back(i);

        // If the window size is reached, add the maximum element to the answer vector
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans; // Return the vector containing maximum elements in each window
}

// Function to print a vector
void printVector(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // Input array and window size
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Find the maximum elements in each sliding window of size k
    vector<int> ans = maxSlidingWindow(nums, k);

    // Print the result
    printVector(ans);

    return 0;
}
