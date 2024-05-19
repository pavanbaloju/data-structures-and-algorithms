#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> diameterHelper(TreeNode *root)
{
    // Base case: if the tree is empty, return pair(0, 0)
    if (root == nullptr)
    {
        return {0, 0};
    }

    // Recursive calls to find the diameter and height of the left subtree
    pair<int, int> leftResult = diameterHelper(root->left);

    // Recursive calls to find the diameter and height of the right subtree
    pair<int, int> rightResult = diameterHelper(root->right);

    // Calculate the diameter passing through the current node
    int throughRootDiameter = leftResult.first + rightResult.first + 1;

    // The diameter of the current subtree is the maximum of the diameter
    // passing through the current node, the diameter of the left subtree,
    // and the diameter of the right subtree
    int maxSubtreeDiameter = max({throughRootDiameter, leftResult.second, rightResult.second});

    // The height of the current subtree is the maximum of the height of the
    // left subtree and the height of the right subtree, plus 1 for the current node
    int subtreeHeight = max(leftResult.second, rightResult.second) + 1;

    return {maxSubtreeDiameter, subtreeHeight};
}

int diameterOfBinaryTree(TreeNode *root)
{
    // Call the helper function to compute the diameter of the binary tree
    return diameterHelper(root).first;
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    // Find the diameter of the tree
    int treeDiameter = diameterOfBinaryTree(root);

    // Output the diameter of the tree
    cout << "Diameter of the tree: " << treeDiameter << endl;

    return 0;
}
