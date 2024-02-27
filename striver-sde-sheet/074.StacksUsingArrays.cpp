#include <iostream>
using namespace std;

// Problem Statement:
// Implement a stack using an array.

// Intuition:
// Use an array to store the elements of the stack and maintain an index to keep track of the top element of the stack.

// DSA Strategy:
// Array

// Approach:
// 1. Define a class 'MyStack' with a private member variable 'arr' (an array to store stack elements) and 'topIndex' (index of the top element of the stack).
// 2. Implement the constructor 'MyStack()' to initialize 'topIndex' to -1 (indicating an empty stack).
// 3. Implement the 'push' function to add an element onto the stack:
//    a. Check if the stack is full. If so, display an error message for stack overflow.
//    b. Increment 'topIndex' and insert the new element at that index in the array.
// 4. Implement the 'pop' function to remove and return the top element from the stack:
//    a. Check if the stack is empty. If so, display an error message for stack underflow and return an invalid value.
//    b. Return the top element from the array and decrement 'topIndex'.
// 5. Implement the 'top' function to return the top element of the stack without popping it:
//    a. Check if the stack is empty. If so, display an error message and return an invalid value.
//    b. Return the element at 'topIndex' in the array.
// 6. Implement the 'isEmpty' function to check if the stack is empty:
//    a. Return true if 'topIndex' is -1 (indicating an empty stack), false otherwise.

// Time Complexity:
// - Push: O(1)
// - Pop: O(1)
// - Top: O(1)
// - isEmpty: O(1)
// Space Complexity: O(n)

const int MAX_SIZE = 100; // Maximum size of the stack

class MyStack
{
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int topIndex;      // Index of the top element of the stack

public:
    // Constructor to initialize the stack
    MyStack()
    {
        topIndex = -1; // Initialize topIndex to -1 (empty stack)
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        if (topIndex == MAX_SIZE - 1)
        {                                      // Check if the stack is full
            cout << "Stack Overflow!" << endl; // Display error message
            return;
        }
        arr[++topIndex] = x; // Increment topIndex and insert the new element
    }

    // Function to pop the top element from the stack
    int pop()
    {
        if (isEmpty())
        {                                       // Check if the stack is empty
            cout << "Stack Underflow!" << endl; // Display error message
            return -1;                          // Return an invalid value
        }
        return arr[topIndex--]; // Return the top element and decrement topIndex
    }

    // Function to return the top element of the stack without popping it
    int top()
    {
        if (isEmpty())
        {                                      // Check if the stack is empty
            cout << "Stack is empty!" << endl; // Display error message
            return -1;                         // Return an invalid value
        }
        return arr[topIndex]; // Return the top element
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return topIndex == -1; // Return true if topIndex is -1 (empty stack), false otherwise
    }
};

// Main function
int main()
{
    MyStack myStack = MyStack(); // Create an instance of MyStack

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Print the top element of the stack
    cout << "Top element: " << myStack.top() << endl; // Expected output: 3

    // Pop the top element from the stack
    cout << "Popped element: " << myStack.pop() << endl; // Expected output: 3

    // Print the top element of the stack
    cout << "Top element after pop: " << myStack.top() << endl; // Expected output: 2

    return 0;
}
