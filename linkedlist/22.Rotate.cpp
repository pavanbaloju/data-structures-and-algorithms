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
};

/**
 * Function to calculate the length of a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @return Length of the linked list.
 * 
 * Intuition:
 * To calculate the length of a linked list, we can use the two-pointer technique.
 * We traverse the list with two pointers, one moving twice as fast as the other.
 * When the fast pointer reaches the end of the list, the slow pointer will be at the middle (or end) of the list.
 * 
 * Approach:
 * - Initialize two pointers, fast and slow, both pointing to the head of the list.
 * - Move the fast pointer two steps and the slow pointer one step at a time.
 * - Count the number of steps taken until the fast pointer reaches the end of the list.
 * - Return twice the count if the fast pointer is not null (odd length), otherwise return twice the count minus one (even length).
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(1), constant space used.
 */
int length(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    int len = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        len++;
    }
    return (fast) ? 2 * len + 1 : 2 * len;
}

/**
 * Function to rotate a linked list to the right by k positions.
 * 
 * @param head Pointer to the head of the linked list.
 * @param k Number of positions to rotate the list to the right.
 * @return Pointer to the head of the rotated linked list.
 * 
 * Intuition:
 * To rotate a linked list to the right by k positions, we can follow these steps:
 * 1. Calculate the length of the list.
 * 2. Adjust k to be less than the length of the list by taking its modulo with the length.
 * 3. If k is zero, return the original list.
 * 4. Traverse the list to the (length - k)th node.
 * 5. Set the next pointer of this node to nullptr to disconnect the list.
 * 6. Set the head of the original list to the next node of the (length - k)th node.
 * 7. Traverse the remaining k - 1 nodes to reach the end of the list.
 * 8. Set the next pointer of the last node to point to the original head of the list.
 * 9. Return the head of the rotated list.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(1), constant space used.
 */
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;

    int len = length(head);
    ListNode *temp = head;
    k = k % len;
    if (k == 0)
    {
        return head;
    }

    // Traverse to the (length - k)th node
    for (int i = 1; i < len - k; i++)
    {
        temp = temp->next;
    }
    ListNode *oldHead = head;
    head = temp->next;
    temp->next = nullptr;

    temp = head;
    // Traverse the remaining k - 1 nodes to reach the end of the list
    while (--k)
    {
        temp = temp->next;
    }
    // Set the next pointer of the last node to point to the original head of the list
    temp->next = oldHead;
    return head;
}

int main()
{
    // Create a linked list with values 1, 2, 3, 4
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);

    // Rotate the linked list to the right by 2 positions
    ListNode *res = rotateRight(headA, 2);

    // Output the values of the rotated list
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
