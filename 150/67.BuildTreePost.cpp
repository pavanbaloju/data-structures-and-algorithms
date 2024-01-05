#include <iostream>
#include <vector>
#include <unordered_map>
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

void inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}
TreeNode *build(vector<int> &postorder, int start, int end, unordered_map<int, int> &m)
{
    if (start > end || postorder.empty())
        return nullptr;

    TreeNode *root = new TreeNode(postorder.back());
    postorder.pop_back();

    int rootIdx = m[root->val];
    root->right = build(postorder, rootIdx + 1, end, m);
    root->left = build(postorder, start, rootIdx - 1, m);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;

    return build(postorder, 0, inorder.size() - 1, m);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(inorder, postorder);
    inOrderTraversal(root);
    return 0;
}