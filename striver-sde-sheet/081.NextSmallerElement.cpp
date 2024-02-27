#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array of integers, find the next smaller element for each element in the array.
// If there is no smaller element, return -1.

// Intuition:
// Use a stack to store the indices of elements from the array. Iterate through the array from
// left to right. For each element, pop elements from the stack and update the result vector
// until finding an element smaller than the current element. Then, push the current index onto
// the stack.

// DSA Strategy:
// Stack

// Approach:
// 1. Create a result vector and initialize it with -1.
// 2. Create a stack to store indices.
// 3. Iterate through each element in the array:
//    a. Pop elements from the stack and update the result vector until finding an element smaller
//       than the current element.
//    b. Push the current index onto the stack.
// 4. Return the result vector.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), where n is the number of elements in the array (for the stack and result vector).

vector<int> nextSmallerElement(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> st;             // Stack to store indices

    for (int i = 0; i < n; ++i)
    {
        // Pop elements from the stack and update result vector
        // until finding an element smaller than the current nums[i]
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            result[st.top()] = nums[i];
            st.pop();
        }

        // Push the current index onto the stack
        st.push(i);
    }

    return result;
}

// Main function
int main()
{
    // Example array
    vector<int> nums = {4, 5, 2, 10, 8};

    // Find the next smaller elements
    vector<int> result = nextSmallerElement(nums);

    // Print the result
    cout << "Next smaller elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
