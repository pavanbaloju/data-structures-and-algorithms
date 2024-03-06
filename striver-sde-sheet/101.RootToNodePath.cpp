#include <iostream>
#include <vector>
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
// Given a binary tree and a target value, find the path from the root node to the node containing the target value.

// Intuition:
// We can use a recursive approach to traverse the tree and find the path from the root to the target node.
// If the current node is the target node, we return true and add the current node to the path.
// If the target node is found in the left or right subtree, we return true and add the current node to the path.
// If the target node is not found in the subtree rooted at the current node, we backtrack and remove the current node from the path.

// DSA Strategy:
// We will use a recursive approach to traverse the tree and find the path from the root to the target node.
// We will maintain a vector to store the path from the root to the target node.
// The findPath function recursively searches for the target node in the tree and updates the path vector accordingly.

// Approach:
// 1. Implement a recursive function findPath that searches for the target node in the tree.
// 2. If the current node is null, return false.
// 3. Add the current node to the path vector.
// 4. If the current node is the target node, return true.
// 5. Recursively search for the target node in the left subtree.
// 6. If the target node is found in the left subtree, return true.
// 7. Recursively search for the target node in the right subtree.
// 8. If the target node is found in the right subtree, return true.
// 9. If the target node is not found in the subtree rooted at the current node, remove the current node from the path vector and return false.
// 10. Implement the rootToNodePath function that initializes an empty path vector and calls the findPath function to find the path from the root to the target node.
// 11. Print the path vector.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (space for the recursive call stack).

bool findPath(TreeNode *root, int target, vector<int> &path)
{
    if (!root)
        return false;

    // Add current node to the path
    path.push_back(root->val);

    // If current node is the target, return true
    if (root->val == target)
        return true;

    // Search in left subtree
    if (findPath(root->left, target, path))
        return true;

    // Search in right subtree
    if (findPath(root->right, target, path))
        return true;

    // If target not found, remove current node from path
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode *root, int target)
{
    vector<int> path;
    findPath(root, target, path);
    return path;
}

// Function to print the path
void printPath(const vector<int> &path)
{
    for (int val : path)
    {
        cout << val << " ";
    }
    cout << endl;
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

    int target = 5;
    vector<int> path = rootToNodePath(root, target);

    cout << "Path from root to node " << target << ": ";
    printPath(path);

    return 0;
}
