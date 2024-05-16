#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
// construct and return the binary tree.

// Intuition:
// The problem can be solved using recursion. We can construct the binary tree by recursively building its left and right subtrees.

// DSA Strategy:
// Recursion, Hash Table (for storing indices of values in inorder traversal)

// Approach:
// 1. Create a hash map to store the indices of values in the inorder traversal.
// 2. Implement a recursive function 'build' to build the binary tree from the preorder and inorder traversal sequences.
//    - Base case: If the start index exceeds the end index in either preorder or inorder traversal, return NULL.
//    - Create a new TreeNode with the value at the current preorder start index.
//    - Find the index of the root value in the inorder traversal.
//    - Calculate the number of nodes in the left subtree.
//    - Recursively build the left subtree.
//    - Recursively build the right subtree.
// 3. In the 'buildTree' function, call the 'build' function with appropriate parameters.
// 4. Return the root of the constructed binary tree.
// 5. In the main function, call 'buildTree' with the given preorder and inorder traversal sequences.
// 6. Perform preorder traversal of the constructed binary tree and print the nodes.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n), for the recursion stack and the hash map.

// Definition of TreeNode structure representing a node in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

// Recursive function to build the binary tree from preorder and inorder traversal sequences
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
