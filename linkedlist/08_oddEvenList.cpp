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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *odd = head, *even = head->next, *es = head->next;

    while (odd->next && even->next)
    {
        odd->next = even->next;
        even->next = even->next->next;
        even = even->next;
        odd = odd->next;
    }
    odd->next = es;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    head = oddEvenList(head);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}