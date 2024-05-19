#include <iostream>
#include <queue> // Include queue library
using namespace std;

// Problem Statement:
// Implement a stack using queues.

// Intuition:
// To implement a stack using queues, we can use a single queue. When pushing an element,
// we can first enqueue it to the queue, and then rotate the queue so that the newly added element becomes the front of the queue (top of the stack).

// DSA Strategy:
// Queue

// Approach:
// 1. Define a class 'MyStack' with a private member variable 'q' of type queue<int>.
// 2. Implement the 'push' function to push an element onto the stack.
//    a. Enqueue the element to the queue.
//    b. Rotate the queue so that the newly added element becomes the front of the queue (top of the stack).
// 3. Implement the 'pop' function to remove and return the top element from the stack.
//    a. Dequeue and return the front element from the queue.
// 4. Implement the 'top' function to return the top element of the stack without removing it.
//    a. Return the front element from the queue.
// 5. Implement the 'empty' function to check if the stack is empty.
//    a. Return whether the queue is empty.

// Time Complexity:
// - Push: O(n)
// - Pop: O(1)
// - Top: O(1)
// - Empty: O(1)
// Space Complexity: O(n)

class MyStack
{
private:
    queue<int> q; // Declare a queue to store stack elements

public:
    MyStack()
    {
        q = queue<int>(); // Initialize the queue
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        q.push(x); // Add the new element to the queue

        // Rotate the queue so that the newly added element becomes the top of the stack
        for (int i = 0; i < q.size() - 1; ++i)
        {
            q.push(q.front()); // Move the front element to the back of the queue
            q.pop();           // Remove the front element
        }
    }

    // Function to pop the top element from the stack
    int pop()
    {
        int x = q.front(); // Get the top element of the stack
        q.pop();           // Remove the top element from the queue
        return x;          // Return the popped element
    }

    // Function to return the top element of the stack without popping it
    int top()
    {
        return q.front(); // Return the front element of the queue (top of the stack)
    }

    // Function to check if the stack is empty
    bool empty()
    {
        return q.empty(); // Check if the queue is empty
    }
};

// Main function
int main()
{
    MyStack myStack = MyStack(); // Create an instance of MyStack

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);

    // Print the top element of the stack
    cout << myStack.top(); // Expected output: 2

    // Pop the top element from the stack
    cout << myStack.pop(); // Expected output: 2

    // Check if the stack is empty
    cout << myStack.empty(); // Expected output: 0 (false)

    return 0;
}
