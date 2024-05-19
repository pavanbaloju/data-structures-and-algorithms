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

// Function to evaluate a node of the binary tree
int evaluate(TreeNode *root)
{
    // Base case: if the root is a leaf node, return its value
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->val;
    }

    // Evaluate the left and right children recursively
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);

    // Apply the boolean operation based on the value of the root node
    if (root->val == 2)
    { // OR operation
        return left_val || right_val;
    }
    else if (root->val == 3)
    { // AND operation
        return left_val && right_val;
    }

    return -1; // Handle invalid node values (optional)
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);

    // Evaluate the root node
    int result = evaluate(root);
    cout << "Result: " << result << endl;

    return 0;
}
