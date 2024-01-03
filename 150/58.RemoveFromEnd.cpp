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

int length(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode *removeNthFromEndUsingCount(ListNode *head, int n)
{
    int Length = length(head);
    int nodeFromBeginning = Length - n + 1;
    ListNode *prev = NULL;
    ListNode *temp = head;
    for (int i = 1; i < nodeFromBeginning; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        head = head->next;
        return head;
    }
    prev->next = prev->next->next;
    return head;
}

// move right n steps ahead of left
// when right is at the end, left will be n steps behind right
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *left = dummy, *right = head;
    while (n-- && right)
    {
        right = right->next;
    }

    while (right != nullptr)
    {
        left = left->next;
        right = right->next;
    }
    left->next = left->next->next;
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = removeNthFromEnd(head, 2);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}