#include <iostream>
#include <vector>
#include <stack>
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
// Given the root of a binary tree, traverse it in pre-order, in-order, and post-order,
// storing the values of its nodes in separate vectors.

// Intuition:
// We can perform pre-order, in-order, and post-order traversals iteratively using a stack.
// We use a stack to mimic the recursive function call stack and keep track of the state of each node.
// The state indicates whether the node has been processed for the current traversal type (pre-order, in-order, or post-order).
// We push nodes onto the stack along with their state and process them accordingly.

// DSA Strategy:
// We use a stack to perform iterative traversal.
// Each element in the stack is a pair consisting of a TreeNode pointer and its state.
// We maintain separate vectors for pre-order, in-order, and post-order traversal.
// At each step, we process the node based on its state and update the state accordingly.

// Approach:
// 1. Initialize three empty vectors: pre, in, and post to store values of nodes in pre-order, in-order, and post-order respectively.
// 2. If the root is NULL, return.
// 3. Initialize a stack of pairs, where each pair consists of a TreeNode pointer and its state.
// 4. Push the root node with state 1 onto the stack.
// 5. While the stack is not empty, do the following:
//    a. Get the top element from the stack.
//    b. Pop the top element from the stack.
//    c. Process the node based on its state:
//       i. If the state is 1 (pre-order), add the node's value to the pre vector, increment the state, and push the node back onto the stack.
//       ii. If the state is 2 (in-order), add the node's value to the in vector, increment the state, and push the node back onto the stack.
//       iii. If the state is 3 (post-order), add the node's value to the post vector.
//    d. If the node has a left child, push the left child with state 1 onto the stack.
//    e. If the node has a right child, push the right child with state 1 onto the stack.
// 6. Return the pre, in, and post vectors containing values of nodes in pre-order, in-order, and post-order respectively.

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n), where n is the number of nodes in the binary tree (used for stack space and storing traversal results).

void allTraversal(TreeNode *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1}); // Push the root node with state 1 to the stack

    if (root == NULL)
        return; // If the root is NULL, return

    while (!st.empty())
    {
        auto it = st.top(); // Get the top element from the stack
        st.pop(); // Pop the top element

        if (it.second == 1)
        {
            preorder.push_back(it.first->val); // Add the value to the preorder vector
            it.second++; // Increment the state of the node
            st.push(it); // Push the updated node back to the stack

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1}); // Push the left child with state 1 to the stack
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->val); // Add the value to the inorder vector
            it.second++; // Increment the state of the node
            st.push(it); // Push the updated node back to the stack

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1}); // Push the right child with state 1 to the stack
            }
        }
        else
        {
            postorder.push_back(it.first->val); // Add the value to the postorder vector
        }
    }
}

void printVector(vector<int> &v)
{
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);

    cout << "Preorder: ";
    printVector(pre);

    cout << "Inorder: ";
    printVector(in);

    cout << "Postorder: ";
    printVector(post);

    return 0;
}


