#include <iostream>
#include <stack>
using namespace std;

// Problem Statement:
// Given a stack of integers, sort it in ascending order using another temporary stack.

// Intuition:
// Use a temporary stack to store elements in sorted order. For each element in the original stack,
// pop elements from the temporary stack and push them back to the original stack until finding the
// correct position for the current element. Then, push the current element to the temporary stack.

// DSA Strategy:
// Stack

// Approach:
// 1. Create a temporary stack to store elements in sorted order.
// 2. Iterate through each element in the original stack:
//    a. Store the top element of the original stack in a temporary variable and pop it.
//    b. Move elements from the temporary stack to the original stack until finding the correct
//       position for the top element.
//    c. Insert the top element at its correct position in the temporary stack.
// 3. Copy elements from the temporary stack back to the original stack.
// 4. The original stack is now sorted in ascending order.

// Time Complexity: O(n^2), where n is the number of elements in the stack.
// Space Complexity: O(n), where n is the number of elements in the stack (for the temporary stack).

void sortStack(stack<int> &s)
{
    stack<int> sortedStack;

    // Iterate through each element in the original stack
    while (!s.empty())
    {
        // Store the top element of the original stack
        int temp = s.top();
        s.pop();

        // Move elements from the sorted stack to the original stack
        // until finding the correct position for the top element
        while (!sortedStack.empty() && sortedStack.top() > temp)
        {
            s.push(sortedStack.top());
            sortedStack.pop();
        }

        // Insert the top element at its correct position in the sorted stack
        sortedStack.push(temp);
    }

    // Copy elements from the sorted stack back to the original stack
    while (!sortedStack.empty())
    {
        s.push(sortedStack.top());
        sortedStack.pop();
    }
}

// Main function
int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(2);

    cout << "Original stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Restore original stack elements
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(2);

    // Sort the stack
    sortStack(s);

    cout << "Sorted stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
