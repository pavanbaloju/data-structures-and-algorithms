#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode structure representing a node in the binary tree
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
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// 1. The left subtree of a node contains only nodes with keys less than the node's key.
// 2. The right subtree of a node contains only nodes with keys greater than the node's key.
// 3. Both the left and right subtrees must also be binary search trees.

// Intuition:
// To check if a binary tree is a valid binary search tree (BST), we can perform an inorder traversal and verify if the elements are in ascending order.
// If the inorder traversal results in a sorted sequence, the tree is a valid BST.

// DSA Strategy:
// Binary search tree property

// Approach:
// We will define a helper function isValid that recursively checks if a node's value is within the specified range.
// We will initialize the range limits as negative and positive infinity, respectively.
// We will call this helper function with the root node to validate the entire binary tree.
// If the tree is a valid BST, the function will return true; otherwise, it will return false.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n) on the recursive call stack.

// Function to check if a binary tree is a valid binary search tree
bool isValid(TreeNode *root, long atLeast, long atMost)
{
    // If the root is null, return true
    if (!root)
        return true;

    // If the value of the root node is not within the specified range, return false
    if (root->val <= atLeast || root->val >= atMost)
        return false;

    // Recursively check the left and right subtrees with updated range limits
    return isValid(root->left, atLeast, root->val) && isValid(root->right, root->val, atMost);
}

// Function to check if a binary tree is a valid binary search tree
bool isValidBST(TreeNode *root)
{
    // Call the helper function with initial range limits
    return isValid(root, LONG_MIN, LONG_MAX);
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Check if the binary tree is a valid binary search tree
    cout << isValidBST(root);

    return 0;
}
