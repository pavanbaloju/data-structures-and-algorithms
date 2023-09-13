#include <iostream>
#include <vector>
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
    ListNode(int x, ListNode *nxt)
    {
        val = x;
        next = nxt;
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *newHead = nullptr, *nxt = nullptr;
    while (head)
    {
        nxt = head->next;
        head->next = newHead;
        newHead = head;
        head = nxt;
    }
    return newHead;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseList(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}