#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem Statement:
// Given an array of integers, find the maximum minimum value for every window size.

// Intuition:
// To solve this problem, we can utilize the concept of finding the nearest smaller element to the left and right of each element in the array.
// Once we have the nearest smaller elements to the left and right of each element, we can calculate the window size for each element and update the maximum minimum values accordingly.

// DSA Strategy Used:
// Stack

// Approach:
// 1. Finding Nearest Previous Smaller Element (left) and Nearest Next Smaller Element (right) for each Element:
//    a. We use two stacks to find the nearest previous smaller element (left) and nearest next smaller element (right) for each element in the array.
//    b. We iterate through the array from left to right to find the nearest previous smaller element for each element.
//    c. Similarly, we iterate from right to left to find the nearest next smaller element for each element.
//    d. For each element, we push its index onto the stack if it's greater than the top element of the stack. Otherwise, we pop elements from the stack until we find a smaller element or the stack becomes empty.
//    e. Once we find the nearest smaller element, we store its index in the respective left or right array. If no smaller element is found, we store -1 (for left) or the size of the array (for right).
// 2. Calculating Maximum Minimum Values for Each Window Size:
//    a. After finding the nearest smaller elements to the left and right of each element, we initialize a result vector to store the maximum minimum values.
//    b. We iterate through the array and calculate the window size for each element by subtracting the indices of the nearest smaller elements (left and right) and subtracting 1.
//    c. Using the window size, we update the maximum minimum value in the result vector.
//    d. Finally, we fill in the missing values in the result vector by iterating backward and updating each element with the maximum value encountered so far.

// Time Complexity:
// - Finding Nearest Previous Smaller Element (left) and Nearest Next Smaller Element (right) for each Element: O(n)
// - Calculating Maximum Minimum Values for Each Window Size: O(n)
// Total Time Complexity: O(n)
// Space Complexity: O(n) - We use additional space for two stack arrays to store indices and a result vector.

// Function to find the nearest previous smaller element for each element
void findPreviousSmaller(const vector<int> &nums, vector<int> &left)
{
    int n = nums.size();
    stack<int> s;

    // Iterate through the array to find the nearest previous smaller element for each element
    for (int i = 0; i < n; ++i)
    {
        // Pop elements from the stack until a smaller element than the current element is found
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        // If stack is empty, there's no previous smaller element, otherwise, store the index of the nearest smaller element
        left[i] = s.empty() ? -1 : s.top();
        s.push(i); // Push current element's index onto the stack
    }
}

// Function to find the nearest next smaller element for each element
void findNextSmaller(const vector<int> &nums, vector<int> &right)
{
    int n = nums.size();
    stack<int> s;

    // Iterate through the array to find the nearest next smaller element for each element
    for (int i = n - 1; i >= 0; --i)
    {
        // Pop elements from the stack until a smaller element than the current element is found
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        // If stack is empty, there's no next smaller element, otherwise, store the index of the nearest smaller element
        right[i] = s.empty() ? n : s.top();
        s.push(i); // Push current element's index onto the stack
    }
}

// Function to find the maximum minimum value for every window size
vector<int> maxOfMinInWindows(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n), right(n);

    // Find the nearest previous smaller element for each element
    findPreviousSmaller(nums, left);

    // Find the nearest next smaller element for each element
    findNextSmaller(nums, right);

    // Initialize the result vector to store the maximum minimum values
    vector<int> result(n + 1, 0);

    // Calculate the window size for each element and update the maximum minimum values
    for (int i = 0; i < n; ++i)
    {
        int windowSize = right[i] - left[i] - 1;
        result[windowSize] = max(result[windowSize], nums[i]);
    }

    // Fill the missing values in the result vector
    for (int i = n - 1; i >= 1; --i)
    {
        result[i] = max(result[i], result[i + 1]);
    }

    // Remove the first element which is always 0
    result.erase(result.begin());

    return result;
}

int main()
{
    vector<int> nums = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = maxOfMinInWindows(nums);

    // Print the maximum minimum values for each window size
    cout << "Maximum minimum values for each window size:" << endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
