#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;         // Value of the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and left, right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to search for a value in a Binary Search Tree
TreeNode *searchBST(TreeNode *root, int val)
{
    // Traverse the tree until the root is null
    while (root != nullptr)
    {
        // If the current node's value equals the search value, return the node
        if (root->val == val)
            return root;

        // If the search value is greater, go to the right subtree
        if (root->val < val)
        {
            root = root->right;
        }
        // If the search value is smaller, go to the left subtree
        else
        {
            root = root->left;
        }
    }
    // If the value is not found, return nullptr
    return nullptr;
}

int main()
{
    // Create a sample binary search tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Search for a value in the BST and print the result
    TreeNode *result = searchBST(root, 6);
    if (result)
        cout << "Value found: " << result->val << endl;
    else
        cout << "Value not found" << endl;

    // Clean up memory (avoid memory leaks)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
