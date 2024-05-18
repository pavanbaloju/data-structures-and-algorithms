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

// Function to perform post-order traversal using a stack
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> stk;
    stack<TreeNode *> output; // This will store nodes in post-order
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode *current = stk.top();
        stk.pop();
        output.push(current);

        if (current->left != nullptr)
        {
            stk.push(current->left);
        }
        if (current->right != nullptr)
        {
            stk.push(current->right);
        }
    }

    // Output the nodes in post-order
    while (!output.empty())
    {
        cout << output.top()->val << " ";
        output.pop();
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

// Main function to demonstrate the post-order traversal
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

    cout << "Post-order traversal of the binary tree is: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
