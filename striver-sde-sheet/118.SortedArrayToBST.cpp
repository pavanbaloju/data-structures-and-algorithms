#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode structure representing a TreeNode in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// Problem Statement:
// Given a sorted array, convert it into a height-balanced binary search tree (BST).
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every TreeNode never differs by more than one.

// Intuition:
// To create a height-balanced BST from a sorted array, we can select the middle element of the array as the root of the tree.
// Then, we recursively construct the left and right subtrees using the elements to the left and right of the middle element, respectively.

// DSA Strategy:
// We will use a recursive approach to construct the height-balanced BST

// Approach:
// We will create a BST from the sorted array using a recursive function sortedArrayToBST.
// We will pass the start and end indices of the array to the function to construct the BST from the specified range.
// The middle element of the array will be selected as the root of the current subtree.
// The left and right subtrees will be recursively constructed from the elements to the left and right of the middle element, respectively.

// Time Complexity: O(n), where n is the number of elements in the sorted array.
// Space Complexity: O(log n) on the recursive call stack.

// Function to create BST from sorted array
TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
{
    // Base case: If the start index is greater than the end index, return null
    if (start > end)
        return nullptr;

    // Find the middle element of the array
    int mid = start + (end - start) / 2;

    // Create a new TreeNode with the middle element as the value
    TreeNode *root = new TreeNode(nums[mid]);

    // Recursively create left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    // Return the root of the BST
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    // Call the recursive function to create the BST from the sorted array
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Function to find the inorder traversal of the BST
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    // Input array
    vector<int> nums = {-10, -3, 0, 5, 9};

    // Create a BST from the sorted array
    TreeNode *root = sortedArrayToBST(nums);

    // Print the inorder traversal of the BST
    inorder(root);

    return 0;
}
