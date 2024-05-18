#include <iostream>
#include <vector>
#include <cmath> // For abs function

using namespace std;

// Problem Statement:
// Given a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.
// In one move, we may choose two adjacent nodes and move one coin from one node to the other.
// The move may be from parent to child, or from child to parent.
// Return the number of moves required to make every node have exactly one coin.

// Intuition:
// The problem can be solved by calculating the balance of coins for each node.
// The balance is the difference between the total coins in the subtree rooted at the node and the number of nodes in that subtree.
// The number of moves required to balance each node is the sum of absolute values of the balances of its children.

// DSA Strategy/Pattern: Depth-First Search (DFS)

// Approach and Time Complexity:
// Approach 1: Depth-First Search
// - Perform a DFS traversal to calculate the balance of coins for each node.
// - The balance of a node is the total number of coins in its subtree minus the number of nodes in the subtree.
// - The number of moves is the sum of absolute values of the balances of the left and right subtrees of each node.
// Time Complexity: O(N) - where N is the number of nodes in the tree, as each node is visited once.
// Space Complexity: O(H) - where H is the height of the tree, due to the recursion stack.

struct TreeNode
{
    int val;                                             // Value of the node (number of coins)
    TreeNode *left;                                      // Pointer to the left child
    TreeNode *right;                                     // Pointer to the right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor initializing the node value and children
};

class Solution
{
public:
    // Main function to distribute coins
    int distributeCoins(TreeNode *root)
    {
        int moves = 0;    // Variable to count the number of moves
        dfs(root, moves); // Start the depth-first search from the root
        return moves;     // Return the total number of moves
    }

private:
    // Helper function to perform depth-first search
    int dfs(TreeNode *node, int &moves)
    {
        if (!node) // If the node is NULL, return 0 (base case)
            return 0;

        // Recursively get the balance from the left and right subtrees
        int left_balance = dfs(node->left, moves);
        int right_balance = dfs(node->right, moves);

        // Current node's balance: total coins in the subtree - nodes in the subtree
        int balance = node->val + left_balance + right_balance - 1;

        // Update the number of moves with the absolute values of left and right balances
        moves += abs(left_balance) + abs(right_balance);

        // Return the current node's balance to its parent
        return balance;
    }
};

int main()
{
    // Example usage:
    // Constructing the tree:
    //       3
    //      / \
    //     0   0
    //    /
    //   0
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(0);

    Solution sol;
    // Print the minimum number of moves required to distribute the coins
    cout << "Approach: Depth-First Search" << endl;
    cout << "Minimum number of moves: " << sol.distributeCoins(root) << endl;

    // Clean up the tree nodes to free memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
