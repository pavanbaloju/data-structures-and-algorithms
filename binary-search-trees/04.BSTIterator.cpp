#include <iostream>
#include <vector>
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
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root of the BST.
// The iterator should return the next smallest number in the BST in ascending order.

// Intuition:
// Inorder traversal of a BST visits the nodes in ascending order. We can implement an iterator that performs an
// inorder traversal of the BST and maintains a stack to keep track of the nodes that need to be visited next.

// DSA Strategy:
// This problem falls under the category of "Tree Traversal and Search".
// We implement a custom iterator class BSTIterator, which maintains a stack to store nodes for inorder traversal.
// The constructor of the BSTIterator initializes the stack by pushing all left nodes starting from the root.
// The next() function returns the next smallest element in the BST by popping the top node from the stack,
// pushing all left nodes of its right child onto the stack, and returning the value of the popped node.
// The hasNext() function checks if there are more elements in the BST by checking if the stack is empty.

// Time Complexity:
// Constructor: O(h), where h is the height of the BST.
// next(): O(1) average, O(h) worst case (amortized time complexity).
// hasNext(): O(1).

class BSTIterator
{
private:
    stack<TreeNode *> st; // Stack to store the nodes

    // Helper function to push all left nodes of a given node onto the stack
    void pushAllLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node); // Push the node onto the stack
            node = node->left; // Move to the left child
        }
    }

public:
    // Constructor to initialize the iterator with the root of the BST
    BSTIterator(TreeNode *root)
    {
        pushAllLeft(root); // Push all left nodes onto the stack starting from the root
    }

    // Function to return the next smallest element in the BST
    int next()
    {
        TreeNode *node = st.top(); // Get the top node from the stack
        st.pop(); // Pop the top node from the stack
        pushAllLeft(node->right); // Push all left nodes of the right child onto the stack
        return node->val; // Return the value of the node
    }

    // Function to check if there are more elements in the BST
    bool hasNext()
    {
        return !st.empty(); // Return true if the stack is not empty, indicating there are more elements
    }
};

int main()
{
    // Create a sample BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Create a BST iterator
    BSTIterator bstIterator = BSTIterator(root);

    // Print the elements in ascending order using the iterator
    while (bstIterator.hasNext())
    {
        cout << bstIterator.next() << " ";
    }

    return 0;
}
