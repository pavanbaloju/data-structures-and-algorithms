#include <iostream>
#include <stack>
using namespace std;

// Problem Statement:
// Implement a queue using two stacks.

// Intuition:
// Use two stacks to simulate the behavior of a queue. One stack is used for pushing elements (pushStack), and the other is used for popping elements (popStack).

// DSA Strategy:
// Stacks

// Approach:
// 1. Define a class 'MyQueue' with two private member variables: 'pushStack' and 'popStack' (both stacks).
// 2. Implement the constructor 'MyQueue()' to initialize both stacks.
// 3. Implement the 'push' function to push an element into the queue:
//    a. Push the element onto the 'pushStack' stack.
// 4. Implement the 'pop' function to pop an element from the queue:
//    a. If 'popStack' is empty, transfer elements from 'pushStack' to 'popStack'.
//    b. Pop the top element from 'popStack' and return it.
// 5. Implement the 'peek' function to return the front element of the queue without removing it:
//    a. If 'popStack' is empty, transfer elements from 'pushStack' to 'popStack'.
//    b. Return the top element of 'popStack'.
// 6. Implement the 'empty' function to check if the queue is empty:
//    a. Return true if both 'pushStack' and 'popStack' are empty, otherwise false.

// Time Complexity:
// - Push: O(1)
// - Pop (Amortized): O(1)
// - Peek (Amortized): O(1)
// - Empty: O(1)
// Space Complexity: O(n)

class MyQueue
{
private:
    stack<int> pushStack, popStack; // Two stacks to simulate a queue

public:
    // Constructor to initialize the queue
    MyQueue()
    {
        pushStack = stack<int>(); // Initialize pushStack stack
        popStack = stack<int>();  // Initialize popStack stack
    }

    // Function to push an element into the queue
    void push(int x)
    {
        pushStack.push(x); // Push the element onto pushStack stack
    }

    // Function to pop an element from the queue
    int pop()
    {
        if (popStack.empty())
        { // If popStack is empty, transfer elements from pushStack to popStack
            while (!pushStack.empty())
            {
                popStack.push(pushStack.top()); // Move top element from pushStack to popStack
                pushStack.pop();                // Remove the top element from pushStack
            }
        }
        int x = popStack.top(); // Retrieve the top element of popStack
        popStack.pop();         // Remove the top element from popStack
        return x;               // Return the removed element
    }

    // Function to return the front element of the queue without removing it
    int peek()
    {
        if (popStack.empty())
        { // If popStack is empty, transfer elements from pushStack to popStack
            while (!pushStack.empty())
            {
                popStack.push(pushStack.top()); // Move top element from pushStack to popStack
                pushStack.pop();                // Remove the top element from pushStack
            }
        }
        return popStack.top(); // Return the top element of popStack
    }

    // Function to check if the queue is empty
    bool empty()
    {
        return pushStack.empty() && popStack.empty(); // Return true if both stacks are empty, otherwise false
    }
};

// Main function
int main()
{
    MyQueue myQueue = MyQueue(); // Create an instance of MyQueue

    // Push elements into the queue
    myQueue.push(1);
    myQueue.push(2);

    // Print the front element of the queue
    cout << "Front element: " << myQueue.peek() << endl;

    // Pop an element from the queue
    cout << "Popped element: " << myQueue.pop() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    return 0;
}
