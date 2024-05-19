#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Queue
{
private:
    int arr[MAX_SIZE]; // Array to store elements
    int front, rear;   // Pointers for front and rear of the queue

public:
    // Constructor
    Queue()
    {
        front = rear = -1; // Initialize front and rear pointers
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return rear == MAX_SIZE - 1;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0; // If the queue is empty, set front and rear to 0
        }
        else
        {
            rear++; // Increment rear pointer
        }
        arr[rear] = val; // Add the element to the rear of the queue
    }

    // Function to remove and return the element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        else if (front == rear)
        {
            // If there is only one element in the queue, reset front and rear pointers
            int val = arr[front];
            front = rear = -1;
            return val;
        }
        else
        {
            return arr[front++]; // Increment front pointer and return the dequeued element
        }
    }

    // Function to return the front element of the queue without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    // Create a queue
    Queue q;

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Peek the front element
    cout << "Front element: " << q.peek() << endl;

    // Dequeue an element
    cout << "Dequeued element: " << q.dequeue() << endl;

    // Peek the front element again
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
