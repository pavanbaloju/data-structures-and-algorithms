#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    Node *next, *random;

    Node(int x)
    {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

/**
 * Function to copy a linked list with random pointers (using hashmap).
 * 
 * @param head Pointer to the head of the original linked list.
 * @return Pointer to the head of the copied linked list.
 * 
 * Intuition:
 * To copy a linked list with random pointers using a hashmap, we follow these steps:
 * 1. Traverse the original list and create a hashmap that maps original nodes to their corresponding copied nodes.
 * 2. While traversing, create a new node for each original node and store it in the hashmap.
 * 3. After creating all nodes, update the next and random pointers of each copied node using the hashmap.
 * 4. Return the head of the copied list.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(n), where n is the number of nodes in the linked list (used by the hashmap).
 */
Node *copyRandomListHashing(Node *head)
{
    unordered_map<Node*, Node*> map;
    Node *temp = head;

    // Step 1: Create a hashmap to map original nodes to their corresponding copied nodes
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        map[temp] = newNode;
        temp = temp->next;
    }
    map[nullptr] = nullptr;
    temp = head;

    // Step 2: Update next and random pointers of copied nodes using the hashmap
    while (temp)
    {
        // Get the copied node corresponding to the current original node
        Node *copy = map[temp];
        
        // Update next pointer of copied node to point to the copied node corresponding to the next original node
        copy->next = map[temp->next];
        
        // Update random pointer of copied node to point to the copied node corresponding to the random original node
        copy->random = map[temp->random];
        
        // Move to the next original node
        temp = temp->next;
    }

    // Step 3: Return the head of the copied list
    return map[head];
}

/**
 * Function to copy a linked list with random pointers (without extra space).
 * 
 * @param head Pointer to the head of the original linked list.
 * @return Pointer to the head of the copied linked list.
 * 
 * Intuition:
 * To copy a linked list with random pointers without using extra space, we follow these steps:
 * 1. Duplicate each node of the original list and insert it next to its original node.
 * 2. Update the random pointers of the duplicated nodes based on the original list's random pointers.
 * 3. Separate the original list and the copied list by rearranging the next pointers.
 * 4. Return the head of the copied list.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the linked list.
 * Space Complexity: O(1), constant space used.
 */
Node *copyRandomList(Node *head)
{
    // Step 1: Duplicate each node and insert it next to its original node
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        Node *nxt = temp->next;
        newNode->next = nxt;
        temp->next = newNode;
        temp = nxt;
    }

    // Step 2: Update random pointers of duplicated nodes
    temp = head;
    while (temp)
    {
        // Update random pointer of duplicated node to point to the node corresponding to the random original node
        temp->next->random = temp->random ? temp->random->next : nullptr;
        
        // Move to the next original node
        temp = temp->next->next;
    }

    // Step 3: Separate the original list and the copied list
    Node *dummy = new Node(0), *copy = dummy;
    temp = head;
    while (temp)
    {
        // Get the next node after the duplicated node
        Node *nxt = temp->next->next;
        
        // Append the duplicated node to the copied list
        copy->next = temp->next;
        copy = copy->next;

        // Restore the original next pointer of the original node
        temp->next = nxt;
        
        // Move to the next original node
        temp = temp->next;
    }

    // Step 4: Return the head of the copied list
    return dummy->next;
}

int main()
{
    // Create a linked list with values 2 -> 4 -> 8
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->random = head;
    head->next->next = new Node(8);
    head->next->next->random = head->next;

    // Copy the linked list with random pointers
    Node *res = copyRandomList(head);

    // Output the comparison result of the original and copied lists
    while (res && head)
    {
        cout << (res == head) << " ";
        res = res->next;
        head = head->next;
    }
    cout << endl;

    // Output the values and random pointers of the copied list
    while (res )
    {
        cout << res->val << "&" << (res->random ? res->random->val: 0)<<" ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
