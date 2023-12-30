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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0), *curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        if (l1)
        {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            carry += l2->val;
            l2 = l2->next;
        }
        curr->next = new ListNode(carry % 10);
        carry = carry / 10;
        curr = curr->next;
    }

    return dummy->next;
}
int main()
{
    ListNode *headA = new ListNode(2);
    headA->next = new ListNode(4);
    headA->next->next = new ListNode(8);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(4);

    ListNode *res = addTwoNumbers(headA, headB);

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
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}