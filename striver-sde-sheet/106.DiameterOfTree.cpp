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
// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.

// Intuition:
// The diameter of a binary tree can be computed recursively by finding the maximum depth of each node's left and right subtrees.
// The diameter of the tree is the maximum of the sum of the depths of the left and right subtrees of each node.
// We can use a helper function to recursively compute the maximum depth of each node's subtree and update the diameter accordingly.

// DSA Strategy:
// We use a recursive approach to traverse the binary tree.
// At each node, we compute the maximum depth of its left and right subtrees recursively.
// We update the diameter by considering the sum of the depths of the left and right subtrees of each node.

// Approach:
// 1. Initialize the diameter to 0.
// 2. Recursively compute the maximum depth of each node's left and right subtrees using a helper function.
// 3. Update the diameter by considering the sum of the depths of the left and right subtrees of each node.
// 4. Return the computed diameter.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive stack space).

// Helper function to compute the diameter of a binary tree
int maxDepth(TreeNode *root, int &diameter)
{
    if (root == NULL)
        return 0;                                     // If the root is NULL, the depth is 0
    int leftDepth = maxDepth(root->left, diameter);   // Recursively find the depth of the left subtree
    int rightDepth = maxDepth(root->right, diameter); // Recursively find the depth of the right subtree
    diameter = max(diameter, leftDepth + rightDepth); // Update the diameter if necessary
    return max(leftDepth, rightDepth) + 1;            // Return the maximum depth of the left and right subtrees + 1
}

// Function to find the diameter of a binary tree
int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;         // Initialize the diameter to 0
    maxDepth(root, diameter); // Call the helper function to compute the diameter
    return diameter;          // Return the diameter of the binary tree
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
    // The diameter of the tree is 3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl; // Output: 3
    return 0;
}
