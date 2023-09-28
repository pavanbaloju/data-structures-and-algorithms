#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// insertion sort
ListNode *insertionSortList(ListNode *head)
{
    
    ListNode *dummy = new ListNode();
    ListNode *curr = head;
    while (curr)
    {
        ListNode *prev = dummy, *nxt = curr->next;
        while (prev->next && prev->next->val <= curr->val)
        {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = nxt;
    }

    return dummy->next;
}
int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    head = insertionSortList(head);
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    return 0;
}