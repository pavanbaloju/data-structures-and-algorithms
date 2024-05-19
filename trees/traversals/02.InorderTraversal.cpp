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
// Given a binary tree, perform inorder traversal iteratively and recursively.

// Intuition:
// Inorder traversal visits nodes in the order: left, root, right.
// We can implement it using both iterative and recursive approaches.

// DSA Strategy:
// Stack (for iterative approach) and recursion (for recursive approach).

// Approach (Iterative):
// 1. Initialize an empty stack to perform iterative inorder traversal.
// 2. Traverse the tree until the current node is nullptr and the stack is empty.
// 3. While traversing, push all left children of the current node onto the stack.
// 4. Pop the top node from the stack.
// 5. Store the value of the popped node.
// 6. Move to the right child of the popped node.
// 7. Repeat steps 3-6 until the stack is empty and all nodes are visited.
// 8. Return the vector containing the inorder traversal values.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space).

// Function to perform iterative inorder traversal of a binary tree
vector<int> inorderTraversal(TreeNode *root)
{
    // Initialize an empty vector to store the values of the nodes in inorder traversal order
    vector<int> values;
    // Initialize a stack to perform iterative inorder traversal
    stack<TreeNode *> st;

    // Traverse the tree until the current node is nullptr and the stack is empty
    while (root || !st.empty())
    {
        // Traverse all the left children of the current node and push them onto the stack
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        // Pop the top node from the stack
        root = st.top();
        st.pop();
        // Store the value of the popped node
        values.push_back(root->val);
        // Move to the right child of the popped node
        root = root->right;
    }
    // Return the vector containing the inorder traversal values
    return values;
}

// Approach (Recursive):
// 1. Implement a recursive function to perform an inorder traversal.
// 2. Base case: If the root is nullptr, return.
// 3. Recursively traverse the left subtree.
// 4. Store the value of the current node.
// 5. Recursively traverse the right subtree.
// 6. Return the vector containing inorder traversal values.
//
// Time Complexity: O(n) - where n is the number of nodes in the tree.
// Space Complexity: O(h) - where h is the height of the tree (stack space for the recursive function calls).

// Function to perform recursive inorder traversal of a binary tree
void inorderRecursive(TreeNode *root, vector<int> &values)
{
    // Base case: If the root is nullptr, return
    if (root == nullptr)
    {
        return;
    }

    // Recursively traverse the left subtree
    inorderRecursive(root->left, values);
    // Store the value of the current node
    values.push_back(root->val);
    // Recursively traverse the right subtree
    inorderRecursive(root->right, values);
}

// Function to perform recursive inorder traversal of a binary tree and return the result
vector<int> inorderTraversalRecursive(TreeNode *root)
{
    // Initialize an empty vector to store the values of the nodes in inorder traversal order
    vector<int> values;
    // Perform recursive inorder traversal starting from the root node
    inorderRecursive(root, values);
    // Return the vector containing the inorder traversal values
    return values;
}

// Function to print the elements of a vector
void printVector(vector<int> &res)
{
    for (int v : res)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Perform iterative inorder traversal and print the result
    cout << "Iterative Inorder Traversal: ";
    vector<int> res = inorderTraversal(root);
    printVector(res);

    // Perform recursive inorder traversal and print the result
    cout << "Recursive Inorder Traversal: ";
    res = inorderTraversalRecursive(root);
    printVector(res);

    return 0;
}
