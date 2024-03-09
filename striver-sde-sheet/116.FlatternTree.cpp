#include <iostream>
#include <stack>
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
// Problem Statement:
// Given a binary tree, flatten it to a linked list in-place. The flattened tree should retain the same pre-order traversal.

// Intuition:
// To flatten a binary tree to a linked list in-place, we can use different traversal methods such as pre-order, post-order, or iterative pre-order traversal. 
// Pre-order traversal ensures that the root node is processed before its children, making it suitable for our purpose.

// DSA Strategy:
// We will use the following strategies to solve the problem:
// 1. Iterative Pre-order Traversal: We will use a stack to perform iterative pre-order traversal of the binary tree.
// 2. Post-order Traversal: We will recursively flatten the right subtree first, followed by the left subtree. This ensures that the nodes are visited in reverse pre-order.
// 3. Pre-order Traversal: We will recursively flatten the left subtree first, then adjust the pointers to convert the left subtree into the right subtree while preserving the order.

// Approach 1: Iterative Pre-order Traversal
// - We will perform iterative pre-order traversal of the binary tree using a stack.
// - During traversal, we will update the pointers to convert the binary tree into a linked list.
// - Time Complexity: O(n), where n is the number of nodes in the binary tree.
// - Space Complexity: O(h), where h is the height of the binary tree (space required for the stack).
// Function to flatten the binary tree to a linked list in-place using iterative pre-order traversal
void flattenIter(TreeNode *root)
{
    // If the root is null, return
    if (!root)
        return;

    // Create a stack to store nodes for iterative pre-order traversal
    stack<TreeNode *> st;
    st.push(root);

    // Iterate until the stack is empty
    while (!st.empty())
    {
        // Pop the top node from the stack
        TreeNode *curr = st.top();
        st.pop();

        // If the right child of the current node exists, push it onto the stack
        if (curr->right)
            st.push(curr->right);
        // If the left child of the current node exists, push it onto the stack
        if (curr->left)
            st.push(curr->left);

        // If the stack is not empty, update the right child of the current node to the top node of the stack
        if (!st.empty())
            curr->right = st.top();
        // Update the left child of the current node to null
        curr->left = nullptr;
    }
}

// Approach 2: Post-order Traversal
// - We will recursively flatten the right subtree first, followed by the left subtree.
// - During the process, we will adjust the pointers to convert the binary tree into a linked list.
// - Time Complexity: O(n), where n is the number of nodes in the binary tree.
// - Space Complexity: O(h), where h is the height of the binary tree (space required for the recursive function call stack).
// Function to flatten the binary tree to a linked list in-place using post-order traversal
TreeNode *pre = nullptr;
void flatten(TreeNode *root)
{
    // If the root is null, return
    if (!root)
        return;

    // Flatten the right subtree first
    flatten(root->right);
    // Flatten the left subtree next
    flatten(root->left);

    // Update the pointers to convert the left subtree to the right subtree
    root->right = pre;
    root->left = nullptr;
    pre = root;
}

// Approach 3: Pre-order Traversal
// - We will recursively flatten the left subtree first.
// - Then, we will adjust the pointers to convert the left subtree into the right subtree while preserving the order.
// - Finally, we will recursively flatten the right subtree.
// - Time Complexity: O(n), where n is the number of nodes in the binary tree.
// - Space Complexity: O(h), where h is the height of the binary tree (space required for the recursive function call stack).
// Function to flatten the binary tree to a linked list in-place using pre-order traversal
void flattenPre(TreeNode *root)
{
    // If the root is null or if it has no children, return
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    // If the left child of the root exists
    if (root->left)
    {
        // Flatten the left subtree
        flattenPre(root->left);

        // Store the right child of the root in a temporary variable
        TreeNode *temp = root->right;

        // Update the right child of the root to point to the left subtree
        root->right = root->left;

        // Update the left child of the root to null
        root->left = nullptr;

        // Find the rightmost node in the left subtree
        TreeNode *rightmost = root->right;
        while (rightmost->right)
            rightmost = rightmost->right;

        // Update the rightmost node to point to the right subtree
        rightmost->right = temp;
    }

    // Flatten the right subtree
    flattenPre(root->right);
}

// Function to print the flattened linked list
void printList(TreeNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->right;
    }
    cout<<endl;
}

int main()
{
    // Construct the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Flatten the binary tree to a linked list in-place using iterative pre-order traversal
    flattenIter(root);
    printList(root);

    // Construct the binary tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Flatten the binary tree to a linked list in-place using post-order traversal
    flatten(root);
    printList(root);

    // Construct the binary tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Flatten the binary tree to a linked list in-place using pre-order traversal
    flattenPre(root);
    printList(root);

    return 0;
}
