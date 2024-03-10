#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Problem Statement:
// Given the root of a Binary Search Tree (BST), and a target integer k, return true if there exist two elements
// in the BST such that their sum is equal to the given target.

// Intuition:
// We can use two iterators to simultaneously traverse the BST in ascending and descending order.
// We initialize one iterator for ascending order and another for descending order.
// Then, we iterate through both iterators simultaneously, comparing the sum of the current elements
// with the target value. If the sum is equal to the target, we return true.
// If the sum is less than the target, we move to the next element in the ascending order iterator.
// If the sum is greater than the target, we move to the next element in the descending order iterator.
// We continue this process until the two iterators meet or until no pair is found.

// DSA Strategy:
// This problem involves traversal and search in a Binary Search Tree.
// We implement two iterators to traverse the BST in ascending and descending order simultaneously.
// We use a stack-based iterative approach to implement the iterators.
// We then perform a two-pointer-like traversal of the iterators to find the pair of elements whose sum is equal to k.

// Time Complexity:
// Constructor for BSTIterator: O(h), where h is the height of the BST.
// next(): O(1) average case, O(h) worst case (amortized time complexity).
// hasNext(): O(1).
// findTarget(): O(n), where n is the number of nodes in the BST.


class BSTIterator
{
private:
    stack<TreeNode *> st; // Stack to store the nodes
    bool reverse;         // Flag to indicate if the iterator is in reverse mode

    // Helper function to push all left nodes of a given node onto the stack
    void pushAllLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);     // Push the node onto the stack
            node = node->left; // Move to the left child
        }
    }

    void pushAllRight(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);      // Push the node onto the stack
            node = node->right; // Move to the right child
        }
    }

public:
    // Constructor to initialize the iterator with the root of the BST
    BSTIterator(TreeNode *root, bool reverse = false)
    {
        this->reverse = reverse;
        if (reverse)
        {
            pushAllRight(root); // Push all right nodes onto the stack starting from the root
        }
        else
        {
            pushAllLeft(root); // Push all left nodes onto the stack starting from the root
        }
    }
    // Function to return the next smallest element in the BST
    int next()
    {
        TreeNode *node = st.top(); // Get the top node from the stack
        st.pop();                  // Pop the top node from the stack
        if (reverse)
        {
            pushAllRight(node->left); // Push all right nodes of the left child onto the stack
        }
        else
        {
            pushAllLeft(node->right); // Push all left nodes of the right child onto the stack
        }
        return node->val; // Return the value of the node
    }

    // Function to check if there are more elements in the BST
    bool hasNext()
    {
        return !st.empty(); // Return true if the stack is not empty, indicating there are more elements
    }
};

bool findTarget(TreeNode *root, int k)
{

    // Create two iterators, one for the ascending order and one for the descending order
    BSTIterator bstIterator1 = BSTIterator(root, false);
    BSTIterator bstIterator2 = BSTIterator(root, true);

    // Get the first and last elements from the ascending order iterator
    int first = bstIterator1.next();
    int last = bstIterator2.next();

    // Iterate until the two iterators meet
    while (first < last)
    {
        // If the sum of the current elements is equal to k, return true
        if (first + last == k)
        {
            return true;
        }
        // If the sum is less than k, move to the next element in the ascending order
        else if (first + last < k)
        {
            first = bstIterator1.next();
        }
        // If the sum is greater than k, move to the next element in the descending order
        else
        {
            last = bstIterator2.next();
        }
    }
    // If no pair is found, return false
    return false;
}

int main()
{
    // Example 1:
    // Construct the BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    // Find the kth largest element in the BST
    cout << findTarget(root, 9) << endl;  // return True
    cout << findTarget(root, 28) << endl; // return False
    return 0;
}