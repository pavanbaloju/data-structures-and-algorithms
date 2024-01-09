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

void inorder(TreeNode *curr, int &prev, int &minDiff)
{
    if (!curr)
        return;

    inorder(curr->left, prev, minDiff);

    if (prev != -1)
        minDiff = min(curr->val - prev, minDiff);
    prev = curr->val;

    inorder(curr->right, prev, minDiff);
}

int getMinimumDifference(TreeNode *root)
{
    int ans = INT_MAX;
    int prev = -1;
    inorder(root, prev, ans);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    cout << getMinimumDifference(root);
    return 0;
}