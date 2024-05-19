#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition of a binary tree node
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

// Function to perform pre-order traversal of the binary tree
void preOrder(TreeNode *root)
{
    // Base case: if the node is null, return
    if (!root)
        return;

    // Visit the root node
    cout << root->val << " ";
    // Recursively visit the left subtree
    preOrder(root->left);
    // Recursively visit the right subtree
    preOrder(root->right);
}

// Function to invert a binary tree
TreeNode *invertTree(TreeNode *root)
{
    // Base case: if the node is null, return the node
    if (root == nullptr)
        return root;

    // Recursively invert the left subtree
    invertTree(root->left);
    // Recursively invert the right subtree
    invertTree(root->right);
    // Swap the left and right children of the current node
    swap(root->left, root->right);
    // Return the root node
    return root;
}

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform pre-order traversal before inverting the tree
    cout << "Pre-order traversal before inverting the tree: ";
    preOrder(root);
    cout << endl;

    // Invert the binary tree
    TreeNode *newRoot = invertTree(root);

    // Perform pre-order traversal after inverting the tree
    cout << "Pre-order traversal after inverting the tree: ";
    preOrder(newRoot); // Alternatively, you can use `preOrder(root)` since the tree is modified in place
    cout << endl;

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
