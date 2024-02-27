#include <iostream>
#include <stack>
using namespace std;

// Problem Statement:
// Implement a queue using two stacks.

// Intuition:
// Use two stacks to simulate the behavior of a queue. One stack is used for pushing elements (pushQueue), and the other is used for popping elements (popQueue).

// DSA Strategy:
// Stacks

// Approach:
// 1. Define a class 'MyQueue' with two private member variables: 'pushQueue' and 'popQueue' (both stacks).
// 2. Implement the constructor 'MyQueue()' to initialize both stacks.
// 3. Implement the 'push' function to push an element into the queue:
//    a. Push the element onto the 'pushQueue' stack.
// 4. Implement the 'pop' function to pop an element from the queue:
//    a. If 'popQueue' is empty, transfer elements from 'pushQueue' to 'popQueue'.
//    b. Pop the top element from 'popQueue' and return it.
// 5. Implement the 'peek' function to return the front element of the queue without removing it:
//    a. If 'popQueue' is empty, transfer elements from 'pushQueue' to 'popQueue'.
//    b. Return the top element of 'popQueue'.
// 6. Implement the 'empty' function to check if the queue is empty:
//    a. Return true if both 'pushQueue' and 'popQueue' are empty, otherwise false.

// Time Complexity:
// - Push: O(1)
// - Pop (Amortized): O(1)
// - Peek (Amortized): O(1)
// - Empty: O(1)
// Space Complexity: O(n)

class MyQueue
{
private:
    stack<int> pushQueue, popQueue; // Two stacks to simulate a queue

public:
    // Constructor to initialize the queue
    MyQueue()
    {
        pushQueue = stack<int>(); // Initialize pushQueue stack
        popQueue = stack<int>();  // Initialize popQueue stack
    }

    // Function to push an element into the queue
    void push(int x)
    {
        pushQueue.push(x); // Push the element onto pushQueue stack
    }

    // Function to pop an element from the queue
    int pop()
    {
        if (popQueue.empty())
        { // If popQueue is empty, transfer elements from pushQueue to popQueue
            while (!pushQueue.empty())
            {
                popQueue.push(pushQueue.top()); // Move top element from pushQueue to popQueue
                pushQueue.pop();                // Remove the top element from pushQueue
            }
        }
        int x = popQueue.top(); // Retrieve the top element of popQueue
        popQueue.pop();         // Remove the top element from popQueue
        return x;               // Return the removed element
    }

    // Function to return the front element of the queue without removing it
    int peek()
    {
        if (popQueue.empty())
        { // If popQueue is empty, transfer elements from pushQueue to popQueue
            while (!pushQueue.empty())
            {
                popQueue.push(pushQueue.top()); // Move top element from pushQueue to popQueue
                pushQueue.pop();                // Remove the top element from pushQueue
            }
        }
        return popQueue.top(); // Return the top element of popQueue
    }

    // Function to check if the queue is empty
    bool empty()
    {
        return pushQueue.empty() && popQueue.empty(); // Return true if both stacks are empty, otherwise false
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
