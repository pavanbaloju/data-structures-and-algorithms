#include <iostream>
#include <vector>
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
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// Intuition:
// A binary tree is a valid binary search tree if and only if the values of its nodes 
// satisfy the BST properties, which are:
// - The left subtree of a node contains only nodes with keys less than the node's key.
// - The right subtree of a node contains only nodes with keys greater than the node's key.
// - Both the left and right subtrees must also be binary search trees.

// DSA Strategy:
// Recursive approach

// Approach:
// 1. Implement a helper function isValid that recursively checks if a given subtree 
//    is a valid binary search tree.
//    a. The function takes three arguments: the root of the current subtree, the 
//       minimum value the root can take (atLeast), and the maximum value the root can 
//       take (atMost).
//    b. If the current root is nullptr, return true.
//    c. If atLeast is not nullptr and the value of the current root is less than or 
//       equal to the value of atLeast, return false.
//    d. If atMost is not nullptr and the value of the current root is greater than or 
//       equal to the value of atMost, return false.
//    e. Recursively call isValid for the left subtree with atMost set to the current 
//       root and atLeast unchanged, and for the right subtree with atLeast set to the 
//       current root and atMost unchanged.
// 2. Implement the isValidBST function that calls the isValid helper function with the 
//    root of the binary tree and nullptr for both the atLeast and atMost values.

// Time Complexity:
// The time complexity of the isValidBST function is O(n), where n is the number of 
// nodes in the binary tree, as each node is visited exactly once.

// Space Complexity:
// The space complexity of the isValidBST function is O(n), where n is the number of 
// nodes in the binary tree, due to the recursive calls and the space used by the 
// call stack.

// Function to check if a binary tree is a valid binary search tree
bool isValid(TreeNode *root, TreeNode *atLeast, TreeNode *atMost) {
    // Base case: if the current root is nullptr, return true
    if (!root)
        return true;

    // Check if the value of the current root is within the valid range
    if (atLeast && root->val <= atLeast->val)
        return false;
    if (atMost && root->val >= atMost->val)
        return false;

    // Recursively check the left and right subtrees
    return isValid(root->left, atLeast, root) && isValid(root->right, root, atMost);
}

// Function to determine if a binary tree is a valid binary search tree
bool isValidBST(TreeNode *root) {
    // Call the isValid helper function with the root of the binary tree
    // and nullptr for both atLeast and atMost values
    return isValid(root, nullptr, nullptr);
}

int main() {
    // Create a binary tree
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
