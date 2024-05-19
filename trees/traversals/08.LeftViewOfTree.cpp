#include <iostream>
#include <vector>
#include <queue>
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
// Given a binary tree, return the left view of the tree, i.e., the nodes visible from the left side when looking from the top.

// Intuition:
// The left view of a binary tree can be obtained by performing either a level order traversal or a recursive traversal of the tree.
// In a level order traversal, we iterate through each level of the tree and add the first node of each level to the result vector.
// Alternatively, a recursive approach can be used where we traverse the tree recursively, keeping track of the current level, and add the first node encountered at each level to the result vector.

// DSA Strategy:
// Level Order Traversal (Iterative) or Recursive Traversal with Level Tracking

// Approach (Iterative - Level Order Traversal):
// 1. Initialize an empty result vector to store the left view elements.
// 2. If the root is nullptr, return the empty result vector.
// 3. Create a queue to perform level order traversal and push the root node into the queue.
// 4. While the queue is not empty:
//    a. Get the number of nodes at the current level.
//    b. Iterate through all the nodes at the current level.
//    c. If it is the first node at the current level, add its value to the result vector.
//    d. Push the left and right children of the current node into the queue if they exist.
// 5. Return the result vector containing the left view elements.

// Approach (Recursive):
// 1. Define a utility function to perform a recursive traversal of the tree.
// 2. If the root is nullptr, return.
// 3. If the size of the result vector is equal to the current level, add the value of the root to the result vector.
// 4. Recursively call the left child with increased level.
// 5. Recursively call the right child with increased level.
// 6. Call the utility function with the root node and level 0 to get the left view.
// 7. Return the result vector containing the left view elements.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
//   Both approaches visit each node exactly once.
// Space Complexity: O(n) - for both approaches.
//   The iterative approach uses a queue to store nodes at each level.
//   The recursive approach uses the function call stack for recursion.

// Function to perform Level Order Traversal and obtain the left view of a binary tree
vector<int> leftView(TreeNode *root)
{
    vector<int> result; // Create a vector to store the left view elements

    if (root == nullptr) // If the root is null, return the empty result vector
        return result;

    queue<TreeNode *> q; // Create a queue to perform level order traversal
    q.push(root);        // Push the root node into the queue

    while (!q.empty()) // Perform level order traversal until the queue is empty
    {
        int n = q.size();            // Get the number of nodes at the current level
        for (int i = 1; i <= n; i++) // Iterate through all the nodes at the current level
        {
            TreeNode *temp = q.front(); // Get the front node of the queue
            q.pop();                    // Remove the front node from the queue

            if (i == 1) // If it is the first node at the current level, add its value to the result vector
                result.push_back(temp->val);

            if (temp->left != nullptr) // If the left child exists, push it into the queue
                q.push(temp->left);
            if (temp->right != nullptr) // If the right child exists, push it into the queue
                q.push(temp->right);
        }
    }

    return result; // Return the left view vector
}

// Utility function to perform Recursive Traversal and obtain the left view of a binary tree
void leftViewUtil(TreeNode *root, int level, vector<int> &result)
{
    if (root == nullptr) // If the root is null, return
        return;

    if (result.size() == level) // If the size of the result vector is equal to the current level, add the value of the root to the result vector
        result.push_back(root->val);

    leftViewUtil(root->left, level + 1, result);  // Recursively call the left child with increased level
    leftViewUtil(root->right, level + 1, result); // Recursively call the right child with increased level
}

// Function to perform Recursive Traversal and obtain the left view of a binary tree
vector<int> leftViewRecursive(TreeNode *root)
{
    vector<int> result;            // Create a vector to store the left view elements
    leftViewUtil(root, 0, result); // Call the utility function to get the left view
    return result;                 // Return the left view vector
}

// Function to print a vector of integers
void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    // Get the left view of the tree using both approaches and print the result
    vector<int> result = leftView(root);
    cout << "Left View (Iterative): ";
    printVector(result);

    result = leftViewRecursive(root);
    cout << "Left View (Recursive): ";
    printVector(result);

    return 0;
}
