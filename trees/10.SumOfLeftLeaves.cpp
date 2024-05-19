#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check if a node is a leaf
bool isLeaf(TreeNode *node)
{
    return (node != nullptr) && (node->left == nullptr) && (node->right == nullptr);
}

// Function to calculate the sum of all left leaves
int sumOfLeftLeaves(TreeNode *root)
{
    // Base case: if the tree is empty, return 0
    if (root == nullptr)
    {
        return 0;
    }

    int sum = 0;

    // If the left child is a leaf, add its value to the sum
    if (isLeaf(root->left))
    {
        sum += root->left->val;
    }
    else
    {
        // If the left child is not a leaf, recurse on the left subtree
        sum += sumOfLeftLeaves(root->left);
    }

    // Recurse on the right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate the sum of all left leaves
    int result = sumOfLeftLeaves(root);
    cout << "Sum of all left leaves: " << result << endl;

    return 0;
}
