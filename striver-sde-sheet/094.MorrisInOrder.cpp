#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Problem Statement:
// Given a binary tree, perform an inorder traversal using Morris traversal algorithm.

// Intuition:
// Morris traversal algorithm allows us to perform an inorder traversal of a binary tree without using recursion or a stack.
// It modifies the tree's structure temporarily by creating threaded links without using additional space.

// DSA Strategy:
// Morris Inorder Traversal

// Approach:
// 1. Initialize an empty vector to store the values in inorder traversal order.
// 2. Start from the root node and initialize a pointer 'curr' to the root.
// 3. While 'curr' is not nullptr:
//    a. If 'curr' has a left child:
//       - Find the rightmost node in the left subtree (i.e., the inorder predecessor) and set its right pointer to 'curr' if it's not already set.
//       - If the right pointer is already set, reset it to nullptr, add the current node's value to the vector, and move to the right child.
//       - If the right pointer is not set, set it to 'curr' and move to the left child.
//    b. If 'curr' does not have a left child:
//       - Add the current node's value to the vector and move to the right child.
// 4. Return the vector containing the inorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(1) - since no additional space is used apart from the vector to store traversal values.

// Function to perform Morris Inorder Traversal of a binary tree
vector<int> morrisInorder(TreeNode *root)
{
    vector<int> values;    // Create a vector to store the values in inorder traversal order
    TreeNode *curr = root; // Start from the root node
    while (curr)
    {
        if (curr->left) // If the current node has a left child
        {
            TreeNode *prev = curr->left; // Find the rightmost node in the left subtree
            while (prev->right && prev->right != curr)
                prev = prev->right;
            if (prev->right) // If the rightmost node's right pointer is already pointing to the current node
            {
                prev->right = nullptr;       // Reset the right pointer to nullptr
                values.push_back(curr->val); // Add the current node's value to the vector
                curr = curr->right;          // Move to the right child
            }
            else // If the rightmost node's right pointer is not pointing to the current node
            {
                prev->right = curr; // Set the right pointer to the current node
                curr = curr->left;  // Move to the left child
            }
        }
        else // If the current node does not have a left child
        {
            values.push_back(curr->val); // Add the current node's value to the vector
            curr = curr->right;          // Move to the right child
        }
    }
    return values; // Return the vector containing the inorder traversal values
}

// Function to print a vector of integers
void printVector(vector<int> &values)
{
    for (int value : values)
        cout << value << " ";
    cout << endl;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Perform Morris Inorder Traversal and print the result
    vector<int> result = morrisInorder(root);
    printVector(result);
    return 0;
}
