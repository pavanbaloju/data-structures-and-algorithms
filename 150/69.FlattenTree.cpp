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

TreeNode *pre = nullptr;
// first solve right subtree and then left
// then update right and left child values. prev holds the node who got flattened last
void flatten(TreeNode *root)
{
    if (!root)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = pre;
    root->left = nullptr;
    pre = root;
}

void flattenIter(TreeNode *root)
{
    if (!root)
        return;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);

        if (!st.empty())
            cur->right = st.top();
        cur->left = nullptr;
    }
}

// using preorder, flatten left and attach to right, flatten right and append to already flattened left
void flattenPre(TreeNode *root)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
        return;

    // flattening the left subtree and attaching it to the right
    TreeNode *rightTree = root->right;
    flattenPre(root->left);
    root->right = root->left;
    root->left = NULL;

    // attaching the right subtree to the end of the flattened left subtree and repeating the process
    TreeNode *temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    flattenPre(rightTree);
    temp->right = rightTree;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    pre = nullptr;
    preOrder(root);
    cout << endl;

    flattenPre(root);
    preOrder(root);
    return 0;
}