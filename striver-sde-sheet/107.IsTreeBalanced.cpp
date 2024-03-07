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
// Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than 1.

// Intuition:
// We can recursively check if each node of the binary tree is balanced by calculating the height of its left and right subtrees.
// If the difference in heights of the left and right subtrees of a node is greater than 1, the tree is not balanced.
// We can use a helper function to compute the height of each node's subtree and check if the tree is balanced.

// DSA Strategy:
// We use a recursive approach to traverse the binary tree.
// At each node, we compute the height of its left and right subtrees recursively.
// We check if the tree is balanced by comparing the heights of the left and right subtrees.
// If the difference in heights is greater than 1, the tree is not balanced.

// Approach:
// 1. Base Case: If the root is NULL, return true and set the height to 0.
// 2. Recursively check if the left subtree is balanced, and compute its height.
// 3. Recursively check if the right subtree is balanced, and compute its height.
// 4. Update the height of the current node as the maximum of the heights of its left and right subtrees plus 1.
// 5. Check if the difference in heights of the left and right subtrees is less than or equal to 1.
// 6. Return true if the tree is balanced, false otherwise.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive stack space).

// Function to check if a binary tree is balanced
bool isBalanced(TreeNode *root, int &height)
{
    if (root == NULL)
    {
        height = 0;  // If the root is NULL, the height is 0
        return true; // An empty tree is balanced
    }

    int leftHeight, rightHeight;

    bool leftBalanced = isBalanced(root->left, leftHeight); // Recursively check if the left subtree is balanced
    if (!leftBalanced)
        return false; // If the left subtree is not balanced, the current node is not balanced

    bool rightBalanced = isBalanced(root->right, rightHeight); // Recursively check if the right subtree is balanced
    if (!rightBalanced)
        return false; // If the right subtree is not balanced, the current node is not balanced

    height = max(leftHeight, rightHeight) + 1; // Update the height of the current node

    return abs(leftHeight - rightHeight) <= 1; // Check if the current node is balanced
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
    // The tree is balanced
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height;
    bool balanced = isBalanced(root, height); // Check if the tree is balanced
    cout << "The tree is " << (balanced ? "balanced" : "not balanced") << endl;

    return 0;
}