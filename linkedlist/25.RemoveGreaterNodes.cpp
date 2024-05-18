#include <iostream>
using namespace std;

// Node structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current)
    {
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// Function to remove nodes with greater values on their right side
ListNode *deleteNodes(ListNode *head)
{
    // If the list is empty or contains only one node, no modification is required
    if (!head)
        return nullptr;

    // Reverse the linked list to iterate from the end to the beginning
    head = reverseLinkedList(head);

    // Create a dummy node to handle edge cases
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    // Iterate through the reversed linked list
    ListNode *current = head;
    int maxVal = current->val; // Initialize the maximum value
    while (current->next)
    {
        if (current->next->val < maxVal)
        {
            // Remove the node if its value is less than the current maximum value
            ListNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            // Update the maximum value if needed
            maxVal = current->next->val;
            current = current->next;
        }
    }

    // Reverse the modified linked list back to its original order
    head = reverseLinkedList(dummy->next);

    // Delete the dummy node
    delete dummy;

    // Return the head of the modified linked list
    return head;
}

// Utility function to print linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = deleteNodes(head);

    cout << "Modified Linked List: ";
    printLinkedList(head);

    return 0;
}
