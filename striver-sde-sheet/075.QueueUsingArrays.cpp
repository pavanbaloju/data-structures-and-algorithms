#include <iostream>
using namespace std;

// Problem Statement:
// Implement a queue using an array.

// Intuition:
// Use an array to store the elements of the queue and maintain indices to keep track of the front and rear of the queue.

// DSA Strategy:
// Array

// Approach:
// 1. Define a class 'MyQueue' with private member variables 'arr' (an array to store queue elements) and 'frontIndex', 'rearIndex' (indices to keep track of the front and rear of the queue).
// 2. Implement the constructor 'MyQueue()' to initialize 'frontIndex' and 'rearIndex' to -1 (indicating an empty queue).
// 3. Implement the 'enqueue' function to add an element to the rear of the queue:
//    a. If the queue is empty, set both 'frontIndex' and 'rearIndex' to 0.
//    b. If the rear index is at the maximum size, display an error message for queue overflow.
//    c. Otherwise, increment the rear index and insert the new element at that index in the array.
// 4. Implement the 'dequeue' function to remove and return the front element from the queue:
//    a. If the queue is empty, display an error message for queue underflow and return an invalid value.
//    b. Retrieve the front element, and if there was only one element in the queue, reset both 'frontIndex' and 'rearIndex' to -1.
//    c. Otherwise, increment the front index.
// 5. Implement the 'front' function to get the front element of the queue without removing it:
//    a. If the queue is empty, display an error message and return an invalid value.
//    b. Otherwise, return the element at the front index of the array.
// 6. Implement the 'isEmpty' function to check if the queue is empty:
//    a. Return true if 'frontIndex' is -1 (indicating an empty queue), false otherwise.

// Time Complexity:
// - Enqueue: O(1)
// - Dequeue: O(1)
// - Front: O(1)
// - isEmpty: O(1)
// Space Complexity: O(n)

const int MAX_SIZE = 100; // Maximum size of the queue

class MyQueue
{
private:
    int arr[MAX_SIZE];         // Array to store queue elements
    int frontIndex, rearIndex; // Indices to keep track of the front and rear of the queue

public:
    // Constructor to initialize the queue
    MyQueue()
    {
        frontIndex = rearIndex = -1; // Initialize frontIndex and rearIndex to -1 (empty queue)
    }

    // Function to enqueue an element into the queue
    void enqueue(int x)
    {
        if (isEmpty())
        { // If the queue is empty, set both front and rear to 0
            frontIndex = rearIndex = 0;
        }
        else if (rearIndex == MAX_SIZE - 1)
        {                                      // Check if the queue is full
            cout << "Queue Overflow!" << endl; // Display error message
            return;
        }
        else
        {
            rearIndex++; // Increment rearIndex
        }
        arr[rearIndex] = x; // Insert the new element at the rear of the queue
    }

    // Function to dequeue an element from the queue
    int dequeue()
    {
        if (isEmpty())
        {                                       // Check if the queue is empty
            cout << "Queue Underflow!" << endl; // Display error message
            return -1;                          // Return an invalid value
        }
        int removedElement = arr[frontIndex]; // Retrieve the front element
        if (frontIndex == rearIndex)
        {                                // If there was only one element in the queue
            frontIndex = rearIndex = -1; // Reset frontIndex and rearIndex to -1
        }
        else
        {
            frontIndex++; // Increment frontIndex
        }
        return removedElement; // Return the dequeued element
    }

    // Function to get the front element of the queue without dequeueing it
    int front()
    {
        if (isEmpty())
        {                                      // Check if the queue is empty
            cout << "Queue is empty!" << endl; // Display error message
            return -1;                         // Return an invalid value
        }
        return arr[frontIndex]; // Return the front element
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return frontIndex == -1; // Return true if frontIndex is -1 (empty queue), false otherwise
    }
};

// Main function
int main()
{
    MyQueue myQueue = MyQueue(); // Create an instance of MyQueue

    // Enqueue elements into the queue
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // Print the front element of the queue
    cout << "Front element: " << myQueue.front() << endl; // Expected output: 1

    // Dequeue an element from the queue
    cout << "Dequeued element: " << myQueue.dequeue() << endl; // Expected output: 1

    // Print the front element of the queue after dequeue
    cout << "Front element after dequeue: " << myQueue.front() << endl; // Expected output: 2

    return 0;
}
