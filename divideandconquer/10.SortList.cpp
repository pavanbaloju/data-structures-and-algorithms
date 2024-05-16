#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given the head of a singly linked list, sort the list using merge sort algorithm.

// Intuition:
// The problem can be solved using merge sort, a divide-and-conquer algorithm.
// We divide the list into two halves recursively until we reach a point where each half contains only one node (or is empty).
// Then, we merge these halves in a sorted manner until we obtain the final sorted list.

// DSA Strategy:
// Merge Sort, Linked List

// Approach:
// 1. Define a ListNode structure representing a node in a singly linked list.
// 2. Implement a function 'merge' to merge two sorted linked lists into one sorted linked list.
//    - Base cases: if either list is empty, return the other list.
//    - Compare the values of the heads of both lists.
//    - Assign the smaller (or equal) value as the current node and merge the rest of the lists.
// 3. Implement a function 'getMiddle' to find the middle node of a linked list using the slow and fast pointer technique.
// 4. Implement a function 'sortList' to perform merge sort on the linked list.
//    - Base case: if the list is empty or has only one node, it is already sorted, so return it.
//    - Find the middle node of the list and split it into two halves.
//    - Recursively sort the left and right halves of the list.
//    - Merge the sorted left and right halves using the 'merge' function.
// 5. In the main function, construct a sample linked list and call 'sortList' to sort it.
// 6. Print the sorted list.

// Time Complexity: O(n log n), where n is the number of nodes in the linked list.
// Space Complexity: O(log n) due to the recursion stack.

// Definition of a node in a singly linked list
struct ListNode
{
    int val;        // Value of the node
    ListNode *next; // Pointer to the next node in the list

    // Constructors to initialize a node
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

// Function to merge two sorted linked lists into one sorted linked list
ListNode *merge(ListNode *head1, ListNode *head2)
{
    // Base cases: if either list is empty, return the other list
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }

    ListNode *temp;
    // Compare the values of the heads of both lists
    if (head1->val < head2->val)
    {
        // If head1's value is smaller, assign it as the current node and merge the rest of head1 with head2
        temp = head1;
        temp->next = merge(head1->next, head2);
    }
    else
    {
        // If head2's value is smaller (or equal), assign it as the current node and merge the rest of head2 with head1
        temp = head2;
        temp->next = merge(head1, head2->next);
    }
    return temp; // Return the merged list
}

// Function to find the middle node of a linked list
ListNode *getMiddle(ListNode *head)
{
    ListNode *slow = head; // Slow pointer moves one step at a time
    ListNode *fast = head; // Fast pointer moves two steps at a time

    while (fast != nullptr && fast->next != nullptr)
    {
        // Move slow pointer one step ahead
        slow = slow->next;
        // Move fast pointer two steps ahead
        fast = fast->next->next;
    }
    // When fast pointer reaches the end, slow pointer will be at the middle node
    return slow; // Return the middle node (or the node before the middle in case of even number of nodes)
}

// Function to sort a linked list using merge sort
ListNode *sortList(ListNode *head)
{
    // Base case: if the list is empty or has only one node, it is already sorted
    if (head == nullptr || head->next == nullptr)
        return head;

    // Find the middle node of the list
    ListNode *middle = getMiddle(head);
    // Split the list into two halves: left and right
    ListNode *right = middle->next;
    middle->next = nullptr; // Break the link between the two halves
    ListNode *left = head;

    // Recursively sort the left and right halves of the list
    ListNode *list1 = sortList(left);
    ListNode *list2 = sortList(right);

    // Merge the sorted left and right halves
    return merge(list1, list2);
}

int main()
{
    // Construct a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(7);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(4);

    // Sort the linked list using merge sort
    ListNode *node = sortList(head);

    // Print the sorted list
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}
