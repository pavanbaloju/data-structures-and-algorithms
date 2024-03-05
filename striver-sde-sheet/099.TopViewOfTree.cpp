#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
// Given a binary tree, return the top view of the tree, i.e., the nodes visible from the top when looking from the top.

// Intuition:
// The top view of a binary tree can be obtained using either an iterative approach with level order traversal or a recursive approach with level and horizontal distance tracking.
// In the iterative approach, we perform a level order traversal and maintain a map to store the horizontal distance and the value of the nodes. We update the map with the value of the nodes encountered at each horizontal distance.
// Alternatively, in the recursive approach, we traverse the tree recursively, keeping track of the horizontal distance and level of each node. We store the topmost node encountered at each horizontal distance in a map.

// DSA Strategy:
// Level Order Traversal (Iterative) or Recursive Traversal with Level and Horizontal Distance Tracking

// Approach (Iterative - Level Order Traversal):
// 1. Initialize an empty result vector to store the top view elements.
// 2. If the root is nullptr, return the empty result vector.
// 3. Create a map to store the horizontal distance and the value of the nodes.
// 4. Create a queue to perform level order traversal and push the root node and its horizontal distance into the queue.
// 5. While the queue is not empty:
//    a. Get the front node and its horizontal distance from the queue.
//    b. Update the map with the value of the node at the current horizontal distance if it is not present in the map.
//    c. Push the left child into the queue with a decreased horizontal distance.
//    d. Push the right child into the queue with an increased horizontal distance.
// 6. Iterate through the map and add the top view elements to the result vector.
// 7. Return the result vector containing the top view elements.

// Approach (Recursive):
// 1. Define a utility function to perform a recursive traversal of the tree.
// 2. If the root is nullptr, return.
// 3. If the horizontal distance is not present in the map or the current level is less than the level stored in the map, update the value of the horizontal distance in the map.
// 4. Recursively call the left child with decreased horizontal distance and increased level.
// 5. Recursively call the right child with increased horizontal distance and increased level.
// 6. Call the utility function with the root node, horizontal distance 0, and level 0 to get the top view.
// 7. Iterate through the map and add the top view elements to the result vector.
// 8. Return the result vector containing the top view elements.

// Time Complexity: O(n) - where n is the number of nodes in the tree.
//   Both approaches visit each node exactly once.
// Space Complexity: O(n) - for both approaches.
//   The iterative approach uses a queue to store nodes at each level, and a map to store the horizontal distance and node values.
//   The recursive approach uses the function call stack for recursion, and a map to store the horizontal distance and node values.

// Utility function to perform Recursive Traversal and obtain the top view of a binary tree
void topViewUtil(TreeNode *root, int hDist, int level, map<int, pair<int, int>> &m)
{
    if (root == nullptr) // If the root is null, return
        return;

    if (m.find(hDist) == m.end() || level < m[hDist].second) // If the horizontal distance is not present in the map or the current level is less than the level stored in the map
        m[hDist] = {root->val, level};                       // Update the value of the horizontal distance in the map

    topViewUtil(root->left, hDist - 1, level + 1, m);  // Recursively call the left child with decreased horizontal distance and increased level
    topViewUtil(root->right, hDist + 1, level + 1, m); // Recursively call the right child with increased horizontal distance and increased level
}

// Function to get the top view of a binary tree using a recursive approach
vector<int> topViewRecursive(TreeNode *root)
{
    vector<int> result;         // Create a vector to store the top view elements
    map<int, pair<int, int>> m; // Create a map to store the horizontal distance and the value of the nodes
    topViewUtil(root, 0, 0, m); // Call the utility function to get the top view
    for (auto it : m)           // Iterate through the map and add the top view elements to the result vector
        result.push_back(it.second.first);
    return result; // Return the top view vector
}

// Function to get the top view of a binary tree using an iterative approach
vector<int> topView(TreeNode *root)
{
    vector<int> result; // Create a vector to store the top view elements

    if (root == nullptr) // If the root is null, return the empty result vector
        return result;

    map<int, int> m;                // Create a map to store the horizontal distance and the value of the nodes
    queue<pair<TreeNode *, int>> q; // Create a queue to perform level order traversal
    q.push({root, 0});              // Push the root node and its horizontal distance into the queue

    while (!q.empty()) // Perform level order traversal until the queue is empty
    {
        TreeNode *temp = q.front().first; // Get the front node of the queue
        int hDist = q.front().second;     // Get the horizontal distance of the front node
        q.pop();                          // Remove the front node from the queue

        if (m.find(hDist) == m.end()) // If the horizontal distance is not present in the map
            m[hDist] = temp->val;     // Update the value of the horizontal distance in the map

        if (temp->left != nullptr) // If the left child exists, push it into the queue with a decreased horizontal distance
            q.push({temp->left, hDist - 1});
        if (temp->right != nullptr) // If the right child exists, push it into the queue with an increased horizontal distance
            q.push({temp->right, hDist + 1});
    }

    for (auto it : m) // Iterate through the map and add the top view elements to the result vector
        result.push_back(it.second);

    return result; // Return the top view vector
}

// Function to print a vector of integers
void printVector(vector<int> &v)
{
    for (int i : v) // Iterate through the vector and print the elements
        cout << i << " ";
    cout << endl; // Print a newline
}

int main()
{
    TreeNode *root = new TreeNode(1); // Create a binary tree
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    // Get the top view of the binary tree using both approaches and print the result
    vector<int> result1 = topViewRecursive(root); // Recursive Approach
    vector<int> result2 = topView(root);          // Iterative Approach

    cout << "Top View (Recursive): ";
    printVector(result1); // Print the top view elements obtained using the recursive approach

    cout << "Top View (Iterative): ";
    printVector(result2); // Print the top view elements obtained using the iterative approach

    return 0; // Return 0 to indicate the successful completion of the program
}
