#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Problem Statement:
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// The lowest common ancestor is the lowest node in the tree that has both nodes as descendants.

// Intuition:
// We can recursively search for the given nodes in the left and right subtrees of each node.
// If both nodes are found in different subtrees of a node, then that node is the lowest common ancestor.
// Otherwise, the lowest common ancestor is found in the subtree where both nodes are present.

// DSA Strategy:
// We use a recursive approach to traverse the binary tree.
// At each node, we check if the node is one of the given nodes or if the given nodes are present in its left or right subtrees.
// If both nodes are present in different subtrees of a node, then that node is the lowest common ancestor.
// Otherwise, we continue searching in the subtree where both nodes are present.

// Approach:
// 1. Base Case: If the root is NULL, return NULL.
// 2. If the root is one of the given nodes (p or q), return the root.
// 3. Recursively search for the given nodes in the left and right subtrees.
// 4. If both nodes are found in different subtrees, return the current root as the lowest common ancestor.
// 5. If one of the nodes is found, return it; otherwise, return NULL.
// 6. If both nodes are found in the same subtree, return that subtree's lowest common ancestor.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive stack space).

// Function to find the lowest common ancestor of two nodes in a binary tree
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL; // If the root is NULL, return NULL

    if (root == p || root == q)
        return root; // If the root is one of the nodes, return the root

    TreeNode *left = lowestCommonAncestor(root->left, p, q);   // Recursively find the lowest common ancestor in the left subtree
    TreeNode *right = lowestCommonAncestor(root->right, p, q); // Recursively find the lowest common ancestor in the right subtree

    if (left != NULL && right != NULL)
        return root; // If the nodes are present in both the left and right subtrees, the current node is the lowest common ancestor

    return left != NULL ? left : right; // If one of the nodes is present in the left subtree, return the lowest common ancestor from the left subtree; otherwise, return the lowest common ancestor from the right subtree
}

int main()
{
    // Example:
    // Construct the following binary tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // The lowest common ancestor of nodes 4 and 5 is node 2
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *p = root->left->left;
    TreeNode *q = root->left->right;

    cout << lowestCommonAncestor(root, p, q)->val;

    return 0;
}

