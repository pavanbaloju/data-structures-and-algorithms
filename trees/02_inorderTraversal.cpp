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

vector<int> inorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> values;
    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        values.push_back(root->val);
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

    vector<int> res = inorderTraversal(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}