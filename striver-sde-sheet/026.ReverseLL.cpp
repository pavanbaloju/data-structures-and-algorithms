#include <iostream>
#include <stack>
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

    // Constructor to initialize a ListNode with a given value and next pointer.
    ListNode(int x, ListNode *nxt)
    {
        val = x;
        next = nxt;
    }
};


// Function to reverse a singly-linked list using a stack.
// Intuition:
// In the stack-based approach, we use a stack to store the nodes of the list.
// We traverse the list and push each node onto the stack.
// Then, we pop nodes from the stack and link them together to form the reversed list.
// Finally, we return the new head of the reversed list.
// Approach:
// - Create a stack to store the nodes.
// - Traverse the list and push each node onto the stack.
// - Pop nodes from the stack and link them together to form the reversed list.
// - Set the last node's next pointer to nullptr.
// - Return the new head of the reversed list.
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(n), where n is the number of nodes in the list (space used by the stack).
ListNode *reverseListStack(ListNode *head)
{
    // Create a stack to store the nodes.
    stack<ListNode *> nodeStack;

    // Push all nodes onto the stack.
    while (head != nullptr)
    {
        nodeStack.push(head);
        head = head->next;
    }

    // Create a new dummy head.
    ListNode *dummyHead = new ListNode(-1);
    ListNode *current = dummyHead;

    // Pop nodes from the stack and link them to form the reversed list.
    while (!nodeStack.empty())
    {
        current->next = nodeStack.top();
        nodeStack.pop();
        current = current->next;
    }

    // Set the last node's next pointer to nullptr.
    current->next = nullptr;

    // Return the new head of the reversed list.
    return dummyHead->next;
}

// Function to reverse a singly-linked list iteratively.
// Intuition:
// In the iterative approach, we use three pointers to reverse the pointers of each node in the list.
// We iterate through the list and reverse the next pointer of each node to point to the previous node.
// Finally, we return the new head of the reversed list.
// Approach:
// - Initialize previous, current, and next pointers.
// - Iterate through the list and reverse pointers by updating the next pointer of each node to point to the previous node.
// - Update the previous and current pointers.
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1), constant space used.
ListNode *reverseListIterative(ListNode *head)
{
    // Initialize previous and current pointers.
    ListNode *prev = nullptr;
    ListNode *curr = head;

    // Iterate through the list and reverse pointers.
    while (curr != nullptr)
    {
        // Store the next node temporarily.
        ListNode *nxt = curr->next;

        // Reverse the pointer of the current node to point to the previous node.
        curr->next = prev;

        // Move prev and curr pointers one step forward.
        prev = curr;
        curr = nxt;
    }

    // Return the new head of the reversed list (previous node, which becomes the last node).
    return prev;
}

// Function to reverse a singly-linked list using recursion.
// Intuition:
// In the recursive approach, we recursively reverse the rest of the list starting from the second node.
// We then reverse the pointer of the next node to point to the current node and update the next pointer of the current node to nullptr.
// Finally, we return the new head of the reversed list.
// Approach:
// - Base case: If the head is null or the list has only one node, return the head.
// - Recursively reverse the rest of the list.
// - Reverse the pointer of the next node to point to the current node.
// - Set the current node's next pointer to nullptr.
// - Return the new head of the reversed list (which is the last node of the original list).
ListNode *reverseListRecursion(ListNode *head)
{
    // Base case: If the head is null or the list has only one node, return the head.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse the rest of the list.
    ListNode *rest = reverseListRecursion(head->next);

    // Reverse the pointer of the next node to point to the current node.
    head->next->next = head;

    // Set the current node's next pointer to null to mark the end of the reversed list.
    head->next = nullptr;

    // Return the new head of the reversed list (which is the last node of the original list).
    return rest;
}


int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse the linked list iteratively.
    ListNode *reversedHeadIterative = reverseListIterative(head);

    // Output the values of the reversed linked list (iterative).
    cout << "Iterative: ";
    while (reversedHeadIterative != nullptr)
    {
        cout << reversedHeadIterative->val << " ";
        reversedHeadIterative = reversedHeadIterative->next;
    }
    cout << endl;

    // Create a new linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    // Reverse the linked list using recursion.
    ListNode *reversedHeadRecursion = reverseListRecursion(head2);

    // Output the values of the reversed linked list (recursive).
    cout << "Recursive: ";
    while (reversedHeadRecursion != nullptr)
    {
        cout << reversedHeadRecursion->val << " ";
        reversedHeadRecursion = reversedHeadRecursion->next;
    }
    cout << endl;

    // Create a new linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);

    // Reverse the linked list using a stack.
    ListNode *reversedHeadStack = reverseListStack(head3);

    // Output the values of the reversed linked list (stack).
    cout << "Stack: ";
    while (reversedHeadStack != nullptr)
    {
        cout << reversedHeadStack->val << " ";
        reversedHeadStack = reversedHeadStack->next;
    }
    cout << endl;

    return 0;
}
