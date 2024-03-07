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
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
// Zigzag level order traversal is achieved by alternating the direction of traversal between left to right and right to left.

// Intuition:
// We can perform a level order traversal of the binary tree using a queue.
// To achieve zigzag traversal, we maintain a flag to indicate the direction of traversal.
// For each level, if the direction is left to right, we add nodes' values from left to right; otherwise, we add nodes' values from right to left.

// DSA Strategy:
// We use a queue to perform level order traversal and a flag to indicate the direction of traversal.
// At each level, we process nodes in the queue and toggle the direction for the next level.
// We store values at each level in a vector and push it to the result vector.

// Approach:
// 1. If the root is null, return an empty vector.
// 2. Initialize an empty vector 'values' to store the zigzag level order traversal.
// 3. Initialize an empty vector 'level' to store values at each level.
// 4. Initialize a queue 'q' to perform level order traversal.
// 5. Push the root node into the queue.
// 6. Initialize a boolean flag 'leftToRight' to true to indicate the direction of traversal.
// 7. While the queue is not empty:
//      a. Get the number of nodes 'k' at the current level.
//      b. Process all nodes at the current level:
//          i.   Pop a node 'node' from the front of the queue.
//          ii.  If 'leftToRight' is true, add 'node->val' to 'level'; otherwise, insert 'node->val' at the beginning of 'level'.
//          iii. If 'node' has a left child, push it into the queue.
//          iv.  If 'node' has a right child, push it into the queue.
//      c. Add 'level' to 'values'.
//      d. Clear 'level' for the next level.
//      e. Toggle the direction 'leftToRight' for the next level.
// 8. Return 'values'.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n), where n is the number of nodes in the binary tree (worst-case scenario when the binary tree is a complete binary tree).

// Function to get the zigzag level order traversal of a binary tree optimized
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root) // If the root is null, return an empty vector
        return {};

    vector<vector<int>> values; // Vector to store the zigzag level order traversal
    vector<int> level; // Vector to store the values at each level
    queue<TreeNode *> q; // Queue to perform level order traversal

    q.push(root); // Push the root node into the queue
    bool leftToRight = true; // Flag to indicate the direction of traversal

    while (!q.empty()) // Perform level order traversal until the queue is empty
    {
        int k = q.size(); // Get the number of nodes at the current level

        while (k--) // Process all the nodes at the current level
        {
            TreeNode *node = q.front(); // Get the front node from the queue
            q.pop(); // Remove the front node from the queue

            if (leftToRight) // If the direction is left to right
            {
                level.push_back(node->val); // Add the node value to the level vector
            }
            else // If the direction is right to left
            {
                level.insert(level.begin(), node->val); // Insert the node value at the beginning of the level vector
            }

            if (node->left) // If the node has a left child, push it into the queue
                q.push(node->left);
            if (node->right) // If the node has a right child, push it into the queue
                q.push(node->right);
        }

        values.push_back(level); // Add the level vector to the values vector
        level.clear(); // Clear the level vector for the next level
        leftToRight = !leftToRight; // Toggle the direction for the next level
    }

    return values; // Return the zigzag level order traversal
}

int main()
{
    // Example:
    // Construct the following binary tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // The zigzag level order traversal of the binary tree is:
    // 1
    // 3 2
    // 4 5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> res = zigzagLevelOrder(root);
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}