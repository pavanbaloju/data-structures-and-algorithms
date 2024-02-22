#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    // Constructors for ListNode
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

// Problem Statement:
// Given the head of a linked list and an integer val, remove all nodes of the linked list that have 
// a value val, and return the new head.

// Intuition:
// To remove elements with a given value from a linked list, we can use two pointers - one to iterate
// through the list and another to keep track of the previous node. Whenever we encounter a node with
// the target value, we simply skip it by updating the 'next' pointer of the previous node.

// DSA Strategy:
// Two Pointers, Linked List

// Approach:
// 1. Create a dummy node and set its next pointer to the head of the given linked list.
// 2. Initialize two pointers 'l' and 'r' to the dummy node and the head respectively.
// 3. Traverse the linked list using 'r':
//    a. If the value of 'r' equals the target value, skip 'r' by updating 'l->next' to 'r->next'.
//    b. Otherwise, move both 'l' and 'r' pointers to their next nodes.
// 4. Return the 'next' pointer of the dummy node, which represents the head of the modified list.

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), constant extra space is used.

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *l = dummy, *r = head;

    while (r)
    {
        if (r->val == val)
        {
            l->next = r->next;
        }
        else
        {
            l = l->next;
        }
        r = r->next;
    }
    return dummy->next;
}

// Main function to demonstrate the removeElements function
int main()
{
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 2 -> 5 -> 2
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);

    // Call the removeElements function to remove all nodes with value 2
    head = removeElements(head, 2);

    // Print the modified linked list
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
