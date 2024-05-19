#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode structure representing a node in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to find the kth largest element in a BST recursively
void kthLargestUtil(TreeNode *root, int &k, int &ans)
{
    // Base case: If the root is NULL or k becomes 0, return
    if (root == NULL || k == 0)
        return;

    // Recur for the right subtree
    kthLargestUtil(root->right, k, ans);

    // If k becomes 0, return
    if (k == 0)
        return;

    // Decrement k and update the answer if k becomes 0
    if (--k == 0)
        ans = root->val;

    // Recur for the left subtree
    kthLargestUtil(root->left, k, ans);
}

// Function to find the kth largest element in a BST
int kthLargest(TreeNode *root, int k)
{
    // Initialize the answer
    int ans = -1;

    // Find the kth largest element in the BST
    kthLargestUtil(root, k, ans);

    // Return the kth largest element
    return ans;
}

int main()
{
    // Example 1:
    // Construct the BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    // Find the kth largest element in the BST
    cout << kthLargest(root, 3) << endl; // Output: 6
    return 0;
}