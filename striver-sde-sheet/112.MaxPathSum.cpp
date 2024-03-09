#include <iostream>
#include <vector>
using namespace std;

// Definition of a TreeNode structure representing a node in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Add problem statement
// Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree and may not pass through the root.

// Add Intuition
// To find the maximum path sum in a binary tree, we can use a recursive approach where for each node, we compute the maximum path sum that includes that node (i.e., the path may start from that node and go downwards) and update the overall maximum path sum accordingly. We return the maximum path sum obtained.

// Add the DSA strategy used to solve the problem
// We use a recursive approach to compute the maximum path sum for each node in the binary tree. At each node, we calculate the maximum path sum that includes the current node by considering three cases:
// 1. The path only includes the current node.
// 2. The path includes the current node and extends to the left subtree.
// 3. The path includes the current node and extends to the right subtree.
// We update the overall maximum path sum by considering the sum of these cases. We return the maximum path sum obtained.

// Add approach: clearly explain the algorithm step by step
// 1. Define a helper function maxPathSumHelper that takes a TreeNode pointer root and a reference to an integer maxSum.
// 2. In the helper function, if the current node is null, return 0.
// 3. Recursively compute the maximum path sum for the left subtree and the right subtree by calling the helper function on the left child and the right child of the current node.
// 4. Update the maximum path sum by considering the current node as the root of the path. The maximum path sum that includes the current node is the sum of the current node's value, the maximum path sum for the left subtree (if positive), and the maximum path sum for the right subtree (if positive).
// 5. Return the maximum path sum that can be extended from the current node. If the sum is negative, return 0 because it does not contribute to any path sum.
// 6. Define the main function maxPathSum that takes a TreeNode pointer root and returns an integer.
// 7. Initialize the maximum path sum maxSum to INT_MIN.
// 8. Call the helper function maxPathSumHelper with the root of the binary tree and maxSum.
// 9. Return the maximum path sum maxSum.

// Add time and space complexity
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree (the maximum depth of the function call stack in the recursive approach).

// helper function to compute the maximum path sum for a node
int maxPathSumHelper(TreeNode *root, int &maxSum)
{
    // Base case: if the current node is null, return 0
    if (!root)
        return 0;

    // Recursively compute the maximum path sum for the left and right subtrees
    int leftSum = maxPathSumHelper(root->left, maxSum);
    int rightSum = maxPathSumHelper(root->right, maxSum);

    // Update the maximum path sum by considering the current node as the root of the path
    maxSum = max(maxSum, root->val + leftSum + rightSum);

    // Return the maximum path sum that can be extended from the current node
    return max(0, root->val + max(leftSum, rightSum));
}

// Function to get the maximum path sum in a binary tree
int maxPathSum(TreeNode *root)
{
    // Initialize the maximum path sum to the minimum integer value
    int maxSum = INT_MIN;

    // Compute the maximum path sum for the entire tree
    maxPathSumHelper(root, maxSum);

    // Return the maximum path sum
    return maxSum;
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    cout << maxPathSum(root) << endl; // Output: 42
    return 0;
}
