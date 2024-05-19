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
// Given a binary search tree (BST), find the in-order predecessor of a given node in the BST.

// Intuition:
// The in-order predecessor of a node in a BST is the node with the largest key smaller than the given node's key.
// We can find the in-order predecessor by traversing the BST either recursively or iteratively.

// DSA Strategy:
// This problem falls under the category of "Tree Traversal and Search".
// We will use both recursive and iterative approaches to find the in-order predecessor of a given node in a binary search tree (BST).

// Approach (Recursive):
// 1. If the root is NULL, return NULL.
// 2. If the value of the current node is greater than or equal to the value of the target node, search in the left subtree.
// 3. If the value of the current node is less than the value of the target node, search in the right subtree.
// 4. If the right subtree search returns NULL, the current node is the in-order predecessor.
// 5. Repeat steps 2-4 until the in-order predecessor is found.
// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(h) for the recursive approach on the call stack.

// Function to find the in-order predecessor of a given node in a BST (recursive approach)
TreeNode *inorderPredecessorRecursive(TreeNode *root, TreeNode *p)
{
    // If the root is NULL, return NULL
    if (root == NULL)
        return NULL;

    // If the value of the current node is greater than or equal to the value of the target node,
    // search in the left subtree
    if (root->val >= p->val)
        return inorderPredecessorRecursive(root->left, p);
    else
    {
        // If the value of the current node is less than the value of the target node,
        // search in the right subtree
        TreeNode *right = inorderPredecessorRecursive(root->right, p);
        // If the right subtree search returns NULL, the current node is the in-order predecessor
        return (right != NULL) ? right : root;
    }
}

// Approach (Iterative):
// 1. Initialize the predecessor node as NULL.
// 2. Traverse the tree until the current node is NULL.
// 3. If the value of the current node is less than the value of the target node, update the predecessor node and move to the right subtree.
// 4. If the value of the current node is greater than or equal to the value of the target node, move to the left subtree.
// 5. Repeat steps 2-4 until the in-order predecessor is found.

// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(1) for the iterative approach

// Function to find the in-order predecessor of a given node in a BST (iterative approach)
TreeNode *inorderPredecessorIterative(TreeNode *root, TreeNode *p)
{
    // Initialize the predecessor node as NULL
    TreeNode *predecessor = NULL;

    // Traverse the tree until the current node is NULL
    while (root != NULL)
    {
        // If the value of the current node is less than the value of the target node,
        // update the predecessor node and move to the right subtree
        if (root->val < p->val)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            // If the value of the current node is greater than or equal to the value of the target node,
            // move to the left subtree
            root = root->left;
        }
    }

    // Return the predecessor node
    return predecessor;
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

    // Find the in-order predecessor of a node
    TreeNode *p = root->left->right; // Node with value 3
    TreeNode *predecessor1 = inorderPredecessorRecursive(root, p);
    TreeNode *predecessor2 = inorderPredecessorIterative(root, p);

    // Print the in-order predecessor
    cout << "In-order predecessor (Recursive): " << predecessor1->val << endl;
    cout << "In-order predecessor (Iterative): " << predecessor2->val << endl;

    return 0;
}
