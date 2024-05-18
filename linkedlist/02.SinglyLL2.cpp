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
class MyLinkedList
{
public:
    MyLinkedList()
    {
        dummy = new ListNode(0);
        size = 0;
    }

    // Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        ListNode *current = dummy->next;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->val;
    }

    // Add a node of value val before the first element of the linked list. 
    // After the insertion, the new node will be the first node of the linked list.
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    // Add a node of value val before the index-th node in the linked list. 
    // If index equals the length of the linked list, the node will be appended to the end of the linked list. 
    // If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        ListNode *newNode = new ListNode(val);
        ListNode *current = dummy;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        ListNode *current = dummy;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        ListNode *temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }

    ~MyLinkedList()
    {
        ListNode *current = dummy;
        while (current != nullptr)
        {
            ListNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

private:
    ListNode *dummy;
    int size;
};

int main()
{
    MyLinkedList *linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);       // linked list becomes 1->2->3
    cout << linkedList->get(1) << endl; // returns 2
    linkedList->deleteAtIndex(1);       // now the linked list is 1->3
    cout << linkedList->get(1) << endl; // returns 3

    // Clean up
    delete linkedList;

    return 0;
}
