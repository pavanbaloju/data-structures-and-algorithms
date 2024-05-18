#include <iostream>
#include <climits>
using namespace std;

// Node structure for the linked list
struct ListNode
{
    int val;
    int minVal; // Minimum value in the stack up to this node
    ListNode *next;
    ListNode(int x, int minVal) : val(x), minVal(minVal), next(nullptr) {}
};

// MinStack class using a singly linked list
class MinStack
{
private:
    ListNode *topNode; // Pointer to the top node of the stack

public:
    // Constructor to initialize the stack
    MinStack() : topNode(nullptr) {}

    // Function to push an element onto the stack
    void push(int x)
    {
        if (topNode == nullptr)
        {
            topNode = new ListNode(x, x); // If the stack is empty, the minVal is the value itself
        }
        else
        {
            topNode = new ListNode(x, min(x, topNode->minVal)); // New node's minVal is the minimum of x and the current top node's minVal
            topNode->next = topNode;
        }
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        ListNode *temp = topNode; // Store the current top node
        topNode = topNode->next;  // Update the top node to the next node
        delete temp;              // Delete the old top node
    }

    // Function to get the top element of the stack
    int top()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        return topNode->val; // Return the value of the top node
    }

    // Function to retrieve the minimum element in the stack
    int getMin()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if the stack is empty
        }
        return topNode->minVal; // Return the minimum value in the stack
    }
};

// Main function to demonstrate the MinStack operations
int main()
{
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(10);
    minStack.push(20);
    minStack.push(5);

    // Print the top element
    cout << "Top element is: " << minStack.top() << endl; // Output: 5

    // Print the minimum element
    cout << "Minimum element is: " << minStack.getMin() << endl; // Output: 5

    // Pop an element from the stack
    minStack.pop();

    // Print the top element
    cout << "Top element is: " << minStack.top() << endl; // Output: 20

    // Print the minimum element
    cout << "Minimum element is: " << minStack.getMin() << endl; // Output: 10

    return 0;
}
