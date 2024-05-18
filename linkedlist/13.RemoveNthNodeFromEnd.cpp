#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head(nullptr) {}

    // Add a node of value val at the head of the list
    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Add a node of value val at the tail of the list
    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    /**
     * Intuition:
     * To remove the Nth node from the end of the list, we can use a two-pointer approach.
     * We use two pointers, slow and fast, initially pointing to the dummy node and the head of the list, respectively.
     * We move the fast pointer n steps ahead.
     * Then, we move both pointers until the fast pointer reaches the end of the list.
     * At this point, the slow pointer will be at the node just before the Nth node from the end.
     * We update the next pointer of the node pointed to by the slow pointer to skip the Nth node.
     * Finally, we return the head of the modified list.
     *
     * Approach:
     * - Create a dummy node and set its next pointer to the head of the list.
     * - Initialize slow and fast pointers to the dummy node and the head of the list, respectively.
     * - Move the fast pointer n steps ahead.
     * - Move both pointers until the fast pointer reaches the end of the list.
     * - Update the next pointer of the node pointed to by the slow pointer to skip the Nth node.
     * - Return the head of the modified list.
     *
     * Time Complexity: O(n), where n is the number of nodes in the list.
     * Space Complexity: O(1), constant space used.
     */

    // Remove the nth node from the end of the list
    void removeNthFromEnd(int n)
    {
        if (!head)
            return;

        ListNode *dummy = new ListNode(0); // Dummy node to handle the case where head needs to be removed
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // Move fast pointer n nodes ahead
        for (int i = 0; i <= n; ++i)
        {
            if (!fast)
            {
                // The list has fewer than n nodes
                delete dummy;
                return;
            }
            fast = fast->next;
        }

        // Move slow and fast pointers simultaneously until fast reaches the end
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from the end
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        head = dummy->next; // Update head after removal
        delete dummy;
    }

    // Print the linked list
    void printList()
    {
        ListNode *current = head;
        while (current)
        {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~SinglyLinkedList()
    {
        while (head)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    ListNode *head;
};

int main()
{
    SinglyLinkedList *linkedList = new SinglyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(2);
    linkedList->addAtTail(3);
    linkedList->addAtTail(4);
    linkedList->addAtTail(5);

    cout << "Original list: ";
    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    int n = 2;
    linkedList->removeNthFromEnd(n);

    cout << "List after removing " << n << "th node from end: ";
    linkedList->printList(); // Output: 1 -> 2 -> 3 -> 5 -> nullptr

    // Clean up
    delete linkedList;

    return 0;
}
