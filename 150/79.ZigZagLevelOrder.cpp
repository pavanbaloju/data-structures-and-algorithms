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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<vector<int>> values;
    queue<TreeNode *> q;
    q.push(root);
    bool rtl = false;
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
        if (rtl)
        {
            reverse(level.begin(), level.end());
        }
        values.push_back(level);
        rtl = !rtl;
    }
    return values;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int>> res = zigzagLevelOrder(root);
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}