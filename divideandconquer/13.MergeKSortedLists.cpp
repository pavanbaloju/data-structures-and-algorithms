#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem Statement:
// Given k sorted linked lists, merge them into one sorted linked list.

// Intuition:
// The problem can be solved by merging the lists in pairs until there's only one list left.
// This is a Divide and Conquer strategy where we repeatedly divide the problem into subproblems of smaller size.

// DSA Strategy/Pattern: Divide and Conquer

// Approach:
// 1. Divide the problem into smaller subproblems by recursively partitioning the list of lists.
// 2. Merge two lists at a time using the merge function, which merges two sorted linked lists into one.
// 3. Repeat this process until there's only one list left.

// Time Complexity: O(n log k), where n is the total number of nodes across all lists and k is the number of lists.
//   - Each merge operation takes O(n) time, and there are log k levels of recursion.
// Space Complexity: O(log k) due to the recursive call stack.

// Definition of a ListNode
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to merge two sorted linked lists
ListNode *merge(ListNode *l1, ListNode *l2)
{
    // Base cases: if either list is empty, return the other list
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    // Compare the values of the heads of both lists
    if (l1->val < l2->val)
    {
        // If l1's value is smaller, merge l1's next with l2
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        // If l2's value is smaller (or equal), merge l2's next with l1
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to divide the lists into halves and merge them
ListNode *partition(vector<ListNode *> lists, int start, int end)
{
    // Base case: when there's only one list
    if (start == end)
        return lists[start];

    // Divide the range into two halves
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        // Recursively partition the left and right halves
        ListNode *l1 = partition(lists, start, mid);
        ListNode *l2 = partition(lists, mid + 1, end);

        // Merge the two lists
        return merge(l1, l2);
    }
    else
        return nullptr;
}

// Function to merge k sorted linked lists
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    // Call the partition function to merge all lists
    return partition(lists, 0, lists.size() - 1);
}

int main()
{
    // Create sample linked lists
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(5);

    ListNode *headB = new ListNode(7);
    headB->next = new ListNode(8);
    headB->next->next = new ListNode(9);

    ListNode *headC = new ListNode(10);
    headC->next = new ListNode(13);
    headC->next->next = new ListNode(24);

    // Store the lists in a vector
    vector<ListNode *> lists = vector<ListNode *>({headA, headB, headC});

    // Merge the lists
    ListNode *res = mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
