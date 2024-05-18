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

    // Remove all elements equal to a given value
    void removeElements(int val)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to handle the case where head needs to be removed
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;

        while (current)
        {
            if (current->val == val)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        head = dummy->next; // Update head after removals
        delete dummy;
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
    linkedList->addAtTail(6);
    linkedList->addAtTail(3);
    linkedList->addAtTail(4);
    linkedList->addAtTail(5);
    linkedList->addAtTail(6);

    cout << "Original list: ";
    linkedList->printList(); // Output: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6 -> nullptr

    int valToRemove = 6;
    linkedList->removeElements(valToRemove);

    cout << "List after removing " << valToRemove << ": ";
    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    // Clean up
    delete linkedList;

    return 0;
}
