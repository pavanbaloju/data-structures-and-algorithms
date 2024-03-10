#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Structure to store information about a subtree
struct SubtreeInfo
{
    int sum;      // Sum of nodes in the subtree
    int minValue; // Minimum value in the subtree
    int maxValue; // Maximum value in the subtree
    bool isBST;   // Indicates whether the subtree is a BST
};

// Problem Statement: Find the maximum sum Binary Search Tree (BST) in a given binary tree.

// Intuition: Perform a bottom-up traversal of the binary tree, 
// checking at each node if its left and right subtrees form a BST and calculating the sum of the subtree.

// DSA strategy used: Depth-First Search (DFS) with Bottom-up approach

// Approach:
// 1. Define a recursive helper function that returns SubtreeInfo for each subtree.
// 2. At each node, recursively find the properties of its left and right subtrees.
// 3. Check if the current subtree is a BST by verifying if its left and right subtrees are BSTs and if the current node's value satisfies the BST property.
// 4. If the subtree is a BST, calculate the sum of nodes in the subtree.
// 5. Update the maximum sum if the current subtree's sum is greater.
// 6. Return SubtreeInfo for the current subtree.
// 7. The main function initializes a variable to track the maximum sum BST found so far.
// 8. Call the recursive helper function starting from the root of the binary tree.
// 9. Return the maximum sum BST.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive call stack space).
// Function to recursively find the maximum sum BST in a binary tree

SubtreeInfo findMaxSumBSTHelper(TreeNode *root, int &maxSum)
{
    if (!root)
    {
        return {0, INT_MAX, INT_MIN, true};
    }

    // Recursively find information about left and right subtrees
    SubtreeInfo leftInfo = findMaxSumBSTHelper(root->left, maxSum);
    SubtreeInfo rightInfo = findMaxSumBSTHelper(root->right, maxSum);

    // Check if the current subtree is a valid BST
    if (leftInfo.isBST && rightInfo.isBST && root->val > leftInfo.maxValue && root->val < rightInfo.minValue)
    {
        // Calculate the sum of nodes in the subtree
        int sum = root->val + leftInfo.sum + rightInfo.sum;

        // Update the maximum sum if necessary
        maxSum = max(maxSum, sum);

        // Return information about the current subtree
        return {sum, min(root->val, leftInfo.minValue), max(root->val, rightInfo.maxValue), true};
    }
    else
    {
        // If the current subtree is not a valid BST, mark it as such and return 0 sum
        return {0, 0, 0, false};
    }
}

// Function to find the maximum sum BST in a binary tree
int maxSumBST(TreeNode *root)
{
    int maxSum = 0;
    findMaxSumBSTHelper(root, maxSum);
    return maxSum;
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Find the maximum sum BST in the binary tree
    cout << "Maximum sum BST: " << maxSumBST(root) << endl;

    return 0;
}
