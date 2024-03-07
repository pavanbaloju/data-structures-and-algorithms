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
// Given the root of a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Intuition:
// The maximum depth of a binary tree can be found recursively by computing the maximum depth of its left and right subtrees.
// The maximum depth of a subtree is the maximum depth of its left and right subtrees plus one (to account for the current node).
// We can use a recursive approach to traverse the tree and find the maximum depth.

// DSA Strategy:
// We use a recursive approach to traverse the binary tree.
// At each node, we compute the maximum depth of its left and right subtrees recursively.
// The maximum depth of the current node is the maximum of the depths of its left and right subtrees plus one.

// Approach:
// 1. If the root is NULL, return 0 (base case).
// 2. Recursively find the maximum depth of the left subtree.
// 3. Recursively find the maximum depth of the right subtree.
// 4. Return the maximum of the depths of the left and right subtrees plus one.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive stack space).

// Function to find the maximum depth of a binary tree
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;                           // If the root is NULL, the depth is 0
    int leftDepth = maxDepth(root->left);   // Recursively find the depth of the left subtree
    int rightDepth = maxDepth(root->right); // Recursively find the depth of the right subtree
    return max(leftDepth, rightDepth) + 1;  // Return the maximum depth of the left and right subtrees + 1
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
    // The maximum depth of the tree is 3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Maximum depth of the tree: " << maxDepth(root) << endl; // Output: 3

    return 0;
}