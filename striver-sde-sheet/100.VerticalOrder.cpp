#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> // for sort
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
// Given a binary tree, return the vertical order traversal of its nodes' values.
// For each node at position (row, col) in the tree, its value will be appended to the vector at that position.

// Intuition:
// To perform vertical order traversal, we can use either BFS (Level Order Traversal) or DFS (Preorder Traversal) approach.
// We will maintain a map where the key represents the horizontal distance and the value is a vector of node values at that distance.

// DSA Strategy:
// We will use a map to store the nodes based on their horizontal distance. For BFS approach, we will use a queue to perform level order traversal.
// For DFS approach, we will use recursion to traverse the tree.

// Approach (BFS):
// 1. Create a map to store the vertical order traversal where the key is the horizontal distance and the value is a vector of node values.
// 2. Perform level order traversal using a queue.
// 3. Keep track of the horizontal distance of each node.
// 4. For each node, add its value to the corresponding horizontal distance in the map.
// 5. Sort the values at each horizontal distance.
// 6. Finally, return the vertical order traversal.

// Time Complexity: O(n log n) due to sorting at each horizontal distance.
// Space Complexity: O(n) for storing the result and the queue.

vector<vector<int>> verticalOrder(TreeNode *root)
{
    vector<vector<int>> result; // Result vector to store the vertical order traversal

    if (root == nullptr) // Check if the root is null
        return result;

    map<int, vector<int>> m;        // Map to store the values of nodes based on their horizontal distance
    queue<pair<TreeNode *, int>> q; // Queue to perform level order traversal
    q.push({root, 0});              // Push the root node with horizontal distance 0 to the queue

    while (!q.empty()) // Perform level order traversal
    {
        TreeNode *temp = q.front().first; // Get the front node from the queue
        int hd = q.front().second;        // Get the horizontal distance of the front node
        q.pop();                          // Pop the front node from the queue

        m[hd].push_back(temp->val); // Add the value of the current node to the corresponding horizontal distance in the map

        if (temp->left != nullptr)         // If the left child exists
            q.push({temp->left, hd - 1});  // Push the left child to the queue with updated horizontal distance
        if (temp->right != nullptr)        // If the right child exists
            q.push({temp->right, hd + 1}); // Push the right child to the queue with updated horizontal distance
    }

    for (auto it : m) // Iterate over the map
    {
        sort(it.second.begin(), it.second.end()); // Sort the values at each horizontal distance
        result.push_back(it.second);              // Add the sorted values to the result vector
    }

    return result; // Return the vertical order traversal
}

// Approach (DFS):
// 1. Create a map to store the vertical order traversal where the key is the horizontal distance and the value is a map of vertical distance and node values.
// 2. Implement a utility function to perform DFS traversal of the tree.
// 3. For each node, add its value to the corresponding horizontal and vertical distances in the map.
// 4. Sort the values at each horizontal distance.
// 5. Finally, return the vertical order traversal.

// Time Complexity: O(n log n) due to sorting at each horizontal distance.
// Space Complexity: O(n) for storing the result and the map.

void verticalOrderUtil(TreeNode *root, int hd, int vd, map<int, map<int, vector<int>>> &m)
{
    if (root == nullptr) // Check if the root is null
        return;

    m[hd][vd].push_back(root->val); // Add the value of the current node to the corresponding horizontal and vertical distance in the map

    verticalOrderUtil(root->left, hd - 1, vd + 1, m);  // Recursively call the function for the left child with updated horizontal and vertical distances
    verticalOrderUtil(root->right, hd + 1, vd + 1, m); // Recursively call the function for the right child with updated horizontal and vertical distances
}

vector<vector<int>> verticalOrderRecursive(TreeNode *root)
{
    map<int, map<int, vector<int>>> m; // Map to store the values of nodes based on their horizontal and vertical distances
    verticalOrderUtil(root, 0, 0, m);  // Call the utility function to populate the map

    vector<vector<int>> result; // Result vector to store the vertical order traversal

    for (auto it : m) // Iterate over the map
    {
        vector<int> temp; // Temporary vector to store the values at each horizontal distance

        for (auto i : it.second) // Iterate over the map at each horizontal distance
        {
            sort(i.second.begin(), i.second.end());                    // Sort the values at each vertical distance
            temp.insert(temp.end(), i.second.begin(), i.second.end()); // Append the sorted values to the temporary vector
        }

        result.push_back(temp); // Add the temporary vector to the result vector
    }

    return result; // Return the vertical order traversal
}

// Function to print a vector of vectors of integers
void printVector(vector<vector<int>> &v)
{
    for (vector<int> i : v)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Vertical Order (BFS):" << endl;
    vector<vector<int>> result1 = verticalOrder(root);
    printVector(result1);

    cout << "Vertical Order (DFS):" << endl;
    vector<vector<int>> result2 = verticalOrderRecursive(root);
    printVector(result2);

    return 0;
}
