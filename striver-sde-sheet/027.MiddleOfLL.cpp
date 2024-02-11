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

// Function to find the middle node of a singly-linked list.
// Intuition:
// In the brute-force approach, we traverse the entire list to count its length.
// Then, we traverse the list again to find the middle node.
// This approach requires two passes through the list.
// In the optimal approach, we use two pointers, slow and fast, initialized to the head of the list.
// The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
// When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
// Approach:
// - Initialize two pointers, slow and fast, to the head of the list.
// - Traverse the list with the fast pointer moving two steps at a time and the slow pointer moving one step at a time.
// - When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1), constant space used.
ListNode *middleNode(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;

    // Calculate the length of the list.
    while (temp)
    {
        temp = temp->next;
        len++;
    }

    temp = head;

    // Traverse to the middle node of the list.
    for (int i = 0; i < len / 2; i++)
    {
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}

// Function to find the middle node of a singly-linked list using the optimal approach.
// Intuition:
// In the optimal approach, we use two pointers, slow and fast, initialized to the head of the list.
// The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
// When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
// This approach requires only one pass through the list.
// Approach:
// - Initialize two pointers, slow and fast, to the head of the list.
// - Traverse the list with the fast pointer moving two steps at a time and the slow pointer moving one step at a time.
// - When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1), constant space used.
ListNode *middleNodeOptimal(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    // Traverse the list with slow and fast pointers.
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Return the middle node.
    return slow;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Find and output the middle node using the brute-force approach.
    cout << "Middle Node (Brute Force): " << middleNode(head)->val << endl;

    // Find and output the middle node using the optimal approach.
    cout << "Middle Node (Optimal): " << middleNodeOptimal(head)->val << endl;

    return 0;
}
