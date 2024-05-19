#include <iostream>
using namespace std;

// Definition of the TreeNode class
class TreeNode
{
public:
    int val;                                                   // Value of the node
    TreeNode *left;                                            // Pointer to the left child
    TreeNode *right;                                           // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor to initialize the node
};

// Function to flatten the binary tree to a linked list
void flatten(TreeNode *root)
{
    if (root == nullptr)
    {
        // If the tree is empty, there's nothing to flatten
        return;
    }

    // Recursively flatten the left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store the original right subtree in a temporary variable
    TreeNode *rightSubtree = root->right;

    // Move the left subtree to the right of the current node
    root->right = root->left;
    root->left = nullptr; // Set the left child to nullptr since it's now moved

    // Find the end of the new right subtree (which was the left subtree)
    TreeNode *current = root;
    while (current->right != nullptr)
    {
        current = current->right; // Traverse to the end of the new right subtree
    }

    // Attach the original right subtree to the end of the new right subtree
    current->right = rightSubtree;
}

// Helper function to print the flattened linked list
void printFlattenedTree(TreeNode *root)
{
    TreeNode *current = root;
    while (current != nullptr)
    {
        cout << current->val << " "; // Print the value of the current node
        current = current->right;    // Move to the next node in the list
    }
    cout << endl; // Print a new line at the end
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Flatten the binary tree to a linked list
    flatten(root);

    // Print the flattened linked list
    cout << "Flattened tree: ";
    printFlattenedTree(root);

    return 0;
}
