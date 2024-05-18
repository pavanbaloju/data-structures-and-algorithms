#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to check if a linked list is a palindrome using a stack
bool isPalindrome(ListNode *head)
{
    if (head == nullptr)
        return true; // An empty list is a palindrome

    stack<int> stk; // Stack to store the elements of the linked list

    // First traversal: Push all elements onto the stack
    ListNode *current = head;
    while (current != nullptr)
    {
        stk.push(current->val);  // Push the current element onto the stack
        current = current->next; // Move to the next node
    }

    // Second traversal: Compare elements with the elements popped from the stack
    current = head;
    while (current != nullptr)
    {
        int topVal = stk.top(); // Get the top element from the stack
        stk.pop();              // Pop the top element
        if (current->val != topVal)
        {
            return false; // If values do not match, it's not a palindrome
        }
        current = current->next; // Move to the next node
    }

    return true; // If all elements matched, it's a palindrome
}

// Main function to test the palindrome check
int main()
{
    ListNode *head = nullptr;

    // Creating a linked list: 1 -> 2 -> 2 -> 1
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Checking if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free allocated memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
