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
    ListNode(int x, ListNode *nxt)
    {
        val = x;
        next = nxt;
    }
};

/**
 * Function to check if a linked list is a palindrome.
 * 
 * @param head Pointer to the head of the linked list.
 * @return True if the linked list is a palindrome, false otherwise.
 * 
 * Intuition:
 * To determine if a linked list is a palindrome, we can follow these steps:
 * 1. Find the middle of the linked list using slow and fast pointers.
 * 2. Reverse the second half of the linked list.
 * 3. Compare the first half with the reversed second half.
 * 
 * Approach:
 * - Use two pointers (slow and fast) to find the middle of the linked list.
 * - Reverse the second half of the linked list.
 * - Compare each node in the first half with the corresponding node in the reversed second half.
 * - If all nodes match, the linked list is a palindrome; otherwise, it is not.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(1), constant space used.
 */
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true; // Empty or single-node linked list is a palindrome

    ListNode *slow = head, *fast = head;
    // Find the middle of the linked list
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    ListNode *newHead = nullptr, *nxt = nullptr;
    while (slow)
    {
        nxt = slow->next;
        slow->next = newHead;
        newHead = slow;
        slow = nxt;
    }

    // Compare the first half with the reversed second half
    slow = newHead;
    fast = head;
    while (slow)
    {
        if (slow->val != fast->val)
        {
            return false; // Not a palindrome
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true; // Linked list is a palindrome
}

int main()
{
    // Create a palindrome linked list: 1 -> 2 -> 3 -> 4 -> 3 -> 2 -> 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    // Check if the linked list is a palindrome
    cout << "Is Palindrome: " << boolalpha << isPalindrome(head) << endl;

    return 0;
}
