#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *prev, *next, *child;

    Node(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

/**
 * Function to flatten a multilevel doubly linked list.
 * 
 * @param head Pointer to the head of the multilevel doubly linked list.
 * @return Pointer to the head of the flattened doubly linked list.
 * 
 * Intuition:
 * To flatten a multilevel doubly linked list, we can follow these steps:
 * 1. Traverse the list using a pointer.
 * 2. If a node has a child, flatten the child sublist and append it after the current node.
 * 3. Repeat the process until all nodes are flattened.
 * 
 * Approach:
 * - Traverse the list using a pointer.
 * - If a node has a child, flatten the child sublist:
 *     - Store the next pointer of the current node.
 *     - Set the next pointer of the current node to the child sublist.
 *     - Set the prev pointer of the child sublist's head to the current node.
 *     - Traverse to the end of the child sublist and connect it with the stored next pointer.
 * - Repeat the process until all nodes are flattened.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the multilevel doubly linked list.
 * Space Complexity: O(1), constant space used.
 */
Node *flatten(Node *head)
{
    if (!head || (!head->child && !head->next))
    {
        return head;
    }
    
    // Traverse the list
    Node *temp = head;
    while (temp)
    {
        // If a node has a child, flatten the child sublist
        if (temp->child)
        {
            // Store the next pointer of the current node
            Node *nxt = temp->next;
            // Set the next pointer of the current node to the child sublist
            temp->child->prev = temp;
            temp->next = temp->child;

            // Traverse to the end of the child sublist
            Node *child = temp->child;
            while (child->next)
                child = child->next;

            // Connect the end of the child sublist with the stored next pointer
            if (nxt)
            {
                child->next = nxt;
                nxt->prev = child;
            }

            // Set the child pointer of the current node to nullptr
            temp->child = nullptr;
        }
        // Move to the next node
        temp = temp->next;
    }
    return head;
}

int main()
{
    // Create a multilevel doubly linked list
    Node *headA = new Node(2);
    headA->next = new Node(4);
    headA->next->prev = headA;
    headA->next->child = new Node(8);
    headA->next->next = new Node(6);
    headA->next->next->prev = headA->next;
    headA->next->next->next = new Node(9);
    headA->next->next->next->prev = headA->next->next;

    // Flatten the multilevel doubly linked list
    Node *res = flatten(headA);

    // Print the flattened doubly linked list
    cout << endl;
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
