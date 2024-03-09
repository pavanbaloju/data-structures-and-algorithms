#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition of TreeNode structure representing a node in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Problem Statement:
// Given a binary tree, determine if it is symmetric around its center.

// Intuition:
// To check if a binary tree is symmetric, we can recursively compare the left and right subtrees.
// Two trees are symmetric if their roots have the same value, and the right subtree of the left tree is the mirror image of the left subtree of the right tree.

// DSA Strategy:
// We will use a recursive approach to check if the given binary tree is symmetric.
// We will define a helper function to check if the children of two nodes are symmetric.
// Then, we will use this helper function to check the symmetry of the root's left and right subtrees.

// Approach:
// Recursive approach to check if a binary tree is symmetric.
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
//   - We traverse each node once.
// Space Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The space complexity arises due to the recursive calls on the stack.

// Function to check if the children of two nodes are symmetric
bool AreChildrenSymmetric(TreeNode *left, TreeNode *right)
{
    // Base case: if both nodes are null, they are symmetric
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    // If one of the nodes is null but not both, they are not symmetric
    if (left == nullptr || right == nullptr)
    {
        return false;
    }
    // If values of the nodes are different, they are not symmetric
    if (left->val != right->val)
    {
        return false;
    }
    // Recursively check the symmetry of left and right children
    return AreChildrenSymmetric(left->left, right->right) && AreChildrenSymmetric(left->right, right->left);
}

// Function to check if the binary tree is symmetric
bool isSymmetric(TreeNode *root)
{
    // If the tree is empty, it is symmetric
    if (root == nullptr)
        return true;

    // Check if the children of the root are symmetric
    return AreChildrenSymmetric(root->left, root->right);
}

int main()
{
    // Example 1:
    // Construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    // Output: true
    cout << (isSymmetric(root) ? "true" : "false") << endl;

    // Example 2:
    // Construct the binary tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    // Output: false
    cout << (isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}
