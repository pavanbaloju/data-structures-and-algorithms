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

    // Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
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
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Add a node of value val before the index-th node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else
        {
            ListNode *newNode = new ListNode(val);
            ListNode *current = head;
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            size++;
        }
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        ListNode *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        if (current->prev)
        {
            current->prev->next = current->next;
        }
        else
        {
            head = current->next;
        }
        if (current->next)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev;
        }
        delete current;
        size--;
    }

private:
    ListNode *head;
    ListNode *tail;
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
