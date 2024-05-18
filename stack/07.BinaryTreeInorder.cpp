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

// Function to perform in-order traversal using a stack
void inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;    // Stack to keep track of nodes
    TreeNode *temp = root; // Pointer to traverse the tree

    while (temp || !st.empty())
    {
        // Reach the leftmost node of the current node
        while (temp)
        {
            st.push(temp);       // Place pointer to a tree node on the stack
            temp = temp->left; // Move to the left child
        }

        // Current must be nullptr at this point
        temp = st.top(); // Node to be processed
        st.pop();
        cout << temp->val << " "; // Visit the node

        // We have visited the node and its left subtree. Now, move to the right subtree
        temp = temp->right;
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

// Main function to demonstrate the in-order traversal
int main()
{
    // Constructing the binary tree
    TreeNode *root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    cout << "In-order traversal of the binary tree is: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
