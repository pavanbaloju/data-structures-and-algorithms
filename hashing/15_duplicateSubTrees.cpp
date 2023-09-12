#include <iostream>
#include <unordered_map>
#include <vector>

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

void addLeftChild(TreeNode *node, int val)
{
    TreeNode *leftChild = new TreeNode(val);
    node->left = leftChild;
}
void addRightChild(TreeNode *node, int val)
{
    TreeNode *rightChild = new TreeNode(val);
    node->right = rightChild;
}


string preOrderTraversal(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &map)
{
    if (!root)
    {
        return "N";
    }
    string s = to_string(root->val) + "," + preOrderTraversal(root->left, res, map) + "," + preOrderTraversal(root->right, res, map);
    if (map[s] == 1)
    {
        res.push_back(root);
    }
    map[s]++;
    return s;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> res;
    unordered_map<string, int> map;
    preOrderTraversal(root, res, map);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    addLeftChild(root, 2);
    addRightChild(root, 3);
    addLeftChild(root->left, 4);
    addLeftChild(root->right, 2);
    addRightChild(root->right, 4);
    addLeftChild(root->right->left, 4);
    vector<TreeNode *> res = findDuplicateSubtrees(root);
    for (TreeNode *t : res)
        cout << t->val << " ";
    return 0;
}