#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // Constructor to initialize a ListNode with a given value and next pointer.
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Add two numbers represented by linked lists.
 * 
 * @param l1 Pointer to the head of the first linked list.
 * @param l2 Pointer to the head of the second linked list.
 * @return Pointer to the head of the result linked list.
 * 
 * Intuition:
 * We iterate through both lists simultaneously, adding corresponding digits along with any carry from the previous sum.
 * If one list is longer than the other, we continue adding digits from the longer list along with the carry.
 * We create a dummy node to simplify handling of edge cases and return the next node after the dummy node as the head of the result list.
 * 
 * Approach:
 * - Initialize a dummy node and a pointer to the current node of the result list.
 * - Initialize a carry variable to store the carry from the previous sum.
 * - Iterate through both lists simultaneously until both lists and the carry are exhausted.
 * - Add the values of the current nodes along with the carry and update the carry accordingly.
 * - Create a new node with the value of the sum modulo 10 and append it to the result list.
 * - Update the current pointer to the next node.
 * - Return the next node after the dummy node as the head of the result list.
 * 
 * Time Complexity: O(max(m, n)), where m and n are the lengths of the input lists.
 *                  We iterate through both lists once.
 * Space Complexity: O(max(m, n)), where m and n are the lengths of the input lists.
 *                   We create a new node for each digit in the result list.
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0); // Dummy node to simplify handling of edge cases
    ListNode *curr = dummy; // Pointer to the current node of the result list
    int carry = 0; // Variable to store the carry from the previous sum

    // Iterate through both lists simultaneously until both lists and the carry are exhausted
    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        curr->next = new ListNode(carry % 10); // Create a new node with the value of the sum modulo 10
        carry = carry / 10; // Update the carry
        curr = curr->next; // Move to the next node in the result list
    }

    return dummy->next; // Return the next node after the dummy node as the head of the result list
}

int main() {
    // Create two linked lists representing numbers: 2 -> 4 -> 8 and 5 -> 6 -> 4
    ListNode *headA = new ListNode(2);
    headA->next = new ListNode(4);
    headA->next->next = new ListNode(8);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(4);

    // Add the numbers represented by the linked lists
    ListNode *res = addTwoNumbers(headA, headB);

    // Output the values of the original lists and the result list
    cout << "List A: ";
    while (headA) {
        cout << headA->val << " ";
        headA = headA->next;
    }
    cout << endl;

    cout << "List B: ";
    while (headB) {
        cout << headB->val << " ";
        headB = headB->next;
    }
    cout << endl;

    cout << "Result: ";
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
