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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *f = headA, *s = headB;
    while (f != s)
    {
        f = f ? f->next : headB;
        s = s ? s->next : headA;
    }
    return f;
}

int main()
{
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    cout << getIntersectionNode(headA, headB)->val << endl;

    while (headB)
    {
        cout << headB->val << " ";
        headB = headB->next;
    }
    cout << endl;
    while (headA)
    {
        cout << headA->val << " ";
        headA = headA->next;
    }
    cout << endl;
    return 0;
}