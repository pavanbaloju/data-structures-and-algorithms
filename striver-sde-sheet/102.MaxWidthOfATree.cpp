#include <iostream>
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
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.

// Intuition:
// We can use level order traversal (BFS) to determine the width of each level.
// During level order traversal, we track the leftmost and rightmost indices of each level.
// The maximum width is then calculated by subtracting the leftmost index from the rightmost index of each level.

// DSA Strategy:
// We will use a queue to perform level order traversal.
// Each element in the queue is a pair consisting of a TreeNode pointer and its corresponding index.
// We track the leftmost and rightmost indices of each level while traversing the tree.
// The maximum width is updated at each level.

// Approach:
// 1. Initialize a variable maxWidth to store the maximum width of the tree (initialized to 0).
// 2. Initialize a queue of pairs, where each pair consists of a TreeNode pointer and its corresponding index.
// 3. Enqueue the root node along with its index (0) into the queue.
// 4. While the queue is not empty, do the following:
//    a. Get the size of the queue (levelSize).
//    b. Initialize leftIndex and rightIndex to track the leftmost and rightmost indices of the current level.
//    c. Iterate through all the nodes at the current level:
//       i. Dequeue a node and its index from the queue.
//       ii. Update the rightmost index.
//       iii. Enqueue the left child with index 2*currentIndex if it exists.
//       iv. Enqueue the right child with index 2*currentIndex+1 if it exists.
//    d. Update the maximum width by subtracting the leftmost index from the rightmost index and adding 1 (to include both indices).
// 5. Return the maximum width.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(w), where w is the maximum width of the binary tree (maximum number of nodes at any level).

uint32_t maxWidthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    int maxWidth = 0;
    queue<pair<TreeNode *, uint32_t>> q; // Pair of node and its index
    q.push({root, 0});

    while (!q.empty())
    {
        int levelSize = q.size();
        uint32_t leftIndex = q.front().second; // Leftmost index of current level
        uint32_t rightIndex = leftIndex;       // Rightmost index of current level

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front().first;
            uint32_t currentIndex = q.front().second;
            q.pop();

            // Update rightmost index
            rightIndex = currentIndex;

            // Enqueue left child if present
            if (node->left)
                q.push({node->left, 2 * currentIndex});

            // Enqueue right child if present
            if (node->right)
                q.push({node->right, 2 * currentIndex + 1});
        }

        // Update maximum width
        maxWidth = max(maxWidth, static_cast<int>(rightIndex - leftIndex + 1));
    }

    return maxWidth;
}

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "Maximum width of the binary tree: " << maxWidthOfBinaryTree(root) << endl;

    return 0;
}
