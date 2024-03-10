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

// Structure to hold properties of a subtree
struct SubtreeInfo
{
    bool isBST;     // Indicates whether the subtree is a binary search tree (BST)
    int size;       // Size of the subtree
    int minValue;   // Minimum value in the subtree
    int maxValue;   // Maximum value in the subtree
};

// Problem Statement: Find the largest Binary Search Tree (BST) within a given binary tree.

// Intuition: Perform a bottom-up traversal of the binary tree, checking at each node if its left and right subtrees form a BST and calculating the size of the subtree.

// DSA strategy used: Depth-First Search (DFS) with Bottom-up approach

// Approach:
// 1. Define a recursive helper function that returns SubtreeInfo for each subtree.
// 2. At each node, recursively find the properties of its left and right subtrees.
// 3. Check if the current subtree is a BST by verifying if its left and right subtrees are BSTs and if the current node's value satisfies the BST property.
// 4. Update the maximum BST size and root if the current subtree is a larger BST.
// 5. Return the SubtreeInfo for the current subtree.
// 6. The main function initializes variables to track the maximum BST size and the root of the largest BST found so far.
// 7. Call the recursive helper function starting from the root of the binary tree.
// 8. Return the root of the largest BST.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (recursive call stack space).

// Function to recursively traverse the binary tree and return subtree properties
SubtreeInfo findLargestBSTHelper(TreeNode *root, int &maxBSTSize, TreeNode *&largestBSTRoot)
{
    if (root == nullptr)
    {
        // Base case: Return properties of an empty subtree
        return {true, 0, INT_MAX, INT_MIN};
    }

    // Recursively find properties of left and right subtrees
    SubtreeInfo leftInfo = findLargestBSTHelper(root->left, maxBSTSize, largestBSTRoot);
    SubtreeInfo rightInfo = findLargestBSTHelper(root->right, maxBSTSize, largestBSTRoot);

    // Check if the current subtree is a BST
    if (leftInfo.isBST && rightInfo.isBST && root->val > leftInfo.maxValue && root->val < rightInfo.minValue)
    {
        // If the current subtree is a BST, update the maximum BST size and root if needed
        int subtreeSize = 1 + leftInfo.size + rightInfo.size;
        if (subtreeSize > maxBSTSize)
        {
            maxBSTSize = subtreeSize;
            largestBSTRoot = root;
        }
        // Return properties of the current subtree
        return {true, subtreeSize, min(root->val, leftInfo.minValue), max(root->val, rightInfo.maxValue)};
    }

    // If the current subtree is not a BST, return properties indicating that it is not a BST
    return {false, 0, 0, 0};
}

// Function to find the largest BST in the given binary tree
TreeNode *findLargestBST(TreeNode *root)
{
    if (root == nullptr)
    {
        // If the root is null, return null (no BST found)
        return nullptr;
    }

    int maxBSTSize = 0;
    TreeNode *largestBSTRoot = nullptr;
    // Find the largest BST recursively
    findLargestBSTHelper(root, maxBSTSize, largestBSTRoot);

    return largestBSTRoot; // Return the root of the largest BST
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Find the largest BST in the binary tree
    TreeNode *largestBST = findLargestBST(root);

    // Print the root value of the largest BST
    if (largestBST != nullptr)
    {
        cout << "Root value of the largest BST: " << largestBST->val << endl;
    }
    else
    {
        cout << "No BST found in the tree." << endl;
    }

    return 0;
}
