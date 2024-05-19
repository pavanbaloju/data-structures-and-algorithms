#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to delete all leaf nodes with a given value
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    // Base case: if the tree is empty, return nullptr
    if (root == nullptr)
    {
        return nullptr;
    }

    // Recursively process the left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // If the current node is a leaf with the target value, delete it
    if (root->left == nullptr && root->right == nullptr && root->val == target)
    {
        delete root;
        return nullptr;
    }

    // Return the (possibly modified) current node
    return root;
}

void printTree(TreeNode *root, int depth = 0)
{
    if (root == nullptr)
        return;
    printTree(root->right, depth + 1);
    cout << string(depth * 4, ' ') << root->val << endl;
    printTree(root->left, depth + 1);
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    cout << "Original Tree:" << endl;
    printTree(root);

    // Delete all leaf nodes with value 2
    root = removeLeafNodes(root, 2);

    cout << "\nTree after deleting leaves with value 2:" << endl;
    printTree(root);

    return 0;
}
