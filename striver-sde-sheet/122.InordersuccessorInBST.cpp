#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Problem Statement:
// Given a binary search tree (BST), find the in-order successor of a given node in the BST.

// Intuition:
// The in-order successor of a node in a BST is the node with the smallest key greater than the given node's key.
// We can find the in-order successor by traversing the BST either recursively or iteratively.

// DSA Strategy:
// This problem falls under the category of "Tree Traversal and Search".
// We will use both recursive and iterative approaches to find the in-order successor of a given node in a binary search tree (BST).

// Approach (Recursive):
// 1. If the root is NULL, return NULL.
// 2. If the value of the current node is less than or equal to the value of the target node, search in the right subtree.
// 3. If the value of the current node is greater than the value of the target node, search in the left subtree.
// 4. If the left subtree search returns NULL, the current node is the in-order successor.
// 5. Repeat steps 2-4 until the in-order successor is found.
// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(h) for the recursive approach on the call stack.

// Function to find the in-order successor of a given node in a BST (recursive approach)
TreeNode *inorderSuccessorRecursive(TreeNode *root, TreeNode *p)
{
    // If the root is NULL, return NULL
    if (root == NULL)
        return NULL;

    // If the value of the current node is less than or equal to the value of the target node,
    // search in the right subtree
    if (root->val <= p->val)
        return inorderSuccessorRecursive(root->right, p);
    else
    {
        // If the value of the current node is greater than the value of the target node,
        // search in the left subtree
        TreeNode *left = inorderSuccessorRecursive(root->left, p);
        // If the left subtree search returns NULL, the current node is the in-order successor
        return (left != NULL) ? left : root;
    }
}
// Approach (Iterative):
// 1. Initialize the successor node as NULL.
// 2. Traverse the tree until the current node is NULL.
// 3. If the value of the current node is greater than the value of the target node, update the successor node and move to the left subtree.
// 4. If the value of the current node is less than or equal to the value of the target node, move to the right subtree.
// 5. Repeat steps 2-4 until the in-order successor is found.

// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(1) for the iterative approach

// Function to find the in-order successor of a given node in a BST (iterative approach)
TreeNode *inorderSuccessorIterative(TreeNode *root, TreeNode *p)
{
    // Initialize the successor node as NULL
    TreeNode *successor = NULL;

    // Traverse the tree until the current node is NULL
    while (root != NULL)
    {
        // If the value of the current node is greater than the value of the target node,
        // update the successor node and move to the left subtree
        if (root->val > p->val)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            // If the value of the current node is less than or equal to the value of the target node,
            // move to the right subtree
            root = root->right;
        }
    }

    // Return the successor node
    return successor;
}

int main()
{
    // Create a BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // Find the in-order successor of a node
    TreeNode *p = root->left->right; // Node with value 3
    TreeNode *successor1 = inorderSuccessorRecursive(root, p);
    TreeNode *successor2 = inorderSuccessorIterative(root, p);

    // Print the in-order successor
    cout << "In-order successor (Recursive): " << successor1->val << endl;
    cout << "In-order successor (Iterative): " << successor2->val << endl;

    return 0;
}
