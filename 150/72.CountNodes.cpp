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

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int getLeftHeight(TreeNode *root)
{
    int lh = 0;
    while (root)
    {
        lh++;
        root = root->left;
    }
    return lh;
}

int getRightHeight(TreeNode *root)
{
    int rh = 0;
    while (root)
    {
        rh++;
        root = root->right;
    }
    return rh;
}
int countNodes2(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);

    if (lh == rh)
        return (1 << rh) - 1;

    return 1 + countNodes2(root->left) + countNodes2(root->right);
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

    cout << countNodes(root) << endl;
    cout << countNodes2(root) << endl;
    return 0;
}