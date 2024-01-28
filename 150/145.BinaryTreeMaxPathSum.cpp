#include <iostream>
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

int findMaxPathSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int leftMax = max(0, findMaxPathSum(root->left, maxi));
    int rightMax = max(0, findMaxPathSum(root->right, maxi));

    maxi = max(maxi, leftMax + rightMax + root->val);
    return max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    // Function call
    cout << "Max path sum is " << maxPathSum(root);
    return 0;
}