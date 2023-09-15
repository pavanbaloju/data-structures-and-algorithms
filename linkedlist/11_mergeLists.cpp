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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0), *curr = dummy;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    while (list1)
    {
        curr->next = list1;
        curr = curr->next;
        list1 = list1->next;
    }
    while (list2)
    {
        curr->next = list2;
        curr = curr->next;
        list2 = list2->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(4);

    ListNode *headB = new ListNode(1);
    headB->next = new ListNode(3);
    headB->next->next = new ListNode(4);

    ListNode *res = mergeTwoLists(headA, headB);

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