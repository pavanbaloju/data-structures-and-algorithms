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

ListNode *getKthNode(ListNode *head, int k)
{
    k--;
    while (head && k-- > 0)
    {
        head = head->next;
    }

    return head;
}

void reverseList(ListNode *head)
{
    ListNode *temp = head, *prev = nullptr;
    while (temp)
    {
        ListNode *nxt = temp->next;
        temp->next = prev;

        prev = temp;
        temp = nxt;
    }
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(0);
    ListNode *prevEnd = dummy;

    while (temp != nullptr)
    {
        ListNode *kth = getKthNode(temp, k);
        if (kth == nullptr)
        {
            prevEnd->next = temp;
            break;
        }

        ListNode *nxt = kth->next;
        kth->next = nullptr;

        reverseList(temp);

        if (head == temp)
            head = kth;
        else
            prevEnd->next = kth;

        prevEnd = temp;
        temp = nxt;
    }
    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    printLinkedList(head);

    head = reverseKGroup(head, 7);

    printLinkedList(head);

    return 0;
}