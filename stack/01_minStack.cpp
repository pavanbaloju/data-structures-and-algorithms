#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Intuition:
// We can use a stack to store pairs of elements and their corresponding minimum values. Each time we push a new element onto the stack, we also update the minimum value accordingly.

// DSA Strategy:
// Stack

// Approach:
// 1. Initialize the stack with a maximum value pair (INT_MAX, INT_MAX).
// 2. When pushing an element onto the stack, store a pair consisting of the element and the minimum of the current minimum and the new element.
// 3. When popping an element from the stack, simply remove the top element.
// 4. To retrieve the top element, return the first element of the top pair.
// 5. To retrieve the minimum element, return the second element of the top pair.

// Time Complexity: O(1) for all operations (push, pop, top, getMin).
// Space Complexity: O(n) where n is the number of elements pushed onto the stack.

class MinStack
{
private:
    vector<pair<int, int>> stack; // Stack to store pairs of (element, current minimum)

public:
    // Constructor to initialize the stack with a maximum value pair
    MinStack()
    {
        stack.push_back({INT_MAX, INT_MAX}); // Push a pair with maximum value
    }

    // Function to push an element onto the stack
    void push(int val)
    {
        // Push the element and the minimum of current minimum and the new element
        stack.push_back({val, min(val, stack.back().second)});
    }

    // Function to pop the top element from the stack
    void pop()
    {
        stack.pop_back(); // Remove the top element from the stack
    }

    // Function to get the top element of the stack
    int top()
    {
        return stack.back().first; // Return the first element of the top pair
    }

    // Function to get the minimum element in the stack
    int getMin()
    {
        return stack.back().second; // Return the second element of the top pair
    }
};

int main()
{
    MinStack minStack = MinStack(); // Create an instance of MinStack

    // Perform stack operations
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Expected output: -3
    minStack.pop();
    cout << minStack.top() << endl;    // Expected output: 0
    cout << minStack.getMin() << endl; // Expected output: -2

    return 0;
}
