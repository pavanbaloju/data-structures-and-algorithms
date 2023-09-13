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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *l = dummy, *r = head;

    while (r)
    {
        if (r->val == val)
        {
            l->next = r->next;
        }
        else
        {
            l = l->next;
        }
        r = r->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);

    head = removeElements(head, 2);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}