#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Brute Force Approach (Recursive)
// Time Complexity: O(n)
// Space Complexity: O(n) on the stack (recursion)
int countNodes_BruteForce(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes_BruteForce(root->left) + countNodes_BruteForce(root->right);
}

// Level Order Traversal Approach (Iterative)
// Time Complexity: O(n)
// Space Complexity: O(n) for the queue
int countNodes_LevelOrder(TreeNode* root) {
    if (!root) return 0;
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        count++;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return count;
}

// Binary Search Approach
// Time Complexity: O(log^2 n)
// Space Complexity: O(1)
int countNodes_BinarySearch(TreeNode* root) {
    if (!root) return 0;
    int height_left = 0, height_right = 0;
    TreeNode* left = root, *right = root;
    // Calculate the height of the left subtree
    while (left) {
        height_left++;
        left = left->left;
    }
    // Calculate the height of the right subtree
    while (right) {
        height_right++;
        right = right->right;
    }
    // If the heights are equal, the tree is full and contains 2^h - 1 nodes
    if (height_left == height_right) {
        return (1 << height_left) - 1;
    }
    // If the heights are not equal, recursively count nodes in the left and right subtrees
    return 1 + countNodes_BinarySearch(root->left) + countNodes_BinarySearch(root->right);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Brute Force
    cout << "Number of nodes (Brute Force): " << countNodes_BruteForce(root) << endl;
    
    // Level Order Traversal
    cout << "Number of nodes (Level Order): " << countNodes_LevelOrder(root) << endl;
    
    // Binary Search
    cout << "Number of nodes (Binary Search): " << countNodes_BinarySearch(root) << endl;
    
    return 0;
}
