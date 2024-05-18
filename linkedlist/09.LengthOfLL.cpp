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

    // Calculate the length of the linked list
    int length()
    {
        int len = 0;
        ListNode *current = head;
        while (current)
        {
            len++;
            current = current->next;
        }
        return len;
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

    linkedList->printList();                                               // Output: 1 -> 2 -> 3 -> 4 -> nullptr
    cout << "Length of the linked list: " << linkedList->length() << endl; // Output: 4

    // Clean up
    delete linkedList;

    return 0;
}
