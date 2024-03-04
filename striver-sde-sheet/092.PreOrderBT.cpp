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
// Problem Statement:
// Given a binary tree, perform preorder traversal iteratively and recursively.

// Intuition:
// Preorder traversal visits nodes in the order: root, left, right.
// We can implement it using both iterative and recursive approaches.

// DSA Strategy:
// Stack (for iterative approach) and recursion (for recursive approach).

// Approach (Iterative):
// 1. Initialize an empty vector to store the values of the nodes in preorder traversal order.
// 2. Initialize a stack to perform iterative preorder traversal.
// 3. Traverse the tree until the current node is nullptr and the stack is empty.
// 4. While traversing, store the value of the current node.
// 5. Push the right child of the current node onto the stack (if not nullptr).
// 6. Move to the left child of the current node.
// 7. Repeat steps 3-6 until the stack is empty and all nodes are visited.
// 8. Return the vector containing the preorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space).

// Function to perform iterative preorder traversal of a binary tree
vector<int> preorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    // Initialize an empty vector to store the values of the nodes in preorder traversal order
    vector<int> values;
    // Initialize a stack to perform iterative preorder traversal
    stack<TreeNode *> st;

    // Traverse the tree until the current node is nullptr and the stack is empty
    while (root || !st.empty())
    {
        // Traverse all the left children of the current node and push them onto the stack
        while (root)
        {
            // Store the value of the current node
            values.push_back(root->val);
            // Push the current node onto the stack
            st.push(root);
            // Move to the left child of the current node
            root = root->left;
        }
        // Pop the top node from the stack
        root = st.top();
        st.pop();
        // Move to the right child of the popped node
        root = root->right;
    }
    // Return the vector containing the preorder traversal values
    return values;
}

// Approach (Recursive):
// 1. Implement a recursive function to perform a preorder traversal.
// 2. Base case: If the root is nullptr, return.
// 3. Store the value of the current node.
// 4. Recursively traverse the left subtree.
// 5. Recursively traverse the right subtree.
// 6. Return the vector containing preorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space for the recursive function calls).

// Function to perform recursive preorder traversal of a binary tree
void preOrder(TreeNode *root, vector<int> &values)
{
    if (!root)
        return;

    // Store the value of the current node
    values.push_back(root->val);
    // Recursively traverse the left subtree
    preOrder(root->left, values);
    // Recursively traverse the right subtree
    preOrder(root->right, values);
}

// Function to perform recursive preorder traversal of a binary tree and return the result
vector<int> preorderTraversalRecursive(TreeNode *root)
{
    vector<int> values;
    // Perform recursive preorder traversal starting from the root node
    preOrder(root, values);
    // Return the vector containing the preorder traversal values
    return values;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Perform iterative preorder traversal and print the result
    cout << "Iterative Preorder Traversal: ";
    vector<int> res = preorderTraversal(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;

    // Perform recursive preorder traversal and print the result
    cout << "Recursive Preorder Traversal: ";
    res = preorderTraversalRecursive(root);
    for (int v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}
