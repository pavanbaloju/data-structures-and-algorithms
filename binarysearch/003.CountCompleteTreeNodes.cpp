#include <iostream>
#include <queue>

using namespace std;

// Problem Statement:
// Given the root of a complete binary tree, return the number of nodes in the tree.

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Intuition:
// We can solve this problem using various approaches such as brute force (recursive), level order traversal, and binary search.
// 1. Brute Force (Recursive): Recursively count the nodes in the tree.
// 2. Level Order Traversal (Iterative): Use a queue to perform level order traversal and count the nodes.
// 3. Binary Search: Determine the height of the left and right subtrees. If they are equal, the tree is full and contains 2^h - 1 nodes. Otherwise, recursively count nodes in the left and right subtrees.

// DSA Strategy/Pattern:
// Brute Force, Level Order Traversal, Binary Search

// Approach 1 (Brute Force - Recursive):
// Explanation:
// 1. Base case: If the root is null, return 0.
// 2. Recursively count the nodes in the left and right subtrees.
// 3. Add 1 for the current node.
// 4. Return the total count.

// Time Complexity: O(n)
// Space Complexity: O(n) on the stack (recursion)

int countNodes_BruteForce(TreeNode *root)
{
    if (!root)
        return 0;
    // Count the nodes in the current tree recursively
    return 1 + countNodes_BruteForce(root->left) + countNodes_BruteForce(root->right);
}

// Approach 2 (Level Order Traversal - Iterative):
// Explanation:
// 1. If the root is null, return 0.
// 2. Initialize a queue for level order traversal and push the root.
// 3. While the queue is not empty, dequeue a node, increment the count, and enqueue its children.
// 4. Return the count.

// Time Complexity: O(n)
// Space Complexity: O(n) for the queue

int countNodes_LevelOrder(TreeNode *root)
{
    if (!root)
        return 0;
    int count = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        count++;
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    return count;
}

// Approach 3 (Binary Search):
// Explanation:
// 1. If the root is null, return 0.
// 2. Calculate the height of the left subtree and right subtree.
// 3. If the heights are equal, the tree is full and contains 2^h - 1 nodes.
// 4. Otherwise, recursively count nodes in the left and right subtrees.

// Time Complexity: O(log^2 n)
// Space Complexity: O(1)

int countNodes_BinarySearch(TreeNode *root)
{
    if (!root)
        return 0;
    int height_left = 0, height_right = 0;
    TreeNode *left = root, *right = root;
    // Calculate the height of the left subtree
    while (left)
    {
        height_left++;
        left = left->left;
    }
    // Calculate the height of the right subtree
    while (right)
    {
        height_right++;
        right = right->right;
    }
    // If the heights are equal, the tree is full and contains 2^h - 1 nodes
    if (height_left == height_right)
    {
        return (1 << height_left) - 1;
    }
    // If the heights are not equal, recursively count nodes in the left and right subtrees
    return 1 + countNodes_BinarySearch(root->left) + countNodes_BinarySearch(root->right);
}

// Main function
int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Brute Force
    cout << "Number of nodes (Brute Force): " << countNodes_BruteForce(root) << endl;

    // Level Order Traversal
    cout << "Number of nodes (Level Order): " << countNodes_LevelOrder(root) << endl;

    // Binary Search
    cout << "Number of nodes (Binary Search): " << countNodes_BinarySearch(root) << endl;

    return 0;
}
