#include <iostream>
#include <vector>
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

void solve(TreeNode *root, vector<int> &res, int height)
{
    if (root == NULL)
    {
        return;
    }

    // check if result does not have values of current height
    // values {1, 3, 5} -> size is 3, last height traversed is 2, if height == 3, add to result
    if (height == res.size())
    {
        res.push_back(root->val);
    }
    solve(root->right, res, height + 1);
    solve(root->left, res, height + 1);
}

vector<int> rightSideViewDFS(TreeNode *root)
{
    vector<int> res;
    solve(root, res, 0);
    return res;
}

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> values;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int k = q.size();
        while (k--)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        values.push_back(level.back());
    }
    return values;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> res = rightSideViewDFS(root);
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}