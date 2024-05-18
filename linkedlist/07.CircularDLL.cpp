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

// Circular Doubly Linked List class
class MyCircularDoublyLinkedList
{
public:
    MyCircularDoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        ListNode *current = head;
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
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        size++;
    }

    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
    }

    // Add a node of value val before the index-th node in the linked list. If index equals the length of the linked list, the node
    // will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
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
        ListNode *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
        {
            ListNode *temp = head;
            if (size == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            delete temp;
        }
        else
        {
            ListNode *current = head;
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (index == size - 1)
            {
                tail = current->prev;
            }
            delete current;
        }
        size--;
    }

    ~MyCircularDoublyLinkedList()
    {
        while (size > 0)
        {
            deleteAtIndex(0);
        }
    }

private:
    ListNode *head;
    ListNode *tail;
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
