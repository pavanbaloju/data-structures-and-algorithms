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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<vector<int>> values;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int k = q.size();
        while (k--)
        {
            TreeNode *TreeNode = q.front();
            q.pop();
            level.push_back(TreeNode->val);

            if (TreeNode->left)
                q.push(TreeNode->left);
            if (TreeNode->right)
                q.push(TreeNode->right);
        }
        values.push_back(level);
    }
    return values;
}

// recursive
void printCurrentLevel(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
void printLevelOrder(TreeNode *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int>> res = levelOrder(root);
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
    }
    cout << endl;
    printLevelOrder(root);
    return 0;
}