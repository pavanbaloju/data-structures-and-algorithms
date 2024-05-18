#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Finds the intersection node of two singly-linked lists using brute force.
 *
 * @param headA Pointer to the head of the first linked list.
 * @param headB Pointer to the head of the second linked list.
 * @return Pointer to the intersection node, or nullptr if there is no intersection.
 *
 * Intuition:
 * To find the intersection node of two linked lists using brute force, we traverse each node in one list and check if it appears in the other list.
 * If we find a node that appears in both lists, it is the intersection node.
 *
 * Approach:
 * - Traverse each node in list A and for each node, traverse each node in list B to check for intersection.
 * - If an intersection is found, return the intersecting node; otherwise, return nullptr.
 *
 * Time Complexity: O(m * n), where m and n are the lengths of the two lists.
 *                  In the worst case, we traverse each node of list A and for each node, we traverse each node of list B.
 * Space Complexity: O(1)
 */
ListNode *getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA, *tempB;
    while (tempA)
    {
        tempB = headB;
        while (tempB)
        {
            if (tempA == tempB)
                return tempA;
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
    return nullptr;
}

/**
 * Finds the intersection node of two singly-linked lists using a hash set.
 *
 * @param headA Pointer to the head of the first linked list.
 * @param headB Pointer to the head of the second linked list.
 * @return Pointer to the intersection node, or nullptr if there is no intersection.
 *
 * Intuition:
 * To find the intersection node of two linked lists using a hash set, we store the addresses of all nodes of one list in a hash set.
 * Then, we traverse the other list and check if any node's address is present in the hash set.
 * If an intersection is found, it is the intersection node.
 *
 * Approach:
 * - Create a hash set to store the addresses of nodes in list A.
 * - Traverse list A and store the address of each node in the hash set.
 * - Traverse list B and check if any node's address is present in the hash set.
 *   - If an intersection is found, return the intersecting node; otherwise, return nullptr.
 *
 * Time Complexity: O(m + n), where m and n are the lengths of the two lists.
 *                   We traverse each list once, and hash set lookup is O(1) on average.
 * Space Complexity: O(m), where m is the length of list A.
 */
ListNode *getIntersectionNodeHashMap(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> addressSet;
    ListNode *tempA = headA;
    while (tempA)
    {
        addressSet.insert(tempA);
        tempA = tempA->next;
    }

    ListNode *tempB = headB;
    while (tempB)
    {
        if (addressSet.find(tempB) != addressSet.end())
            return tempB;
        tempB = tempB->next;
    }

    return nullptr;
}

/**
 * Finds the intersection node of two singly-linked lists.
 *
 * @param headA Pointer to the head of the first linked list.
 * @param headB Pointer to the head of the second linked list.
 * @return Pointer to the intersection node, or nullptr if there is no intersection.
 *
 * Intuition:
 * To find the intersection node of two linked lists, we can traverse both lists simultaneously.
 * If one list reaches the end, we continue from the head of the other list.
 * By doing this, we ensure that both lists travel the same distance before reaching the intersection node.
 *
 * Approach:
 * - Initialize two pointers, tempA and tempB, to the heads of the two lists.
 * - While tempA is not equal to tempB:
 *   - If tempA reaches the end of list A, move it to the head of list B; otherwise, move it to the next node.
 *   - If tempB reaches the end of list B, move it to the head of list A; otherwise, move it to the next node.
 * - Return tempA, which points to the intersection node, or nullptr if there is no intersection.
 *
 * Time Complexity: O(m + n), where m and n are the lengths of the two lists.
 * Space Complexity: O(1)
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA, *tempB = headB;
    while (tempA != tempB)
    {
        tempA = tempA ? tempA->next : headB;
        tempB = tempB ? tempB->next : headA;
    }
    return tempA;
}

int main()
{
    // Create the first linked list: 4 -> 1 -> 8 -> 4 -> 5
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // Create the second linked list: 5 -> 6 -> 1 -> 8 -> 4 -> 5 (intersection at node with value 8)
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    // Find and output the intersection node
    cout << "Intersection Node Value: " << getIntersectionNode(headA, headB)->val << endl;

    // Find and output the intersection node using brute force
    cout << "Brute Force: ";
    ListNode *intersectionNode = getIntersectionNodeBruteForce(headA, headB);
    cout << intersectionNode->val << endl;

    // Find and output the intersection node using hash set
    cout << "Hash Set: ";
    intersectionNode = getIntersectionNodeHashMap(headA, headB);
    cout << intersectionNode->val << endl;

    // Output the values of the modified linked lists
    ListNode *current = headB;
    cout << "Linked List B: ";
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    current = headA;
    cout << "Linked List A: ";
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
