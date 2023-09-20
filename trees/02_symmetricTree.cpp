#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

bool childSymmetric(TreeNode *left, TreeNode *right)
{
    if (left == nullptr || right == nullptr)
        return left == right;
    if (left->val != right->val)
        return false;
    return childSymmetric(left->left, right->right) and childSymmetric(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr || root->right == nullptr)
    {
        return root->left == root->right;
    }
    return childSymmetric(root->left, root->right);
}
bool isSymmetric2(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    if (root->left == nullptr || root->right == nullptr)
    {
        return root->left == root->right;
    }
    queue<TreeNode *> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty())
    {
        TreeNode *left = q1.front();
        q1.pop();
        TreeNode *right = q2.front();
        q2.pop();

        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
        {
            return false;
        }
        if (left)
        {
            if (left->val != right->val)
            {
                return false;
            }

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << isSymmetric2(root);
    return 0;
}