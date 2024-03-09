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
// Given inorder and postorder traversal sequences of a binary tree, construct the binary tree.
// Assume that duplicates do not exist in the tree.

// Intuition:
// To reconstruct the binary tree from its inorder and postorder traversals, we can follow these steps:
// 1. Use the last element of the postorder traversal sequence to create the root node.
// 2. Find the root node's position in the inorder traversal to determine the left and right subtrees.
// 3. Recursively build the right subtree.
// 4. Recursively build the left subtree.

// DSA Strategy:
// We will use a recursive approach to construct the binary tree efficiently.
// We will maintain a map to store the indices of values in the inorder traversal for quick lookup.

// Approach:
// Recursive approach to construct the binary tree from inorder and postorder traversals.
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The time complexity arises from the traversal of the postorder sequence,
//     as well as the construction of the binary tree.
// Space Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The space complexity arises due to the recursive calls on the stack and the unordered map.

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
