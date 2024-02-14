#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given the head of a linked list, return the list after sorting it in ascending order.

// Intuition:
// Use the Insertion Sort algorithm to sort the linked list.

// DSA Strategy:
// Sorting, Linked List

// Approach:
// 1. Create a dummy node to serve as the head of the sorted linked list.
// 2. Iterate through each node of the original linked list.
// 3. For each node, find its correct position in the sorted linked list.
// 4. Insert the node into its correct position.
// 5. Return the next of the dummy node, which contains the head of the sorted linked list.

// Time Complexity: O(N^2), where N is the number of nodes in the linked list.
// Space Complexity: O(1)

// Struct representing a node in the linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to perform Insertion Sort on a linked list
ListNode *insertionSortList(ListNode *head)
{
    // Create a dummy node
    ListNode *dummy = new ListNode();
    // Initialize the current node to the head of the linked list
    ListNode *curr = head;
    // Iterate through each node of the original linked list
    while (curr)
    {
        // Store the next node in a variable
        ListNode *nxt = curr->next;
        // Initialize the previous node to the dummy node
        ListNode *prev = dummy;
        // Find the correct position to insert the current node in the sorted linked list
        while (prev->next && prev->next->val <= curr->val)
        {
            prev = prev->next;
        }
        // Insert the current node into its correct position
        curr->next = prev->next;
        prev->next = curr;
        // Move to the next node in the original linked list
        curr = nxt;
    }
    // Return the next of the dummy node, which contains the head of the sorted linked list
    return dummy->next;
}

// Main function
int main()
{
    // Create the linked list: 4 -> 3 -> 2 -> 1
    ListNode *head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Sort the linked list using Insertion Sort
    head = insertionSortList(head);

    // Print the sorted linked list
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    return 0;
}
