#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to perform level order traversal of a binary tree
vector<vector<int>> levelOrder(TreeNode *root)
{
    // If the tree is empty, return an empty vector
    if (!root)
        return {};

    // Vector to store the values at each level
    vector<vector<int>> values;
    // Queue for level order traversal
    queue<TreeNode *> q;
    // Enqueue the root node
    q.push(root);
    // Loop until the queue is empty
    while (!q.empty())
    {
        // Vector to store values of the current level
        vector<int> level;
        // Get the size of the current level (number of nodes at this level)
        int k = q.size();
        // Process all nodes at the current level
        while (k--)
        {
            // Dequeue a node
            TreeNode *node = q.front();
            q.pop();
            // Add its value to the current level vector
            level.push_back(node->val);

            // Enqueue left and right child nodes if they exist
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        // Add the current level vector to the result
        values.push_back(level);
    }
    // Return the vector containing values at each level
    return values;
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Perform level order traversal and store the result
    vector<vector<int>> res = levelOrder(root);

    // Print the result
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    // Clean up memory (avoid memory leaks)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
