#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Detects the start of a cycle in a linked list using a hashmap.
 *
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the node where the cycle begins, or nullptr if there is no cycle.
 *
 * Intuition:
 * Another approach to detect a cycle in a linked list is to use a hashmap to store visited nodes.
 * We traverse the linked list and for each node, we check if it has been visited before.
 * If a node has been visited, it means there is a cycle, and we return the node where the cycle begins.
 *
 * Approach:
 * - Initialize a hashmap to store visited nodes.
 * - Traverse the linked list.
 * - For each node, check if it has been visited before:
 *    - If yes, return the node where the cycle begins.
 *    - If no, mark the node as visited and move to the next node.
 * - If no cycle is found, return nullptr.
 *
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(n), where n is the number of nodes in the list (used by the hashmap).
 */
ListNode *detectCycleHash(ListNode *head)
{
    unordered_set<ListNode *> visited;
    ListNode *current = head;
    while (current != nullptr)
    {
        // If the current node has been visited before, return it (start of the cycle)
        if (visited.find(current) != visited.end())
            return current;
        // Mark the current node as visited
        visited.insert(current);
        // Move to the next node
        current = current->next;
    }
    // If no cycle is found, return nullptr
    return nullptr;
}

/**
 * Detects the start of a cycle in a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the node where the cycle begins, or nullptr if there is no cycle.
 *
 * Intuition:
 * To detect the start of a cycle in a linked list, we use the Floyd's Tortoise and Hare algorithm.
 * We use two pointers, slow and fast, initialized to the head of the list.
 * The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
 * If there is a cycle, the two pointers will eventually meet.
 * Once they meet, we reset the slow pointer to the head of the list and move both pointers at the same pace.
 * The point at which they meet again is the start of the cycle.
 *
 * Approach:
 * - Initialize slow and fast pointers to the head of the list.
 * - Move the slow pointer one step and the fast pointer two steps at a time.
 * - If they meet, reset the slow pointer to the head of the list and move both pointers at the same pace until they meet again.
 * - Return the node where they meet (the start of the cycle).
 * - If there is no cycle, return nullptr.
 *
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(1)
 */
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        // Move slow pointer one step
        slow = slow->next;
        // Move fast pointer two steps
        fast = fast->next->next;
        // If slow and fast pointers meet, there is a cycle
        if (slow == fast)
        {
            // Reset slow pointer to head
            slow = head;
            // Move slow and fast pointers at the same pace until they meet again
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            // Return the node where they meet (start of the cycle)
            return slow;
        }
    }
    // If no cycle is found, return nullptr
    return nullptr;
}

int main()
{
    // Create a linked list with a cycle: 3 -> 2 -> 0 -> 4 -> 2 (cycle starts at node with value 2)
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;

    // Find and output the start of the cycle
    ListNode *cycleStart = detectCycle(head);
    cout << "Cycle starts at node with value " << cycleStart->val << endl;

    cycleStart = detectCycleHash(head);
    cout << "Cycle starts at node with value (Hashing) " << cycleStart->val << endl;

    return 0;
}
