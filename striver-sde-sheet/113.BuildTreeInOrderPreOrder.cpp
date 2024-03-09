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
// Given preorder and inorder traversal sequences of a binary tree, construct the binary tree.
// Assume that duplicates do not exist in the tree.

// Intuition:
// To reconstruct the binary tree from its preorder and inorder traversals, we can follow these steps:
// 1. Use the first element of the preorder traversal sequence to create the root node.
// 2. Find the root node's position in the inorder traversal to determine the left and right subtrees.
// 3. Recursively build the left subtree using the left part of the inorder traversal.
// 4. Recursively build the right subtree using the right part of the inorder traversal.

// DSA Strategy:
// We will use a recursive approach to construct the binary tree efficiently.
// We will maintain a map to store the indices of values in the inorder traversal for quick lookup.

// Approach:
// Recursive approach to construct the binary tree from preorder and inorder traversals.
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The time complexity arises from the traversal of the preorder and inorder sequences,
//     as well as the construction of the binary tree.
// Space Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The space complexity arises due to the recursive calls on the stack and the unordered map.

// Function to perform preorder traversal of the binary tree and print the nodes
void preOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // Print the value of the current node
    cout << root->val << " ";
    // Recursively traverse the left subtree
    preOrderTraversal(root->left);
    // Recursively traverse the right subtree
    preOrderTraversal(root->right);
}

// Function to recursively build the binary tree from preorder and inorder traversal sequences
TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    // Base case: If the start index exceeds the end index in either preorder or inorder traversal, return NULL
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }
    // Create a new TreeNode with the value at the current preorder start index
    TreeNode *root = new TreeNode(preorder[preStart]);
    // Find the index of the root value in the inorder traversal
    int inRootIndex = mp[root->val];
    // Calculate the number of nodes in the left subtree
    int numsLeft = inRootIndex - inStart;

    // Recursively build the left subtree
    root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRootIndex - 1, mp);
    // Recursively build the right subtree
    root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRootIndex + 1, inEnd, mp);

    return root;
}

// Function to construct the binary tree from preorder and inorder traversal sequences
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // Create a hash map to store the indices of values in the inorder traversal
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    // Recursively build the binary tree
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

int main()
{
    // Example input: inorder and preorder traversal sequences
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    // Build the binary tree from the traversal sequences
    TreeNode *root = buildTree(inorder, preorder);

    // Perform preorder traversal and print the nodes
    cout << "Preorder traversal of the constructed binary tree: ";
    preOrderTraversal(root);

    return 0;
}
