#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    // Constructor to initialize a ListNode with a given value and next pointer.
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists.
// Intuition:
// We initialize a dummy node to hold the merged list.
// We then traverse both input lists simultaneously, comparing the values of their nodes.
// We append the smaller node to the merged list and move the corresponding pointer forward.
// Once one of the lists is exhausted, we append the remaining nodes of the other list to the merged list.
// Approach:
// - Initialize a dummy node and a current pointer to hold the merged list.
// - Traverse both input lists simultaneously:
//   - Compare the values of the current nodes of the input lists.
//   - Append the smaller node to the merged list and move the corresponding pointer forward.
// - Append the remaining nodes of the non-empty list to the merged list.
// - Return the merged list.
// Time Complexity: O(n + m), where n and m are the lengths of the input lists.
// Space Complexity: O(1), constant space used.
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0), *curr = dummy;

    // Traverse both lists until one of them is exhausted.
    while (list1 && list2)
    {
        if (list1->val < list2->val)
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

    // Append the remaining nodes of the non-empty list to the merged list.
    while (list1)
    {
        curr->next = list1;
        curr = curr->next;
        list1 = list1->next;
    }
    while (list2)
    {
        curr->next = list2;
        curr = curr->next;
        list2 = list2->next;
    }

    // Return the merged list.
    return dummy->next;
}

// Function to merge two sorted linked lists recursively.
// Intuition:
// The recursive approach mimics the iterative approach.
// We compare the values of the current nodes of the input lists and recursively merge the rest of the lists.
// We return the merged list when one of the lists is exhausted.
// Approach:
// - Base cases:
//   - If one of the input lists is null, return the other list.
// - Compare the values of the current nodes of the input lists:
//   - Select the smaller node as the head of the merged list.
//   - Recursively merge the rest of the lists starting from the next node of the selected node.
// - Return the head of the merged list.
// Time Complexity: O(n + m), where n and m are the lengths of the input lists.
// Space Complexity: O(n + m), where n and m are the lengths of the input lists (due to recursive calls).
ListNode *mergeTwoListsRecursive(ListNode *list1, ListNode *list2)
{
    // Base cases: if one of the lists is null, return the other list.
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }

    // Select the smaller node as the head of the merged list.
    ListNode *l1 = list1, *l2 = list2;
    list1 = l1->val < l2->val ? l1 : l2;
    list2 = l1->val < l2->val ? l2 : l1;

    // Recursively merge the rest of the lists.
    list1->next = mergeTwoLists(list1->next, list2);

    // Return the head of the merged list.
    return list1;
}

int main()
{
    // Create two sorted linked lists.
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(4);

    ListNode *headB = new ListNode(1);
    headB->next = new ListNode(3);
    headB->next->next = new ListNode(4);

    // Merge the lists using the iterative approach and output the merged list.
    ListNode *res = mergeTwoLists(headA, headB);
    cout << "Merged List (Iterative): ";
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    // Merge the lists using the recursive approach and output the merged list.
    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(4);

    headB = new ListNode(1);
    headB->next = new ListNode(3);
    headB->next->next = new ListNode(4);

    ListNode *resRecursive = mergeTwoListsRecursive(headA, headB);
    cout << "Merged List (Recursive): ";
    while (resRecursive)
    {
        cout << resRecursive->val << " ";
        resRecursive = resRecursive->next;
    }
    cout << endl;

    return 0;
}
