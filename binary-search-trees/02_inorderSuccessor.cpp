#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *node)
{
    TreeNode *successor = nullptr;
    while (root != nullptr)
    {
        if (node->val < root->val)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    cout << inorderSuccessor(root, root->left)->val;
    return 0;
}