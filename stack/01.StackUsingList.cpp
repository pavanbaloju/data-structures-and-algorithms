#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Stack class using a singly linked list
class Stack
{
private:
    ListNode *topNode; // Pointer to the top node of the stack
    int size;          // To keep track of the stack size

public:
    // Constructor to initialize the stack
    Stack() : topNode(nullptr), size(0) {}

    // Function to push an element onto the stack
    void push(int x)
    {
        ListNode *newNode = new ListNode(x); // Create a new node
        newNode->next = topNode;             // Point it to the current top node
        topNode = newNode;                   // Update the top node to the new node
        size++;                              // Increment the size
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        ListNode *temp = topNode;    // Store the current top node
        topNode = topNode->next;     // Update the top node to the next node
        int poppedValue = temp->val; // Get the value of the popped node
        delete temp;                 // Delete the old top node
        size--;                      // Decrement the size
        return poppedValue;          // Return the popped value
    }

    // Function to get the top element of the stack
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        return topNode->val; // Return the value of the top node
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return topNode == nullptr; // Return true if topNode is nullptr
    }

    // Function to get the size of the stack
    int getSize()
    {
        return size; // Return the current size
    }
};

// Main function to demonstrate the stack operations
int main()
{
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the top element
    cout << "Top element is: " << stack.top() << endl;

    // Pop elements from the stack
    cout << "Popped element is: " << stack.pop() << endl;
    cout << "Popped element is: " << stack.pop() << endl;

    // Print the top element
    cout << "Top element is: " << stack.top() << endl;

    // Print the current size of the stack
    cout << "Current stack size: " << stack.getSize() << endl;

    return 0;
}
