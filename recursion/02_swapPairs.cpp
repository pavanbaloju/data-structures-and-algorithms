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

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    swap(head->val, head->next->val);
    head->next->next = swapPairs(head->next->next);
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode *newHead = swapPairs(head);
    while (newHead)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    
    return 0;
}