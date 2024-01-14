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

ListNode *mergelist(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
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

    if (list1 != nullptr)
    {
        curr->next = list1;
        list1 = list1->next;
    }

    if (list2 != nullptr)
    {
        curr->next = list2;
        list2 = list2->next;
    }

    return dummy->next;
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

    return mergelist(list1, list2);
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