#include <iostream>
using namespace std;

// Definition of the TreeNode class
class TreeNode
{
public:
    int val;         // Value of the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        // If the tree is empty, create a new node with the given value
        return new TreeNode(val);
    }

    // Traverse the tree to find the correct position for the new value
    if (val < root->val)
    {
        // If the value is less than the current node's value, go to the left subtree
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        // If the value is greater than or equal to the current node's value, go to the right subtree
        root->right = insertIntoBST(root->right, val);
    }

    // Return the unchanged root node
    return root;
}

// Helper function to print the BST in-order
void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Traverse the right subtree
    inOrderTraversal(root->right);
}

int main()
{
    // Construct the initial BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Print the initial BST
    cout << "Initial BST (in-order): ";
    inOrderTraversal(root);
    cout << endl;

    // Insert a new value into the BST
    int newVal = 5;
    root = insertIntoBST(root, newVal);

    // Print the updated BST
    cout << "BST after inserting " << newVal << " (in-order): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
