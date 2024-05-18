#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head(nullptr) {}

    // Add a node of value val at the head of the list
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Add a node of value val at the tail of the list
    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Reverse the linked list using a stack
    void reverseUsingStack() {
        if (!head) return;

        stack<ListNode*> nodeStack;
        ListNode* current = head;

        // Push all nodes onto the stack
        while (current) {
            nodeStack.push(current);
            current = current->next;
        }

        // Pop from the stack and rearrange pointers
        head = nodeStack.top();
        nodeStack.pop();
        current = head;

        while (!nodeStack.empty()) {
            current->next = nodeStack.top();
            nodeStack.pop();
            current = current->next;
        }

        current->next = nullptr;  // Set the last node's next to nullptr
    }

    // Reverse the linked list iteratively
    void reverseIterative()
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current)
        {
            next = current->next; // store next node
            current->next = prev; // reverse current node's pointer
            prev = current;       // move pointers one position ahead
            current = next;
        }

        head = prev;
    }

    // Reverse the linked list recursively
    ListNode *reverseRecursive(ListNode *node)
    {
        if (!node || !node->next)
            return node;

        ListNode *rest = reverseRecursive(node->next);
        node->next->next = node;
        node->next = nullptr;

        return rest;
    }

    // Wrapper function for recursive reverse
    void reverseRecursive()
    {
        head = reverseRecursive(head);
    }

    // Print the linked list
    void printList()
    {
        ListNode *current = head;
        while (current)
        {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~SinglyLinkedList()
    {
        while (head)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    ListNode *head;
};

int main()
{
    SinglyLinkedList *linkedList = new SinglyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(2);
    linkedList->addAtTail(3);
    linkedList->addAtTail(4);
    linkedList->addAtTail(5);

    cout << "Original list: ";
    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    linkedList->reverseIterative();
    cout << "Reversed list (Iterative): ";
    linkedList->printList(); // Output: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

    linkedList->reverseRecursive();
    cout << "Reversed list (Recursive): ";
    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    linkedList->reverseUsingStack();
    cout << "Reversed list (Stack): ";
    linkedList->printList(); // Output: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

    // Clean up
    delete linkedList;

    return 0;
}
