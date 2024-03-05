#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// Function to get the vertical order of a binary tree using an iterative approach
vector<vector<int>> verticalOrder(TreeNode *root)
{
    vector<vector<int>> result; // Create a vector of vectors to store the vertical order elements

    if (root == nullptr) // If the root is null, return the empty result vector
        return result;

    map<int, vector<int>> m;        // Create a map to store the vertical distance and the value of the nodes
    queue<pair<TreeNode *, int>> q; // Create a queue to perform level order traversal
    q.push({root, 0});              // Push the root node and its vertical distance into the queue

    while (!q.empty()) // Perform level order traversal until the queue is empty
    {
        TreeNode *temp = q.front().first; // Get the front node of the queue
        int vDist = q.front().second;     // Get the vertical distance of the front node
        q.pop();                          // Remove the front node from the queue

        m[vDist].push_back(temp->val); // Add the value of the front node to the map at the corresponding vertical distance

        if (temp->left != nullptr) // If the left child exists, push it into the queue with the same vertical distance
            q.push({temp->left, vDist - 1});
        if (temp->right != nullptr) // If the right child exists, push it into the queue with the same vertical distance
            q.push({temp->right, vDist + 1});
    }

    for (auto it : m) // Iterate through the map and add the vertical order elements to the result vector
        result.push_back(it.second);

    return result; // Return the vertical order vector
}

void verticalOrderUtil(TreeNode *root, int vDist, int hDist, map<int, map<int, vector<int>>> &m)
{
    if (root == nullptr) // If the root is null, return
        return;

    m[vDist][hDist].push_back(root->val); // Add the value of the node to the map at the corresponding vertical and horizontal distances

    verticalOrderUtil(root->left, vDist - 1, hDist + 1, m);  // Recursively call the left child with decreased vertical distance and increased horizontal distance
    verticalOrderUtil(root->right, vDist + 1, hDist + 1, m); // Recursively call the right child with increased vertical distance and increased horizontal distance
}

// Function to get the vertical order of a binary tree using a recursive approach
vector<vector<int>> verticalOrderRecursive(TreeNode *root)
{
    map<int, map<int, vector<int>>> m; // Create a map to store the vertical and horizontal distances and the value of the nodes
    verticalOrderUtil(root, 0, 0, m);  // Call the utility function to get the vertical order

    vector<vector<int>> result; // Create a vector of vectors to store the vertical order elements
    for (auto it : m)           // Iterate through the map and add the vertical order elements to the result vector
    {
        vector<int> temp;
        for (auto i : it.second)
            temp.insert(temp.end(), i.second.begin(), i.second.end());
        result.push_back(temp);
    }

    return result; // Return the vertical order vector
}

// Function to print a vector of vectors of integers
void printVector(vector<vector<int>> &v)
{
    for (vector<int> i : v) // Iterate through the vector of vectors
    {
        for (int j : i) // Iterate through the inner vector and print the elements
            cout << j << " ";
        cout << endl; // Print a new line after printing the inner vector
    }
}

int main()
{
    TreeNode *root = new TreeNode(3); // Create a binary tree
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = verticalOrder(root); // Get the vertical order of the binary tree
    printVector(result);                              // Print the vertical order vector

    result = verticalOrderRecursive(root); // Get the vertical order of the binary tree using a recursive approach
    printVector(result);                    // Print the vertical order vector

    return 0; // Return 0 to indicate successful completion
}