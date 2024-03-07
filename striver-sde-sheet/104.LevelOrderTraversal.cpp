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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Problem Statement:
// Given the root of a binary tree, perform level order traversal and return the result as a vector of vectors,
// where each inner vector contains the values of nodes at each level of the tree.

// Intuition:
// Level order traversal visits nodes level by level, starting from the root.
// We can use a queue to keep track of the nodes at each level.
// At each level, we dequeue nodes from the queue, add their values to the current level vector,
// and enqueue their children (if any) for the next level.

// DSA Strategy:
// We use a queue to perform level order traversal.
// At each level, we dequeue nodes and enqueue their children (if any) for the next level.
// We maintain a vector of vectors to store the values of nodes at each level.

// Approach:
// 1. Initialize an empty vector of vectors called result to store the level order traversal.
// 2. If the root is NULL, return the empty result.
// 3. Initialize a queue to store the nodes for level order traversal.
// 4. Enqueue the root node into the queue.
// 5. While the queue is not empty, do the following:
//    a. Get the size of the queue to determine the number of nodes at the current level.
//    b. Initialize an empty vector called level to store the values of nodes at the current level.
//    c. Iterate from 0 to size of the queue:
//       i. Dequeue a node from the front of the queue.
//       ii. Add the value of the node to the level vector.
//       iii. Enqueue the left child (if exists) of the node into the queue.
//       iv. Enqueue the right child (if exists) of the node into the queue.
//    d. Add the level vector to the result vector.
// 6. Return the result vector containing the level order traversal.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n), where n is the number of nodes in the binary tree (used for queue and result vector).

// Function to perform level order traversal on a binary tree
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result; // Vector to store the level order traversal
    if (root == NULL)
        return result; // If the root is NULL, return an empty vector

    queue<TreeNode *> q; // Queue to store the nodes for level order traversal
    q.push(root);        // Push the root node into the queue

    while (!q.empty())
    {
        int n = q.size();  // Get the number of nodes at the current level
        vector<int> level; // Vector to store the nodes at the current level

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front(); // Get the front node from the queue
            q.pop();                    // Pop the front node from the queue
            level.push_back(node->val); // Add the node's value to the level vector

            if (node->left != NULL)
                q.push(node->left); // If the node has a left child, push it into the queue
            if (node->right != NULL)
                q.push(node->right); // If the node has a right child, push it into the queue
        }

        result.push_back(level); // Add the level vector to the result vector
    }

    return result; // Return the level order traversal
}

// Function to print the level order traversal
void printLevelOrder(vector<vector<int>> &result)
{
    for (vector<int> level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);
    printLevelOrder(result);

    return 0;
}
