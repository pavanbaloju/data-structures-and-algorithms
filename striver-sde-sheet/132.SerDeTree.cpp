#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";       // Print the value of the current node
    preOrderTraversal(root->left);  // Recursively traverse the left subtree
    preOrderTraversal(root->right); // Recursively traverse the right subtree
}

// Problem Statement: Serialize and deserialize a binary tree.

// Intuition: Perform level-order traversal (BFS) to serialize the tree. Use a queue to store nodes during deserialization.

// DSA strategy used: Level-order traversal, Queue

// Approach:
// Serialization:
// 1. Perform level-order traversal of the binary tree.
// 2. Use a queue to store nodes during traversal.
// 3. For each node, append its value to the serialized string.
// 4. If a node is null, append "#" to indicate a null node.
// 5. Return the serialized string.

// Deserialization:
// 1. If the input string is empty, return null.
// 2. Use stringstream to split the input string into tokens.
// 3. Create the root node using the first token (value of the root).
// 4. Use a queue to store parent nodes during reconstruction.
// 5. For each pair of tokens representing left and right children:
//    a. If the token is "#", set the corresponding child pointer to null.
//    b. Otherwise, create a new node with the token value and set it as the corresponding child.
// 6. Return the root node.

// Time Complexity: Both serialization and deserialization operations have a time complexity of O(n), where n is the number of nodes in the binary tree.
// Space Complexity: Both serialization and deserialization operations have a space complexity of O(n), where n is the number of nodes in the binary tree.
string serialize(TreeNode *root)
{
    if (!root)
        return "";

    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
            s.append("#,"); // Indicates null node
        else
        {
            s.append(to_string(node->val) + ','); // Append node value
            q.push(node->left);                   // Enqueue left child
            q.push(node->right);                  // Enqueue right child
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.empty())
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str)); // Create root node
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#") // Check for null left child
        {
            node->left = nullptr;
        }
        else
        {
            TreeNode *left = new TreeNode(stoi(str)); // Create left child
            node->left = left;
            q.push(left);
        }
        getline(s, str, ',');
        if (str == "#") // Check for null right child
        {
            node->right = nullptr;
        }
        else
        {
            TreeNode *right = new TreeNode(stoi(str)); // Create right child
            node->right = right;
            q.push(right);
        }
    }
    return root;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Serialize the binary tree to a string
    string serializedTree = serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;

    // Deserialize the string and reconstruct the binary tree
    root = deserialize(serializedTree);

    // Perform pre-order traversal to verify the reconstruction
    cout << "Pre-order traversal of reconstructed tree: ";
    preOrderTraversal(root);

    return 0;
}
