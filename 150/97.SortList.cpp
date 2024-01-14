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

ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    ListNode *temp;
    if (head1->val < head2->val)
    {
        temp = head1;
        temp->next = merge(head1->next, head2);
    }
    else
    {
        temp = head2;
        temp->next = merge(head1, head2->next);
    }
    return temp;
}

ListNode *getMiddle(ListNode *head)
{
    ListNode *temp = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}

ListNode *sortList(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *middle = getMiddle(head);
    ListNode *right = middle->next;
    middle->next = nullptr;
    ListNode *left = head;

    ListNode *list1 = sortList(left);
    ListNode *list2 = sortList(right);

    return merge(list1, list2);
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(7);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(4);

    ListNode *node = sortList(head);
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}