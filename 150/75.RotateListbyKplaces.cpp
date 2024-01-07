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
};
int length(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    int len = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        len++;
    }
    return (fast) ? 2 * len + 1 : 2 * len;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;

    int len = length(head);
    k = k % len;
    if (k == 0)
        return head;

    // move right by n-k and split the list into two and create new head
    ListNode *temp = head;
    for (int i = 1; i < len - k; i++)
    {
        temp = temp->next;
    }
    ListNode *oldHead = head;
    head = temp->next;
    temp->next = nullptr;

    // attach old head to the end of second list which has new head
    temp = head;
    while (--k)
    {
        temp = temp->next;
    }
    temp->next = oldHead;
    return head;
}

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);

    ListNode *res = rotateRight(headA, 2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}