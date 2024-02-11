#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Deletes the given node from the linked list.
 *
 * @param node Pointer to the node to be deleted.
 *
 * Intuition:
 * Since we don't have access to the head of the linked list, we can't directly remove the given node.
 * However, we can achieve the effect of deletion by copying the value of the next node to the given node,
 * and then removing the next node from the list.
 *
 * Approach:
 * - Copy the value of the next node to the given node.
 * - Delete the next node by updating the next pointer of the given node to skip the next node.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void deleteNode(ListNode *node)
{
    // Copy the value of the next node to the given node
    node->val = node->next->val;
    // Delete the next node by updating the next pointer of the given node
    node->next = node->next->next;
}

int main()
{
    // Create a linked list: 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Select the node with value 5 to be deleted
    ListNode *nodeToDelete = head->next;

    // Delete the selected node
    deleteNode(nodeToDelete);

    // Output the values of the modified linked list
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
