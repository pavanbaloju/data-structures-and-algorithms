#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode*> s;
    while (root || !s.empty())
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> inorder = inorderTraversal(root);
    for (int x : inorder)
        cout << x << " ";
    return 0;
}