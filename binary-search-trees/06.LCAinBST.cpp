#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Problem Statement:
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
// The lowest common ancestor is defined between two nodes p and q as the lowest node in the BST that has both p and q as descendants.

// Intuition:
// The LCA of two nodes in a BST is the node at which the paths to the two nodes diverge.
// We can start traversing the BST from the root and move left or right based on the values of the nodes until we find a node whose value lies between the values of the two given nodes.

// DSA Strategy:
// This problem falls under the category of "Tree Traversal and Search".
// We will use a recursive approach to find the lowest common ancestor (LCA) of two nodes in a binary search tree (BST).
// 1. Start from the root of the BST.
// 2. If both nodes are smaller than the current node, move to the left subtree.
// 3. If both nodes are greater than the current node, move to the right subtree.
// 4. If one node is smaller and the other is greater than the current node, return the current node as the LCA.
// 5. Repeat steps 2-4 until the LCA is found.

// Approach:
// We will define a function lowestCommonAncestor that recursively searches for the LCA of two given nodes in the BST.
// The function will take three parameters: the current node, and the two nodes whose LCA needs to be found.
// We will traverse the BST recursively based on the values of the two nodes, moving left or right until the LCA is found.

// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(h) on the recursive call stack.

// Function to find the LCA in a BST
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // If any of the nodes is null, return null
    if (root == nullptr || p == nullptr || q == nullptr)
    {
        return nullptr;
    }

    // If both nodes are smaller than the current node, go to the left subtree
    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    // If both nodes are greater than the current node, go to the right subtree
    if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    // If one node is smaller and the other is greater than the current node, return the current node
    return root;
}

int main()
{
    // Create a sample BST
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Find the LCA of two nodes
    TreeNode *p = root->left;
    TreeNode *q = root->right;
    TreeNode *lca = lowestCommonAncestor(root, p, q);

    // Print the value of the LCA
    if (lca != nullptr)
    {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    }
    else
    {
        std::cout << "No Lowest Common Ancestor found." << std::endl;
    }

    // Clean up memory
    // TODO: Implement a function to delete the tree nodes

    return 0;
}
