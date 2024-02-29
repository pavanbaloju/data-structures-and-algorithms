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

// Intuition:
// Maintain an additional variable to keep track of the minimum element. When pushing a new element onto the stack, compare it with the current minimum element and update if necessary.

// DSA Strategy:
// Stack

// Approach:
// 1. Initialize the stack and minimum element variable in the constructor.
// 2. When pushing an element onto the stack:
//    a. If the new element is less than or equal to the current minimum element, push the current minimum onto the stack and update the minimum element.
//    b. Push the new element onto the stack.
// 3. When popping an element from the stack:
//    a. If the top element is equal to the minimum element, pop again to update the minimum element.
//    b. Pop the top element from the stack.
// 4. To retrieve the top element, return the top element of the stack.
// 5. To retrieve the minimum element, return the current minimum element.

// Time Complexity: O(1) for all operations (push, pop, top, getMin).
// Space Complexity: O(n) where n is the number of elements pushed onto the stack.

class MinStackOptimal
{
private:
    vector<int> stack; // Stack to store elements
    int minElem;       // Variable to store the minimum element so far

public:
    // Constructor to initialize the stack and minimum element
    MinStackOptimal()
    {
        minElem = INT_MAX; // Initialize minElem to maximum value
    }

    // Function to push an element onto the stack
    void push(int val)
    {
        if (val <= minElem)
        {
            // If the new element is less than or equal to minElem,
            // push the current minElem onto the stack and update minElem
            stack.push_back(minElem);
            minElem = val;
        }
        stack.push_back(val); // Push the new element onto the stack
    }

    // Function to pop the top element from the stack
    void pop()
    {
        if (stack.back() == minElem)
        {
            // If the top element is equal to minElem, pop again to update minElem
            stack.pop_back();
            minElem = stack.back();
        }
        stack.pop_back(); // Pop the top element from the stack
    }

    // Function to get the top element of the stack
    int top()
    {
        return stack.back(); // Return the top element of the stack
    }

    // Function to get the minimum element in the stack
    int getMin()
    {
        return minElem; // Return the current minimum element
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

    cout << endl;
    MinStackOptimal minStackOpt = MinStackOptimal(); // Create an instance of MinStack

    // Perform stack operations
    minStackOpt.push(-2);
    minStackOpt.push(0);
    minStackOpt.push(-3);
    cout << minStackOpt.getMin() << endl; // Expected output: -3
    minStackOpt.pop();
    cout << minStackOpt.top() << endl;    // Expected output: 0
    cout << minStackOpt.getMin() << endl; // Expected output: -2

    return 0;
}
