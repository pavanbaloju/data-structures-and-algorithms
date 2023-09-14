#include <iostream>
using namespace std;

class MyLinkedList
{
    struct DLListNode
    {
        int val;
        DLListNode *prev, *next;

        DLListNode(int x)
        {
            val = x;
            prev = nullptr;
            next = nullptr;
        }
    };
    DLListNode *dl, *dr;
    int len = 0;

public:
    MyLinkedList()
    {
        dl = new DLListNode(0);
        dr = new DLListNode(0);
        dl->next = dr;
        dr->prev = dl;
    }

    int get(int index)
    {
        if (index < 0 || index >= len)
        {
            return -1;
        }
        DLListNode *curr = dl->next;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        DLListNode *newNode = new DLListNode(val);
        newNode->next = dl->next;
        dl->next = newNode;
        newNode->prev = dl;
        newNode->next->prev = newNode;
        len++;
    }

    void addAtTail(int val)
    {
        DLListNode *curr = dr->prev;
        DLListNode *newNode = new DLListNode(val);
        newNode->next = dr;
        newNode->prev = curr;
        curr->next = newNode;
        dr->prev = newNode;
        len++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
        {
            return;
        }
        DLListNode *curr = dl->next;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        DLListNode *newNode = new DLListNode(val), *prev = curr->prev;
        newNode->next = curr;
        newNode->prev = prev;
        prev->next = newNode;
        curr->prev = newNode;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
        {
            return;
        }
        DLListNode *curr = dl->next;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        DLListNode *prev = curr->prev;
        prev->next = curr->next;
        curr->next->prev = prev;
        delete (curr);
        len--;
    }
};

int main()
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    cout << myLinkedList.get(1);   // return 2
    myLinkedList.deleteAtIndex(1); // now the linked list is 1->3
    cout << myLinkedList.get(1);
    return 0;
}