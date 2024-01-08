#include <iostream>
#include <vector>
#include <queue>
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

void avg(TreeNode *root, int level, map<int, pair<double, double>> &vc)
{
    if (root == NULL)
        return;

    vc[level].first += root->val; // value
    vc[level].second++; // count

    avg(root->left, level + 1, vc);
    avg(root->right, level + 1, vc);
}
vector<double> averageOfLevelsDFS(TreeNode *root)
{
    map<int, pair<double, double>> vc;
    vector<double> res;
    avg(root, 0, vc);

    for (auto i : vc)
        res.push_back(i.second.first / i.second.second);
    return res;
}

vector<double> averageOfLevels(TreeNode *root)
{
    if (!root)
        return {};

    vector<double> values;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int k = q.size();
        int k2 = k;
        double avg = 0;
        while (k--)
        {
            TreeNode *node = q.front();
            q.pop();
            avg += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        values.push_back(avg / k2);
    }
    return values;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<double> res = averageOfLevelsDFS(root);
    for (double x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}