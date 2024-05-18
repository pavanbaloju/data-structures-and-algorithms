#include <iostream>
using namespace std;

// Definition for doubly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class MyLinkedList
{
public:
    MyLinkedList()
    {
        dummy = new ListNode(0); // Dummy node
        dummy->next = dummy;
        dummy->prev = dummy;
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
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        ListNode *current = dummy;
        for (int i = 0; i <= index; ++i)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    ~MyLinkedList()
    {
        ListNode *current = dummy->next;
        while (current != dummy)
        {
            ListNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete dummy;
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
#include <iostream>
using namespace std;

// Definition for doubly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Circular Doubly Linked List class with a dummy node
class MyCircularDoublyLinkedList
{
public:
    MyCircularDoublyLinkedList()
    {
        dummy = new ListNode(0);
        dummy->next = dummy;
        dummy->prev = dummy;
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
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *nextNode = dummy->next;
        newNode->next = nextNode;
        newNode->prev = dummy;
        dummy->next = newNode;
        nextNode->prev = newNode;
        size++;
    }

    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *prevNode = dummy->prev;
        newNode->next = dummy;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        dummy->prev = newNode;
        size++;
    }

    // Add a node of value val before the index-th node in the linked list. If index equals the length of the linked list,
    // the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        ListNode *newNode = new ListNode(val);
        ListNode *current = dummy->next;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        ListNode *prevNode = current->prev;
        newNode->next = current;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        current->prev = newNode;
        size++;
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        ListNode *current = dummy->next;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        ListNode *prevNode = current->prev;
        ListNode *nextNode = current->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete current;
        size--;
    }

    ~MyCircularDoublyLinkedList()
    {
        while (size > 0)
        {
            deleteAtIndex(0);
        }
        delete dummy;
    }

private:
    ListNode *dummy;
    int size;
};

int main()
{
    MyCircularDoublyLinkedList *linkedList = new MyCircularDoublyLinkedList();
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
