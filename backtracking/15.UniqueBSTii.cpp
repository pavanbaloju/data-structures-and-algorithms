#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Problem Statement:
// Given an integer n, generate all structurally unique BST's (binary search trees) that 
// store values 1 ... n.

// Intuition:
// We can use a recursive approach with memoization to generate all structurally unique 
// BSTs that store values from 1 to n. We start by considering each number from 1 to n 
// as the root of a BST. For each root value, we recursively generate all possible left 
// subtrees and right subtrees. We combine each left subtree and right subtree with the 
// current root to form a BST. We use memoization to avoid recomputing the same subtree 
// structures.

// DSA Strategy/Pattern: Dynamic Programming, Recursion

// Approach:
// Explanation:
// 1. Define a recursive helper function 'generateTrees' that takes the start and end 
//    values of the range as parameters.
// 2. If start is greater than end, return a vector containing a single nullptr (base case).
// 3. Check if the result for the current range is memoized. If found, return the memoized result.
// 4. Initialize an empty vector 'result' to store the generated BSTs.
// 5. Iterate through each number from 'start' to 'end' as the root value of a BST.
//    - Recursively generate all possible left subtrees for values in the range (start, rootValue - 1).
//    - Recursively generate all possible right subtrees for values in the range (rootValue + 1, end).
//    - Combine each left subtree and right subtree with the current root to form a BST.
//    - Add the generated BST to the 'result' vector.
// 6. Memoize the result for the current range using a unique key.
// 7. Return the 'result' vector.
// 8. Define the main function 'generateTrees' that calls the helper function with n as the input.
// 9. Example usage: Create a sample input 'n' and call 'generateTrees' to generate unique BSTs.

// Time Complexity: O(n^2 * Cn), where n is the input integer and Cn is the nth Catalan number.
//                  Each call to 'generateTrees' explores each number as a root and generates 
//                  all possible subtrees, resulting in a total of Cn distinct BSTs.
//                  Computing each distinct BST has a time complexity of O(n).
// Space Complexity: O(n^2 * Cn) for the memoization map and storing all generated BSTs.

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

private:
    unordered_map<string, vector<TreeNode*>> memo;

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr}; // Base case: return a vector with one nullptr

        // Check if the result is memoized
        string key = to_string(start) + "-" + to_string(end);
        if (memo.find(key) != memo.end()) return memo[key];

        vector<TreeNode*> result;

        // Iterate through each number from start to end as the root
        for (int rootValue = start; rootValue <= end; ++rootValue) {
            // Generate all possible left subtrees
            vector<TreeNode*> leftSubtrees = generateTrees(start, rootValue - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightSubtrees = generateTrees(rootValue + 1, end);

            // Combine each left subtree and right subtree with the current root to form a BST
            for (TreeNode* leftSubtree : leftSubtrees) {
                for (TreeNode* rightSubtree : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    result.push_back(root);
                }
            }
        }

        // Memoize the result
        memo[key] = result;

        return result;
    }
};

// Function to print the inorder traversal of a binary tree (used for testing)
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution sol;

    // Example usage
    int n = 3;
    vector<TreeNode*> result = sol.generateTrees(n);

    // Printing the inorder traversal of each generated BST
    for (TreeNode* root : result) {
        inorderTraversal(root);
        cout << endl;
    }

    return 0;
}
