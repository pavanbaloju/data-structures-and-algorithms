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

void inOrderTraversal(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;

    // left, root, right
    inOrderTraversal(root->left, v);
    v.push_back(root->val);
    inOrderTraversal(root->right, v);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> v;
    inOrderTraversal(root, v);
    return v[k - 1];
}

void inorder(TreeNode *root, int &k, int &kth)
{
    if (!root || k == 0)
        return;

    inorder(root->left, k, kth);
    if (--k == 0)
    {
        kth = root->val;
        return;
    }
    inorder(root->right, k, kth);
}

int kthSmallestOpt(TreeNode *root, int k)
{
    int kth = 0;
    inorder(root, k, kth);
    return kth;
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

    cout << kthSmallestOpt(root, 3);
    return 0;
}