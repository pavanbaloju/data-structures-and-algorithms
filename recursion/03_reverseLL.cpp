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

ListNode *reverse(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode *newHead = reverse(head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}