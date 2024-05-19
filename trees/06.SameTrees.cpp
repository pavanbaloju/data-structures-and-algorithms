#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if two binary trees are identical
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true; // If both trees are empty, they are identical
    if (p == NULL || q == NULL)
        return false; // If one tree is empty and the other is not, they are not identical
    if (p->val != q->val)
        return false;                                                        // If the values of the current nodes are different, the trees are not identical
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // Recursively check if the left and right subtrees are identical
}

int main()
{
    // Example:
    // Construct the following binary trees:
    // Tree 1:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // Tree 2:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // The trees are identical
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);
    q->left->right = new TreeNode(5);

    cout << (isSameTree(p, q) ? "The trees are identical" : "The trees are not identical") << endl;

    return 0;
}