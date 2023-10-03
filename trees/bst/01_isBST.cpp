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

bool isValid(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if (!root)
        return true;

    if (min && root->val <= min->val)
        return false;
    if (max && root->val >= max->val)
        return false;

    return isValid(root->left, min, root) && isValid(root->right, root, max);
}

bool isValidBST(TreeNode *root)
{
    return isValid(root, nullptr, nullptr);
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
    cout << isValidBST(root);
    return 0;
}