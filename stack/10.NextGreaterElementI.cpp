#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem Statement:
// Given two arrays nums1 and nums2 where nums1 is a subset of nums2, return the next greater element for each element in nums1.
// The next greater element of a number x in nums1 is the first greater number to its right in nums2.
// If it does not exist, return -1 for this number.

// Intuition:
// Use a monotonic stack to find the next greater element for each element in nums2.
// Store the results in a map. Then, iterate through nums1 and retrieve the next greater element from the map.

// DSA Strategy:
// Monotonic Stack, Hash Map

// Approach:
// 1. Initialize an unordered_map to store the next greater element for each element in nums2.
// 2. Initialize a stack to maintain elements from nums2 in a monotonic decreasing order.
// 3. Iterate through nums2 from left to right:
//    a. While the stack is not empty and the current element is greater than the top element of the stack:
//       - Update the next greater element for the top element of the stack and pop it from the stack.
//    b. Push the current element to the stack.
// 4. Iterate through nums1:
//    - Retrieve the next greater element for each element from the map. If not found, assign -1.
// 5. Return the result vector.

// Time Complexity: O(n1 + n2), where n1 is the size of nums1 and n2 is the size of nums2.
// Space Complexity: O(n2), where n2 is the size of nums2 (for the stack and map).

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> nextGreater;  // Map to store next greater element for each element in nums2
    stack<int> st;                        // Monotonic stack to store elements from nums2
    vector<int> result(nums1.size(), -1); // Initialize result vector with -1

    // Iterate through nums2 from left to right
    for (int num : nums2)
    {
        // Pop elements from the stack and update result vector
        // until finding an element greater than the current num
        while (!st.empty() && st.top() < num)
        {
            nextGreater[st.top()] = num;
            st.pop();
        }
        // Push the current num to the stack
        st.push(num);
    }

    // Iterate through nums1 to get the next greater elements
    for (int i = 0; i < nums1.size(); ++i)
    {
        if (nextGreater.find(nums1[i]) != nextGreater.end())
        {
            result[i] = nextGreater[nums1[i]];
        }
    }

    return result;
}

// Main function
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
