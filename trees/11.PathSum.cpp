#include <iostream>
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

// Function to determine if there's a root-to-leaf path that sums to targetSum
bool hasPathSum(TreeNode *root, int targetSum)
{
    // If the root is null, there is no path, return false
    if (!root)
        return false;

    // Subtract the value of the current node from targetSum
    targetSum -= root->val;

    // If the current node is a leaf and targetSum is now 0, we've found a path
    if (!root->left && !root->right && targetSum == 0)
    {
        return true;
    }

    // Recursively check the left and right subtrees
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
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

    // Check if there's a root-to-leaf path with sum equal to 8
    cout << "Path with sum 8 exists: " << (hasPathSum(root, 8) ? "Yes" : "No") << endl;

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