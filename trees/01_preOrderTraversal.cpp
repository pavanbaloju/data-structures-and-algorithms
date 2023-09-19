#include <iostream>
#include <vector>
#include <stack>
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
void preOrder(TreeNode *root, vector<int> &values)
{
    if (!root)
        return;

    values.push_back(root->val);
    preOrder(root->left, values);
    preOrder(root->right, values);
}
vector<int> preorderTraversal2(TreeNode *root)
{
    vector<int> values;
    preOrder(root, values);
    return values;
}
vector<int> preorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> values;
    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        while (root)
        {
            values.push_back(root->val);
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        root = root->right;
    }
    return values;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> res = preorderTraversal(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;

    res = preorderTraversal2(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}