#include <iostream>
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

    // Find the middle node using the two-pointer (fast and slow) approach
    ListNode *findMiddleTwoPointer()
    {
        if (!head)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Find the middle node using length calculation approach
    ListNode *findMiddleLength()
    {
        if (!head)
            return nullptr;

        int length = 0;
        ListNode *current = head;
        while (current)
        {
            length++;
            current = current->next;
        }

        current = head;
        for (int i = 0; i < length / 2; ++i)
        {
            current = current->next;
        }

        return current;
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

    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    // Find the middle using the two-pointer approach
    ListNode *middle = linkedList->findMiddleTwoPointer();
    if (middle)
    {
        cout << "Middle element (Two-Pointer): " << middle->val << endl; // Output: 3
    }

    // Find the middle using the length calculation approach
    middle = linkedList->findMiddleLength();
    if (middle)
    {
        cout << "Middle element (Length Calculation): " << middle->val << endl; // Output: 3
    }

    // Clean up
    delete linkedList;

    return 0;
}
