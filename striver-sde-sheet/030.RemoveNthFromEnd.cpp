#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    // Constructor to initialize a ListNode with a given value and next pointer.
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor to initialize a ListNode with a given value and next pointer.
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

/**
 * Intuition:
 * We first count the number of nodes in the list.
 * Then, we calculate the position of the node to remove from the beginning (count - n).
 * Finally, we iterate through the list to find the node at the calculated position and remove it.
 *
 * Approach:
 * - Count the number of nodes in the list.
 * - Calculate the position of the node to remove from the beginning (count - n).
 * - Iterate through the list to find the node at the calculated position.
 * - Remove the node from the list.
 * - Return the head of the modified list.
 *
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(1), constant space used.
 */
ListNode *removeNthFromEndBrute(ListNode *head, int n)
{
    // Count the number of nodes in the list.
    int count = 0;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    // Calculate the position of the node to remove from the beginning (count - n).
    int pos = count - n;

    // Handle the case when the node to remove is the head of the list.
    if (pos == 0)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Iterate through the list to find the node at the calculated position.
    curr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        curr = curr->next;
    }

    // Remove the node from the list.
    ListNode *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    // Return the head of the modified list.
    return head;
}

/**
 * Intuition:
 * To remove the Nth node from the end of the list, we can use a two-pointer approach.
 * We use two pointers, slow and fast, initially pointing to the dummy node and the head of the list, respectively.
 * We move the fast pointer n steps ahead.
 * Then, we move both pointers until the fast pointer reaches the end of the list.
 * At this point, the slow pointer will be at the node just before the Nth node from the end.
 * We update the next pointer of the node pointed to by the slow pointer to skip the Nth node.
 * Finally, we return the head of the modified list.
 *
 * Approach:
 * - Create a dummy node and set its next pointer to the head of the list.
 * - Initialize slow and fast pointers to the dummy node and the head of the list, respectively.
 * - Move the fast pointer n steps ahead.
 * - Move both pointers until the fast pointer reaches the end of the list.
 * - Update the next pointer of the node pointed to by the slow pointer to skip the Nth node.
 * - Return the head of the modified list.
 *
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(1), constant space used.
 */
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Create a dummy node and set its next pointer to the head of the list.
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy, *fast = head;

    // Move the fast pointer n steps ahead.
    while (n-- && fast)
    {
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end of the list.
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Update the next pointer of the node pointed to by the slow pointer to skip the Nth node.
    slow->next = slow->next->next;

    // Return the head of the modified list.
    return dummy->next;
}

int main()
{

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Remove the 2nd node from the end using brute force.
    head = removeNthFromEndBrute(head, 2);

    // Output the values of the modified list.
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Remove the 2nd node from the end.
    head = removeNthFromEnd(head, 2);

    // Output the values of the modified list.
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
