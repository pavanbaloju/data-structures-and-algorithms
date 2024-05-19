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
// Given a binary search tree (BST) and a target value, find the ceil value of the target value in the BST.
// The ceil value of a node is the smallest value in the BST that is greater than or equal to the target value.

// Intuition:
// In a BST, to find the ceil of a given value:
// 1. If the current node's value is equal to the target value, return the target value.
// 2. If the current node's value is greater than the target value, update the ceil value and move to the left subtree.
// 3. If the current node's value is less than the target value, move to the right subtree.

// DSA Strategy:
// This problem falls under the category of "Tree Traversal and Search".
// We can solve this problem using an iterative approach to traverse the BST.
// We start from the root node and traverse down the tree while updating the ceil value based on the conditions mentioned above.

// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(1) for the iterative approach.

// Function to find the ceil of a given value in a BST
int ceilInBST(TreeNode *root, int key)
{
    // Initialize the ceil value as -1
    int ceil = -1;

    // Traverse the BST
    while (root)
    {
        // If the current node's value is equal to the key, return the key
        if (root->val == key)
        {
            return key;
        }
        // If the current node's value is greater than the key, update the ceil value and move to the left subtree
        else if (root->val > key)
        {
            ceil = root->val;
            root = root->left;
        }
        // If the current node's value is less than the key, move to the right subtree
        else
        {
            root = root->right;
        }
        
    }

    // Return the ceil value
    return ceil;
}

int main()
{
    // Example 1
    // Construct the BST
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    // Find the ceil of the given value in the BST
    int key = 5;
    cout << "Ceil of " << key << " in the BST: " << ceilInBST(root, key) << endl;

    // Example 2
    // Construct the BST
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    // Find the ceil of the given value in the BST
    key = 14;
    cout << "Ceil of " << key << " in the BST: " << ceilInBST(root, key) << endl;

    return 0;
}
