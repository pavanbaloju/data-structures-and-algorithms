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

void preOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int rootIndexInOrder = mp[root->val];
    int noOfNodesInLeft = rootIndexInOrder - inStart;

    root->left = build(preorder, preStart + 1, preStart + noOfNodesInLeft, inorder, inStart, rootIndexInOrder - 1, mp);
    root->right = build(preorder, preStart + noOfNodesInLeft + 1, preEnd, inorder, rootIndexInOrder + 1, inEnd, mp);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < preorder.size(); i++)
        mp[inorder[i]] = i;
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7}, preorder = {3, 9, 20, 15, 7};
    TreeNode *root = buildTree(inorder, preorder);
    preOrderTraversal(root);
    return 0;
}