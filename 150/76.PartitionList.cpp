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

ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy1 = new ListNode(0);
    ListNode *dummy2 = new ListNode(0);
    ListNode *left = dummy1, *right = dummy2;

    while (head)
    {
        if (head->val < x)
        {
            left->next = head;
            left = left->next;
        }
        else
        {
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }
    left->next = dummy2->next;
    right->next = nullptr;
    return dummy1->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(7);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);

    ListNode *res = partition(head, 6);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}