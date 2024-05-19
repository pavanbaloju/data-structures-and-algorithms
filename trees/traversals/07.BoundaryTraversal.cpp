#include <iostream>
#include <vector>
using namespace std;

// Definition of a TreeNode structure representing a node in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Problem statement
// Given a binary tree, return its boundary traversal. The boundary traversal consists of the nodes' values along the boundary of the tree in a counter-clockwise direction starting from the root.

// Intuition
// The boundary traversal of a binary tree consists of three parts: the left boundary (excluding the leaf nodes if they are the leftmost or rightmost nodes), the leaf nodes from left to right, and the right boundary (excluding the leaf nodes if they are the leftmost or rightmost nodes).
// We can compute each part separately using recursive functions: printLeftBoundary, printRightBoundary, and printLeaves.

// DSA strategy used to solve the problem
// We use a recursive approach to compute the left boundary, right boundary, and leaf nodes of the binary tree. Then, we concatenate these parts to get the boundary traversal of the tree.

// Approach: clearly explain the algorithm step by step
// 1. Initialize an empty vector 'result' to store the boundary traversal.
// 2. If the root is null, return an empty result.
// 3. Add the value of the root node to 'result'.
// 4. Compute the left boundary (excluding the leaf nodes if they are the leftmost or rightmost nodes) using the printLeftBoundary function.
// 5. Compute the leaf nodes of the tree from left to right using the printLeaves function.
// 6. Compute the right boundary (excluding the leaf nodes if they are the leftmost or rightmost nodes) using the printRightBoundary function.
// 7. Return the 'result'.

// Time and Space complexity
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (the maximum depth of the function call stack in the recursive approach).

// Helper function to check if a node is a leaf node
bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}

// Function to print the left boundary of the tree (excluding the leaf node if it is the leftmost or rightmost node)
void printLeftBoundary(TreeNode *root, vector<int> &result)
{
    if (!root || isLeaf(root))
        return;

    // Add the value of the current node to the result
    result.push_back(root->val);

    // Recursively traverse the left subtree if it exists
    if (root->left)
    {
        printLeftBoundary(root->left, result);
    }
    else
    {
        // If the left subtree doesn't exist, traverse the right subtree
        printLeftBoundary(root->right, result);
    }
}

// Function to print the right boundary of the tree (excluding the leaf node if it is the leftmost or rightmost node)
void printRightBoundary(TreeNode *root, vector<int> &result)
{
    if (!root || isLeaf(root))
        return;

    // Recursively traverse the right subtree if it exists
    if (root->right)
    {
        printRightBoundary(root->right, result);
    }
    else
    {
        // If the right subtree doesn't exist, traverse the left subtree
        printRightBoundary(root->left, result);
    }

    // Add the value of the current node to the result
    result.push_back(root->val);
}

// Function to print the leaf nodes of the tree from left to right
void printLeaves(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;

    // If the current node is a leaf node, add its value to the result
    if (isLeaf(root))
    {
        result.push_back(root->val);
    }

    // Recursively traverse the left and right subtrees
    printLeaves(root->left, result);
    printLeaves(root->right, result);
}

// Function to compute the boundary traversal of the binary tree
vector<int> boundaryOfBinaryTree(TreeNode *root)
{
    vector<int> result;

    // Return an empty result if the tree is empty
    if (!root)
        return result;

    // Print the root node
    result.push_back(root->val);

    // Print the left boundary (excluding the leaf node if it is the leftmost or rightmost node)
    printLeftBoundary(root->left, result);

    // Print the leaf nodes of the tree from left to right
    printLeaves(root->left, result);
    printLeaves(root->right, result);

    // Print the right boundary (excluding the leaf node if it is the leftmost or rightmost node)
    printRightBoundary(root->right, result);

    return result;
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);

    // Compute the boundary traversal of the binary tree
    vector<int> result = boundaryOfBinaryTree(root);

    // Print the boundary traversal
    cout << "Boundary traversal of the binary tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
