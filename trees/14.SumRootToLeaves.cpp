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

// Helper function to perform DFS and calculate the sum of root-to-leaf numbers
void sumRootToLeafHelper(TreeNode *node, int currentNumber, int &totalSum)
{
    if (node == nullptr)
    {
        return;
    }

    // Update the current number by appending the current node's value
    currentNumber = currentNumber * 10 + node->val;

    // If the current node is a leaf, add the current number to the total sum
    if (node->left == nullptr && node->right == nullptr)
    {
        totalSum += currentNumber;
        return;
    }

    // Recursively call for the left and right children
    sumRootToLeafHelper(node->left, currentNumber, totalSum);
    sumRootToLeafHelper(node->right, currentNumber, totalSum);
}

// Main function to calculate the sum of all root-to-leaf numbers
int sumNumbers(TreeNode *root)
{
    int totalSum = 0;
    sumRootToLeafHelper(root, 0, totalSum);
    return totalSum;
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Calculate the sum of all root-to-leaf numbers
    int result = sumNumbers(root);
    cout << "Sum of all root-to-leaf numbers: " << result << endl;

    return 0;
}