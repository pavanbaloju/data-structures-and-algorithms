#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of a binary tree node
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
// Given a binary tree, perform postorder traversal iteratively and recursively.

// Intuition:
// Postorder traversal visits nodes in the order: left, right, root.
// We can implement it using both iterative and recursive approaches.

// DSA Strategy:
// Stack (for iterative approach) and recursion (for recursive approach).

// Approach (Iterative):
// 1. Initialize an empty vector to store the values of the nodes in postorder traversal order.
// 2. Initialize a stack to perform iterative postorder traversal.
// 3. Iterate through the tree using the stack until the current node is nullptr and the stack is empty.
// 4. While traversing, traverse all left subtrees and push nodes onto the stack.
// 5. When reaching the leftmost node, check if the right subtree exists and has not been traversed.
// 6. If the right subtree exists and has not been traversed, traverse the right subtree.
// 7. Otherwise, store the value of the current node, mark it as visited, and pop it from the stack.
// 8. Repeat steps 3-7 until the stack is empty and all nodes are visited.
// 9. Return the vector containing the postorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space).

// Function to perform iterative postorder traversal of a binary tree
vector<int> postorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> values;
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;

    // Iterate through the tree using a stack
    while (root || !st.empty())
    {
        // Traverse left subtrees and push nodes onto the stack
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        TreeNode *node = st.top();
        // Check if the right subtree exists and has not been traversed
        if (node->right && node->right != prev)
        {
            // Traverse the right subtree
            root = node->right;
        }
        else
        {
            // Store the value of the current node
            values.push_back(node->val);
            // Mark the current node as visited
            prev = node;
            // Pop the node from the stack
            st.pop();
        }
    }
    return values;
}

// Approach (Recursive):
// 1. Implement a recursive function to perform a postorder traversal.
// 2. Base case: If the root is nullptr, return.
// 3. Recursively traverse the left subtree.
// 4. Recursively traverse the right subtree.
// 5. Store the value of the current node.
// 6. Return the vector containing postorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space for the recursive function calls).

// Function to perform recursive postorder traversal of a binary tree
void postorderRecursive(TreeNode *root, vector<int> &values)
{
    if (!root)
        return;

    // Recursively traverse the left subtree
    postorderRecursive(root->left, values);
    // Recursively traverse the right subtree
    postorderRecursive(root->right, values);
    // Store the value of the current node
    values.push_back(root->val);
}

// Function to perform recursive postorder traversal of a binary tree and return the result
vector<int> postorderTraversalRecursive(TreeNode *root)
{
    vector<int> values;
    // Perform recursive postorder traversal starting from the root node
    postorderRecursive(root, values);
    // Return the vector containing the postorder traversal values
    return values;
}

// Function to print a vector of integers
void printVector(vector<int> &res)
{
    for (int v : res)
        cout << v << " ";
    cout << endl;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Perform iterative postorder traversal and print the result
    cout << "Iterative Postorder Traversal: ";
    vector<int> res = postorderTraversal(root);
    printVector(res);

    // Perform recursive postorder traversal and print the result
    cout << "Recursive Postorder Traversal: ";
    res = postorderTraversalRecursive(root);
    printVector(res);

    return 0;
}
