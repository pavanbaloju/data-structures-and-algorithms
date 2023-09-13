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

bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *newHead = nullptr, *nxt = nullptr;
    while (slow)
    {
        nxt = slow->next;
        slow->next = newHead;
        newHead = slow;
        slow = nxt;
    }
    slow = newHead;
    fast = head;
    while (slow)
    {
        if (slow->val != fast->val)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    cout << isPalindrome(head);
    return 0;
}