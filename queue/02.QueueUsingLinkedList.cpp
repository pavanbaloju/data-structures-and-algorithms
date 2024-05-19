#include <iostream>
using namespace std;

// Node structure to represent each element in the queue
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
    Node *front; // Pointer to the front of the queue
    Node *rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = rear = newNode; // If the queue is empty, set front and rear to the new node
        }
        else
        {
            rear->next = newNode; // Link the current rear node to the new node
            rear = newNode;       // Update the rear pointer
        }
    }

    // Function to remove and return the element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int val = front->data; // Store the value of the front node
        Node *temp = front;    // Store the front node in a temporary pointer
        front = front->next;   // Move front pointer to the next node
        delete temp;           // Delete the front node
        return val;
    }

    // Function to return the front element of the queue without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return front->data;
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
