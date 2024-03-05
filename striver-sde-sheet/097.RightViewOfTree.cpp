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
// Given a binary tree, return the right view of the tree, i.e., the nodes visible from the right side when looking from the top.

// Intuition:
// Similar to the left view, the right view of a binary tree can be obtained using either a level order traversal or a recursive traversal.
// In a level order traversal, we iterate through each level of the tree and add the last node of each level to the result vector.
// Alternatively, a recursive approach can be used where we traverse the tree recursively, keeping track of the current level, and add the last node encountered at each level to the result vector.

// DSA Strategy:
// Level Order Traversal (Iterative) or Recursive Traversal with Level Tracking

// Approach (Iterative - Level Order Traversal):
// 1. Initialize an empty result vector to store the right view elements.
// 2. If the root is nullptr, return the empty result vector.
// 3. Create a queue to perform level order traversal and push the root node into the queue.
// 4. While the queue is not empty:
//    a. Get the number of nodes at the current level.
//    b. Iterate through all the nodes at the current level.
//    c. If it is the last node at the current level, add its value to the result vector.
//    d. Push the left and right children of the current node into the queue if they exist.
// 5. Return the result vector containing the right view elements.

// Approach (Recursive):
// 1. Define a utility function to perform a recursive traversal of the tree.
// 2. If the root is nullptr, return.
// 3. If the size of the result vector is equal to the current level, add the value of the root to the result vector.
// 4. Recursively call the right child with increased level.
// 5. Recursively call the left child with increased level.
// 6. Call the utility function with the root node and level 0 to get the right view.
// 7. Return the result vector containing the right view elements.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
//   Both approaches visit each node exactly once.
// Space Complexity: O(n) - for both approaches.
//   The iterative approach uses a queue to store nodes at each level.
//   The recursive approach uses the function call stack for recursion.

// Utility function to perform Recursive Traversal and obtain the right view of a binary tree
void rightViewUtil(TreeNode *root, int level, vector<int> &result)
{
    if (root == nullptr) // If the root is null, return
        return;

    if (result.size() == level) // If the size of the result vector is equal to the current level, add the value of the root to the result vector
        result.push_back(root->val);

    rightViewUtil(root->right, level + 1, result); // Recursively call the right child with increased level
    rightViewUtil(root->left, level + 1, result);  // Recursively call the left child with increased level
}

// Function to perform Recursive Traversal and obtain the right view of a binary tree
vector<int> rightViewRecursive(TreeNode *root)
{
    vector<int> result;             // Create a vector to store the right view elements
    rightViewUtil(root, 0, result); // Call the utility function to get the right view
    return result;                  // Return the right view vector
}

// Function to perform Level Order Traversal and obtain the right view of a binary tree
vector<int> rightView(TreeNode *root)
{
    vector<int> result; // Create a vector to store the right view elements

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

            if (i == n) // If it is the last node at the current level, add its value to the result vector
                result.push_back(temp->val);

            if (temp->left != nullptr) // If the left child exists, push it into the queue
                q.push(temp->left);
            if (temp->right != nullptr) // If the right child exists, push it into the queue
                q.push(temp->right);
        }
    }

    return result; // Return the right view vector
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

    // Get the right view of the tree using both approaches and print the result
    vector<int> result = rightView(root);
    cout << "Right View (Iterative): ";
    printVector(result);

    result = rightViewRecursive(root);
    cout << "Right View (Recursive): ";
    printVector(result);

    return 0;
}
