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

ListNode* reverseBetween(ListNode* head, int m, int n) 
{ 
    // First move the current pointer to the Listnode from where 
    // we have to reverse the linked list 
    ListNode *curr = head, *prev = NULL; 
    // prev points to the Listnode before mth Listnode 
    int i; 
    for (i = 1; i < m; i++) { 
        prev = curr; 
        curr = curr->next; 
    } 
    // This pointer stores the pointer to the head of the 
    // reversed linkedlist 
    ListNode* rtail = curr; 
    // This pointer stores the pointer to the tail of the 
    // reversed linkedlist 
    ListNode* rhead = NULL; 
    // Now reverse the linked list from m to n Listnodes 
    while (i <= n) { 
        ListNode* next = curr->next; 
        curr->next = rhead; 
        rhead = curr; 
        curr = next; 
        i++; 
    } 
    // if prev is not null it means that some of the Listnodes 
    // exits before m  or we can say m!=1 
    if (prev != NULL) 
        prev->next = rhead; 
    else
        head = rhead; 
    // at this point curr will point to the next of nth 
    // Listnode where we will connect the tail of the reversed 
    // linked list 
    rtail->next = curr; 
    // at the end return the new head. 
    return head; 
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseBetween(head, 2, 4);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}