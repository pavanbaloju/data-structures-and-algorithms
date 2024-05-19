#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque
{
private:
    Node *front; // Pointer to the front of the deque
    Node *rear;  // Pointer to the rear of the deque

public:
    // Constructor to initialize an empty deque
    Deque() : front(nullptr), rear(nullptr) {}

    // Function to check if the deque is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to add an element to the front of the deque
    void insertFront(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = rear = newNode; // If the deque is empty, set both front and rear to the new node
        }
        else
        {
            newNode->next = front; // Link the new node to the current front node
            front->prev = newNode; // Link the current front node back to the new node
            front = newNode;       // Update the front pointer to the new node
        }
    }

    // Function to add an element to the rear of the deque
    void insertRear(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = rear = newNode; // If the deque is empty, set both front and rear to the new node
        }
        else
        {
            newNode->prev = rear; // Link the new node to the current rear node
            rear->next = newNode; // Link the current rear node forward to the new node
            rear = newNode;       // Update the rear pointer to the new node
        }
    }

    // Function to delete an element from the front of the deque
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete front." << endl;
            return;
        }
        Node *temp = front;  // Store the front node in a temporary pointer
        front = front->next; // Move the front pointer to the next node
        if (front)
        {
            front->prev = nullptr; // If the deque is not empty, set the previous pointer of the new front node to null
        }
        else
        {
            rear = nullptr; // If the deque becomes empty, set the rear pointer to null
        }
        delete temp; // Delete the old front node
    }

    // Function to delete an element from the rear of the deque
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete rear." << endl;
            return;
        }
        Node *temp = rear; // Store the rear node in a temporary pointer
        rear = rear->prev; // Move the rear pointer to the previous node
        if (rear)
        {
            rear->next = nullptr; // If the deque is not empty, set the next pointer of the new rear node to null
        }
        else
        {
            front = nullptr; // If the deque becomes empty, set the front pointer to null
        }
        delete temp; // Delete the old rear node
    }

    // Function to get the front element of the deque
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot get front." << endl;
            return -1;
        }
        return front->data; // Return the data of the front node
    }

    // Function to get the rear element of the deque
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot get rear." << endl;
            return -1;
        }
        return rear->data; // Return the data of the rear node
    }
};

int main()
{
    // Create a deque
    Deque dq;

    // Insert elements at the front and rear
    dq.insertFront(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.insertRear(4);

    // Display front and rear elements
    cout << "Front element: " << dq.getFront() << endl; // Should be 3
    cout << "Rear element: " << dq.getRear() << endl;   // Should be 4

    // Delete front and rear elements
    dq.deleteFront();
    dq.deleteRear();

    // Display front and rear elements again
    cout << "Front element after deletion: " << dq.getFront() << endl; // Should be 1
    cout << "Rear element after deletion: " << dq.getRear() << endl;   // Should be 2

    return 0;
}
