#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Function to get the kth node in a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param k The position of the node to retrieve (1-based index).
 * @return Pointer to the kth node from the head.
 */
ListNode *getKthNode(ListNode *head, int k)
{
    k--; // Adjust k to 0-based index
    while (head && k-- > 0)
    {
        head = head->next;
    }
    return head;
}

/**
 * Function to reverse a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 */
void reverseList(ListNode *head)
{
    ListNode *temp = head, *prev = nullptr;
    while (temp)
    {
        ListNode *nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
}

/**
 * Function to reverse every k nodes in a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param k The size of each group to be reversed.
 * @return Pointer to the new head of the modified list.
 * 
 * Intuition:
 * We can approach this problem by iterating through the list and reversing each group of k nodes.
 * For each group, we find the kth node, reverse the group, and update the pointers accordingly.
 * 
 * Approach:
 * - Initialize a dummy node to hold the result.
 * - Use two pointers to keep track of the current and previous group's end nodes.
 * - Iterate through the list and reverse each group of k nodes.
 * - Update pointers to link the reversed groups together.
 * - Return the new head of the modified list.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(1), constant space used.
 */
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(0); // Dummy node to hold the result
    ListNode *prevEnd = dummy;         // Pointer to the end of the previous group

    while (temp != nullptr)
    {
        ListNode *kth = getKthNode(temp, k); // Get the kth node of the current group
        if (kth == nullptr)
        {
            // If less than k nodes left, append the remaining list to the result
            prevEnd->next = temp;
            break;
        }

        ListNode *nxt = kth->next; // Store the next node after the current group
        kth->next = nullptr;       // Break the list at the end of the current group

        reverseList(temp); // Reverse the current group

        if (head == temp)
            head = kth; // Update the head if it's the first group
        else
            prevEnd->next = kth; // Link the previous group's end to the current group's start

        prevEnd = temp; // Update the end of the previous group (temp which was the start becomes end after reverse)
        temp = nxt;     // Move to the next group
    }
    return head; // Return the new head of the modified list
}

/**
 * Function to print the values of a linked list.
 * 
 * @param head Pointer to the head of the linked list.
 */
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with values 5, 4, 3, 7, 9, and 2
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    cout << "Original Linked List:" << endl;
    printLinkedList(head);

    // Reverse every 7 nodes in the linked list
    head = reverseKGroup(head, 7);

    cout << "Modified Linked List:" << endl;
    printLinkedList(head);

    return 0;
}
