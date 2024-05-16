#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Statement:
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
// construct and return the binary tree.

// Intuition:
// The problem can be solved using recursion. We can construct the binary tree by recursively building its left and right subtrees.

// DSA Strategy:
// Recursion, Hash Table (for storing indices of values in inorder traversal)

// Approach:
// 1. Create a hash map to store the indices of values in the inorder traversal.
// 2. Implement a recursive function 'build' to build the binary tree from the postorder and inorder traversal sequences.
//    - Base case: If the start index exceeds the end index in the inorder traversal or the postorder vector is empty, return NULL.
//    - Create a new TreeNode with the value of the last element in the postorder sequence.
//    - Remove the last element from the postorder sequence.
//    - Find the index of the root value in the inorder traversal.
//    - Recursively build the right subtree.
//    - Recursively build the left subtree.
// 3. In the 'buildTree' function, call the 'build' function with appropriate parameters.
// 4. Return the root of the constructed binary tree.
// 5. In the main function, call 'buildTree' with the given inorder and postorder traversal sequences.
// 6. Perform inorder traversal of the constructed binary tree and print the nodes.

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

// Function to perform inorder traversal of the binary tree and print the nodes
void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // Recursively traverse the left subtree
    inOrderTraversal(root->left);
    // Print the value of the current node
    cout << root->val << " ";
    // Recursively traverse the right subtree
    inOrderTraversal(root->right);
}

// Function to recursively build the binary tree from postorder traversal sequence
TreeNode *build(vector<int> &postorder, int inStart, int inEnd, unordered_map<int, int> &m)
{
    // Base case: If the start index exceeds the end index or the postorder vector is empty, return nullptr
    if (inStart > inEnd || postorder.empty())
    {
        return nullptr;
    }
    // Create a new TreeNode with the value of the last element in the postorder sequence
    TreeNode *root = new TreeNode(postorder.back());
    // Remove the last element from the postorder sequence
    postorder.pop_back();

    // Find the index of the root value in the inorder traversal
    int rootIdx = m[root->val];
    // Recursively build the right subtree
    root->right = build(postorder, rootIdx + 1, inEnd, m);
    // Recursively build the left subtree
    root->left = build(postorder, inStart, rootIdx - 1, m);

    return root;
}

// Function to construct the binary tree from inorder and postorder traversal sequences
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // Create a hash map to store the indices of values in the inorder traversal
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    // Recursively build the binary tree
    return build(postorder, 0, inorder.size() - 1, m);
}

int main()
{
    // Example input: inorder and postorder traversal sequences
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Build the binary tree from the traversal sequences
    TreeNode *root = buildTree(inorder, postorder);

    // Perform inorder traversal and print the nodes
    cout << "Inorder traversal of the constructed binary tree: ";
    inOrderTraversal(root);

    return 0;
}
