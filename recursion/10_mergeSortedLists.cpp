#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }

    ListNode *l1 = list1, *l2 = list2;
    list1 = l1->val < l2->val ? l1 : l2;
    list2 = l1->val < l2->val ? l2 : l1;
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
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
}