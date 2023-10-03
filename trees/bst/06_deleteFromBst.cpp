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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (root->val == key && !root->left && !root->right)
        return nullptr;

    if (root->val == key && !root->left && root->right)
        return root->right;

    if (root->val == key && root->left && !root->right)
        return root->left;

    TreeNode *node = nullptr, *parent = nullptr, *temp = root;
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

    if (!node)
    {
        return root;
    }

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
    else
    {
        TreeNode *t = inorderSuccessor(root, node);
        swap(node->val, t->val);
        node->right = deleteNode(node->right, t->val);
    }
    return root;
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
    // root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);
    cout<<inorderSuccessor(root, root->right)->val<<" ";
    TreeNode *r = deleteNode(root, 5);
    inorder(r);
    return 0;
}