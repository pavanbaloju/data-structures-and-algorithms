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

void preOrder(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void solve(TreeNode *root, int &curr, int &sum)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        sum += curr * 10 + root->val;
        return;
    }
    curr = curr * 10 + root->val;
    solve(root->left, curr, sum);
    solve(root->right, curr, sum);
    curr = curr / 10;
}

int sumNumbers(TreeNode *root)
{
    if (!root)
        return 0;
    int sum = 0, curr = 0;
    solve(root, curr, sum);
    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preOrder(root);
    cout << endl;
    cout << sumNumbers(root);
    return 0;
}