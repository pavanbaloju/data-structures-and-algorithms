#include <iostream>
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
// Given the head of a singly linked list, group all the nodes with odd indices together followed
// by the nodes with even indices. The relative order within each group should remain as it was in
// the input.

// Intuition:
// We can solve this problem in a single pass by maintaining two pointers, 'odd' and 'even', to represent
// the heads of the odd and even indexed groups respectively. Additionally, we need to keep track of the
// start of the even-indexed group ('es') to link the end of the odd-indexed group with the start of the
// even-indexed group.

// DSA Strategy:
// Two Pointers, Linked List

// Approach:
// 1. Initialize 'odd' and 'even' pointers to the head and the head's next node respectively.
// 2. Initialize 'es' (even start) to the head's next node to represent the start of the even-indexed group.
// 3. Traverse the list using a while loop until 'odd->next' and 'even->next' are not null:
//    a. Move 'odd->next' to 'even->next' to connect the odd-indexed group.
//    b. Move 'even->next' to 'even->next->next' to update the even-indexed group.
//    c. Move 'odd' and 'even' to their next nodes.
// 4. Connect the end of the odd-indexed group to the start of the even-indexed group using 'odd->next = es'.
// 5. Return the head of the modified linked list.

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), constant extra space is used.

ListNode *oddEvenList(ListNode *head)
{
    // If the list is empty or has only one node, return the original list
    if (!head || !head->next)
        return head;

    ListNode *odd = head, *even = head->next, *es = head->next;

    // Traverse the list using a while loop until 'odd->next' and 'even->next' are not null:
    while (odd->next && even->next)
    {
        // Move 'odd->next' to 'even->next' to connect the odd-indexed group.
        odd->next = even->next;

        // Move 'even->next' to 'even->next->next' to update the even-indexed group.
        even->next = even->next->next;

        // Move 'even' to its next node.
        even = even->next;

        // Move 'odd' to its next node.
        odd = odd->next;
    }

    odd->next = es; // Connect the end of the odd-indexed group to the start of the even-indexed group

    return head;
}

// Main function to demonstrate the oddEvenList function
int main()
{
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    // Call the oddEvenList function to group nodes with odd indices together
    head = oddEvenList(head);

    // Print the modified linked list
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
