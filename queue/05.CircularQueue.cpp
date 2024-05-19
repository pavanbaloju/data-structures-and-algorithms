#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;  // Array to store elements of the queue
    int front; // Pointer to the front of the queue
    int rear;  // Pointer to the rear of the queue
    int size;  // Maximum size of the queue
    int count; // Current number of elements in the queue

public:
    // Constructor to initialize the queue with a given size
    CircularQueue(int k)
    {
        size = k;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free the allocated memory
    ~CircularQueue()
    {
        delete[] arr;
    }

    // Function to insert an element into the circular queue
    bool enqueue(int value)
    {
        if (isFull())
        {
            return false; // Return false if the queue is full
        }
        rear = (rear + 1) % size; // Move rear pointer to the next position circularly
        arr[rear] = value;        // Insert the new element at the rear
        count++;                  // Increment the count of elements
        return true;              // Return true indicating the operation was successful
    }

    // Function to delete an element from the circular queue
    bool dequeue()
    {
        if (isEmpty())
        {
            return false; // Return false if the queue is empty
        }
        front = (front + 1) % size; // Move front pointer to the next position circularly
        count--;                    // Decrement the count of elements
        return true;                // Return true indicating the operation was successful
    }

    // Function to get the front item from the queue
    int Front()
    {
        if (isEmpty())
        {
            return -1; // Return -1 if the queue is empty
        }
        return arr[front]; // Return the front element
    }

    // Function to get the last item from the queue
    int Rear()
    {
        if (isEmpty())
        {
            return -1; // Return -1 if the queue is empty
        }
        return arr[rear]; // Return the rear element
    }

    // Function to check whether the circular queue is empty
    bool isEmpty()
    {
        return count == 0;
    }

    // Function to check whether the circular queue is full
    bool isFull()
    {
        return count == size;
    }
};

int main()
{
    // Create a circular queue of size 3
    CircularQueue q(3);

    // Enqueue elements
    cout << (q.enqueue(1) ? "Enqueued 1" : "Failed to enqueue 1") << endl;
    cout << (q.enqueue(2) ? "Enqueued 2" : "Failed to enqueue 2") << endl;
    cout << (q.enqueue(3) ? "Enqueued 3" : "Failed to enqueue 3") << endl;
    cout << (q.enqueue(4) ? "Enqueued 4" : "Failed to enqueue 4") << endl; // Should fail as queue is full

    // Display front and rear elements
    cout << "Front element: " << q.Front() << endl; // Should be 1
    cout << "Rear element: " << q.Rear() << endl;   // Should be 3

    // Dequeue elements
    cout << (q.dequeue() ? "Dequeued" : "Failed to dequeue") << endl;      // Should dequeue 1
    cout << (q.enqueue(4) ? "Enqueued 4" : "Failed to enqueue 4") << endl; // Should succeed

    // Display front and rear elements again
    cout << "Front element: " << q.Front() << endl; // Should be 2
    cout << "Rear element: " << q.Rear() << endl;   // Should be 4

    return 0;
}
