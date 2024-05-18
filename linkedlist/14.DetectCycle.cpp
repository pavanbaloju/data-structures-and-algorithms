#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    // Approach 1: Floyd's Tortoise and Hare algorithm

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
    ListNode *detectCycle1(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        // Initialize slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow and fast pointers until they meet
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        // If there is no cycle, return nullptr
        if (slow != fast)
            return nullptr;

        // Move slow to the head and continue moving slow and fast pointers
        // until they meet at the node where the cycle starts
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Return the node where the cycle starts
        return slow;
    }

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

    // Approach 2: Using Hash Map
    ListNode *detectCycle2(ListNode *head)
    {
        unordered_set<ListNode *> visited;

        while (head)
        {
            // If the current node is already visited, it means there is a cycle
            if (visited.find(head) != visited.end())
            {
                return head;
            }

            // Otherwise, mark the current node as visited
            visited.insert(head);
            head = head->next;
        }

        // If no cycle found, return nullptr
        return nullptr;
    }
};

int main()
{
    // Create a linked list with a cycle
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution solution;

    // Approach 1: Floyd's Tortoise and Hare algorithm
    ListNode *cycleStart1 = solution.detectCycle1(head);

    if (cycleStart1)
    {
        cout << "Cycle detected using Floyd's Tortoise and Hare algorithm! The cycle starts at node with value: " << cycleStart1->val << endl;
    }
    else
    {
        cout << "No cycle detected using Floyd's Tortoise and Hare algorithm." << endl;
    }

    // Approach 2: Using Hash Map
    ListNode *cycleStart2 = solution.detectCycle2(head);

    if (cycleStart2)
    {
        cout << "Cycle detected using Hash Map approach! The cycle starts at node with value: " << cycleStart2->val << endl;
    }
    else
    {
        cout << "No cycle detected using Hash Map approach." << endl;
    }

    // Clean up
    ListNode *current = head;
    while (current)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
