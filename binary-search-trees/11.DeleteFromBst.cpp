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

// Function to find the inorder successor of a given node in a BST
TreeNode *inorderSuccessor(TreeNode *root, TreeNode *node)
{
    TreeNode *successor = nullptr;
    while (root != nullptr)
    {
        // If the node's value is less than root's value, the successor might be the current root
        if (node->val < root->val)
        {
            successor = root;
            root = root->left;
        }
        // Otherwise, move to the right subtree
        else
        {
            root = root->right;
        }
    }
    return successor;
}

// Function to delete a node with a given key from the BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root; // If the tree is empty, return null

    // If the node to be deleted is a leaf node
    if (root->val == key && !root->left && !root->right)
        return nullptr;

    // If the node to be deleted has only a right child
    if (root->val == key && !root->left && root->right)
        return root->right;

    // If the node to be deleted has only a left child
    if (root->val == key && root->left && !root->right)
        return root->left;

    TreeNode *node = nullptr, *parent = nullptr, *temp = root;

    // Traverse the tree to find the node to be deleted and its parent
    while (temp != nullptr)
    {
        if (temp->val == key)
        {
            node = temp;
            break;
        }
        if (temp->val < key)
        {
            parent = temp;
            temp = temp->right;
        }
        else
        {
            parent = temp;
            temp = temp->left;
        }
    }

    // If the node is not found, return the original root
    if (!node)
    {
        return root;
    }

    // If the node to be deleted is a leaf node
    if (!node->left && !node->right)
    {
        if (parent->left == node)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }
    // If the node to be deleted has only one child
    else if ((!node->left && node->right) || (node->left && !node->right))
    {
        if (parent->left == node)
        {
            parent->left = node->left ? node->left : node->right;
        }
        else
        {
            parent->right = node->left ? node->left : node->right;
        }
    }
    // If the node to be deleted has two children
    else
    {
        // Find the inorder successor
        TreeNode *t = inorderSuccessor(root, node);
        // Swap values of the node and the inorder successor
        swap(node->val, t->val);
        // Delete the inorder successor
        node->right = deleteNode(node->right, t->val);
    }
    return root;
}

// Function to perform inorder traversal of the BST
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
    // Create a sample binary search tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);

    // Find and print the inorder successor of the node with value 7
    TreeNode *successor = inorderSuccessor(root, root->right);
    if (successor)
        cout << "Inorder successor of node 7 is: " << successor->val << endl;

    // Delete the node with value 5 and print the inorder traversal of the modified tree
    TreeNode *newRoot = deleteNode(root, 5);
    cout << "Inorder traversal after deleting node 5: ";
    inorder(newRoot);
    cout << endl;

    return 0;
}
