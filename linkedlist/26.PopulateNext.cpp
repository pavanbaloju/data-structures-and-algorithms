#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of Node structure representing a node in the binary tree
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// Problem Statement:
// Given a binary tree, populate each next pointer to point to its next right node. If there is no next right node,
// the next pointer should be set to NULL. Initially, all next pointers are set to NULL.

// Intuition:
// We can use a level order traversal approach to connect nodes at the same level using their next pointers.

// DSA Strategy:
// We will solve this problem using two approaches:
// 1. Level Order Traversal with Extra Space: We will perform level order traversal of the binary tree using a queue
//    and store nodes at each level in a vector. After processing each level, we will connect nodes at the same level
//    using their next pointers.
// 2. Level Order Traversal with Constant Space: We will perform level order traversal of the binary tree without using
//    extra space. We will use the next pointers of nodes to connect nodes at the same level.

// Approach 1: Level Order Traversal with Extra Space
// - We will perform level order traversal of the binary tree using a queue.
// - During traversal, we will store nodes at each level in a vector.
// - After processing each level, we will connect nodes at the same level using their next pointers.
// - Time Complexity: O(n), where n is the number of nodes in the binary tree.
// - Space Complexity: O(m), where m is the maximum number of nodes at any level (space required for the queue and vector).
// Function to populate next pointer of all nodes of a binary tree using level order traversal
Node *connect(Node *root)
{
    // If the root is null, return null
    if (!root)
        return nullptr;

    // Create a queue for level order traversal
    queue<Node *> q;
    // Push the root node into the queue
    q.push(root);

    // Perform level order traversal
    while (!q.empty())
    {
        // Get the size of the current level
        int levelSize = q.size();
        // Initialize a vector to store nodes at the current level
        vector<Node *> levelNodes;

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; i++)
        {
            // Pop a node from the front of the queue
            Node *node = q.front();
            q.pop();
            // Add the node to the vector
            levelNodes.push_back(node);

            // Push the left and right children of the node into the queue (if they exist)
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        // Connect nodes at the current level
        for (int i = 0; i < levelNodes.size() - 1; i++)
        {
            levelNodes[i]->next = levelNodes[i + 1];
        }
    }

    // Return the root of the binary tree
    return root;
}

// Approach 2: Level Order Traversal with Constant Space
// - We will perform level order traversal of the binary tree without using extra space.
// - We will use the next pointers of nodes to connect nodes at the same level.
// - Time Complexity: O(n), where n is the number of nodes in the binary tree.
// - Space Complexity: O(1).
// Function to populate next pointer of all nodes of a binary tree in-place using level order traversal
Node *connect2(Node *root)
{
    // If the root is null, return null
    if (!root)
        return nullptr;

    Node *curr = root, *nextLevel = root->left;

    // Traverse the tree until there are nodes with children
    while (curr && nextLevel)
    {
        // Connect left child's next pointer to right child
        curr->left->next = curr->right;

        // If there is a node next to the current parent node in the same level
        if (curr->next)
        {
            // Connect right child's next pointer to left child of next node
            curr->right->next = curr->next->left;
            // Move to the next node
            curr = curr->next;
        }
        else
        {
            // Move to the next level
            curr = nextLevel;
            // Move to the left child of the next level
            nextLevel = curr->left;
        }
    }

    // Return the root of the binary tree
    return root;
}

// Function to print the next pointers of all nodes of a binary tree
void printNext(Node *root)
{
    // If the root is null, return
    if (!root)
        return;

    // Start from the leftmost node of the tree
    Node *curr = root;
    // Traverse each level
    while (curr)
    {
        // Print the next pointers of nodes at the current level
        Node *temp = curr;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        // Move to the left child of the next level
        curr = curr->left;
    }
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Populate the next pointers of all nodes using level order traversal
    connect(root);
    // Print the next pointers of all nodes
    printNext(root);

    // Construct the binary tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    // Populate the next pointers of all nodes in-place using level order traversal
    connect2(root2);
    // Print the next pointers of all nodes
    printNext(root2);

    return 0;
}
