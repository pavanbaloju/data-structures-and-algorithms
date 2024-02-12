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
 * Detects whether a linked list has a cycle using a hashmap.
 * 
 * @param head Pointer to the head of the linked list.
 * @return True if there is a cycle in the linked list, false otherwise.
 * 
 * Intuition:
 * One approach to detect a cycle in a linked list is to use a hashmap to store visited nodes.
 * We traverse the linked list and for each node, we check if it has been visited before.
 * If a node has been visited, it means there is a cycle, and we return true.
 * If we reach the end of the list without finding a cycle, we return false.
 * 
 * Approach:
 * - Initialize a hashmap to store visited nodes.
 * - Traverse the linked list.
 * - For each node, check if it has been visited before:
 *    - If yes, return true (cycle detected).
 *    - If no, mark the node as visited and move to the next node.
 * - If we reach the end of the list without finding a cycle, return false.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the list.
 * Space Complexity: O(n), where n is the number of nodes in the list (used by the hashmap).
 */
bool hasCycle(ListNode *head)
{
    unordered_set<ListNode *> visited;
    ListNode *current = head;
    while (current != nullptr)
    {
        // If the current node has been visited before, return true (cycle detected)
        if (visited.find(current) != visited.end())
            return true;
        // Mark the current node as visited
        visited.insert(current);
        // Move to the next node
        current = current->next;
    }
    // If we reach the end of the list without finding a cycle, return false
    return false;
}

int main()
{
    // Create a linked list with a cycle: 3 -> 2 -> 0 -> 4 -> 2 (cycle starts at node with value 2)
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;

    // Check if the linked list has a cycle
    bool cycleExists = hasCycle(head);
    if (cycleExists)
        cout << "Cycle exists in the linked list." << endl;
    else
        cout << "No cycle found in the linked list." << endl;

    return 0;
}
