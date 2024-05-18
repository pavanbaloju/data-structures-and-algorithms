#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal using a stack
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> stk; // Stack to keep track of nodes
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode *current = stk.top();
        stk.pop();
        cout << current->val << " "; // Visit the node

        // Push right child first so that left child is processed first
        if (current->right != nullptr)
        {
            stk.push(current->right);
        }
        if (current->left != nullptr)
        {
            stk.push(current->left);
        }
    }
}

// Helper function to create a new node
TreeNode *newNode(int data)
{
    TreeNode *node = new TreeNode(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Main function to demonstrate the pre-order traversal
int main()
{
    // Constructing the binary tree
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "Pre-order traversal of the binary tree is: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
