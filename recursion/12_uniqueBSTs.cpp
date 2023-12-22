#include <iostream>
#include <vector>
#include <map>
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
    {
        cout << "null ";
        return;
    }

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
vector<TreeNode *> gen(int left, int right, map<pair<int, int>, vector<TreeNode *>> &memo)
{
    vector<TreeNode *> res = vector<TreeNode *>();
    if (left > right)
        return {nullptr};

    if (memo.count({left, right}))
        return memo[{left, right}];

    for (int val = left; val <= right; val++)
    {
        vector<TreeNode *> leftTrees = gen(left, val - 1, memo);
        vector<TreeNode *> rightTrees = gen(val + 1, right, memo);
        for (auto left : leftTrees)
        {
            for (auto right : rightTrees)
            {
                TreeNode *root = new TreeNode(val, left, right);
                res.push_back(root);
            }
        }
    }

    return memo[{left, right}] = res;
}

vector<TreeNode *> generateTrees(int n)
{
    map<pair<int, int>, vector<TreeNode *>> memo;
    return gen(1, n, memo);
}

/*
n == 1:
{1}
n==2:
    1               1
2       null  null      2
*/

int main()
{
    vector<TreeNode *> trees = generateTrees(3);
    for (auto tree : trees)
    {
        preOrder(tree);
        cout << endl;
    }
    return 0;
}