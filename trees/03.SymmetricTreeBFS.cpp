#include <iostream>
#include <queue>
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
// We can use breadth-first search (BFS) traversal to check if a binary tree is symmetric.
// We start BFS traversal from the root and compare corresponding nodes at each level.
// At each level, we check if the left child of the left node is equal to the right child of the right node,
// and if the right child of the left node is equal to the left child of the right node.

// DSA Strategy:
// We will use BFS traversal to compare corresponding nodes at each level of the binary tree.
// We will use a queue to store nodes for BFS traversal.

// Approach:
// BFS approach to check if a binary tree is symmetric.
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
//   - We traverse each node once.
// Space Complexity: O(n), where n is the number of nodes in the binary tree.
//   - The space complexity arises due to the queue used for BFS traversal.

// Function to check if the binary tree is symmetric using BFS
bool isSymmetric(TreeNode *root)
{
    // If the root is null, it is symmetric
    if (root == nullptr)
        return true;

    // Create a queue to store nodes for BFS traversal
    queue<TreeNode *> q;
    // Add the root's left and right children to the queue
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        // Get the left and right nodes for comparison
        TreeNode *leftNode = q.front();
        q.pop();
        TreeNode *rightNode = q.front();
        q.pop();

        // If both nodes are null, continue to the next iteration
        if (leftNode == nullptr && rightNode == nullptr)
            continue;
        // If one of the nodes is null but not both, or their values are different, return false
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val)
            return false;

        // Add the left child of leftNode and the right child of rightNode to the queue
        q.push(leftNode->left);
        q.push(rightNode->right);
        // Add the right child of leftNode and the left child of rightNode to the queue
        q.push(leftNode->right);
        q.push(rightNode->left);
    }

    // If the loop completes without returning false, the tree is symmetric
    return true;
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
