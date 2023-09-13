#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};
class MyLinkedList
{
private:
    ListNode *head;
    int len = 0;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        if (index < 0 || index > len -1)
        {
            return -1;
        }
        ListNode *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        len++;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *curr = head, *prev = nullptr;
        if (head == nullptr)
        {
           return addAtHead(val);
        }
        while (curr!= nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        len++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > len)
        {
            return;
        }
        if (index == 0)
        {
            return addAtHead(val);
        }

        ListNode *newNode = new ListNode(val);
        ListNode *curr = head, *prev = nullptr;
        for (int i = 0; i < index; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        len++;
    }

    void deleteAtHead() {
            ListNode *temp = head;
            head = head->next;
            delete (temp);
            len--;
            return;
    }

    void deleteAtIndex(int index)
    {
        if (index > len - 1)
        {
            return;
        }
        if (index ==0)
        {
            return deleteAtHead();
        }
        
        ListNode *curr = head, *prev = nullptr;
        for (int i = 0; i < index; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete(curr);
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