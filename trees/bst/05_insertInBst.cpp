#include <iostream>
#include <vector>
#include <stack>
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

TreeNode *insertIntoBST(TreeNode *node, int val)
{
    if (!node)
        return new TreeNode(val);

    TreeNode *root = node, *prev = root;
    while (root != nullptr)
    {
        if (root->val < val)
        {
            prev = root;
            root = root->right;
        }
        else
        {
            prev = root;
            root = root->left;
        }
    }
    if (prev->val < val)
    {
        prev->right = new TreeNode(val);
    }
    else
    {
        prev->left = new TreeNode(val);
    }

    return node;
}

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
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    insertIntoBST(root, 10);
    inorder(root);
    return 0;
}