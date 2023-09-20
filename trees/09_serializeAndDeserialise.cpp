#include <iostream>
#include <sstream>
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
string serialize(TreeNode *root)
{
    if (!root)
        return "";

    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
            s.append("#,");
        else
        {
            s.append(to_string(node->val) + ',');
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}
TreeNode *deserialize(string data)
{
    if (data.empty())
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            node->left = nullptr;
        }
        else
        {
            TreeNode *left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            node->right = nullptr;
        }
        else
        {
            TreeNode *right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    string t = serialize(root);
    cout << t << endl;
    root = deserialize(t);
    preOrderTraversal(root);
    return 0;
}