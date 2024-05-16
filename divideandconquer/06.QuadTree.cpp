#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a grid of 0's and 1's, where 0 represents a white cell and 1 represents a black cell, construct a quad tree to represent it. A quad tree is a tree data structure in which each internal node has exactly four children.

// Intuition:
// The problem can be solved by recursively dividing the grid into quadrants until a quadrant contains only one color (either black or white). Each leaf node represents a cell in the grid, and each non-leaf node represents a quadrant.

// DSA Strategy:
// Recursive approach, Quad Tree construction

// Approach:
// 1. Implement a Node class to represent each node in the quad tree.
// 2. Define a function 'allSame' to check if all elements in a subgrid are the same.
// 3. Implement a recursive function 'solve' to construct the quad tree.
//    - If all elements in the subgrid are the same, create a leaf node.
//    - Otherwise, create a non-leaf node and recursively construct child nodes.
// 4. Define a function 'construct' to start the quad tree construction from the entire grid.
// 5. In the main function, create an example grid and construct the quad tree from it.
// 6. Print the values of the root node and its children to verify the construction.

// Time Complexity: O(N^2 * log N), where N is the size of the grid.
// Space Complexity: O(N^2) for the recursion stack and quad tree construction.

// Definition of the Quad Tree Node
class Node
{
public:
    bool val;          // Value of the node
    bool isLeaf;       // Indicates whether the node is a leaf
    Node *topLeft;     // Pointer to the top-left child node
    Node *topRight;    // Pointer to the top-right child node
    Node *bottomLeft;  // Pointer to the bottom-left child node
    Node *bottomRight; // Pointer to the bottom-right child node

    // Constructors
    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// Function to check if all elements in a subgrid are the same
bool allSame(int r, int c, int n, vector<vector<int>> &grid)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[r][c] != grid[r + i][c + j])
                return false;

    return true;
}

// Recursive function to construct the Quad Tree
Node *solve(int r, int c, int n, vector<vector<int>> &grid)
{
    if (allSame(r, c, n, grid))
        return new Node(grid[r][c], true); // Create a leaf node if all elements are the same

    Node *root = new Node(); // Create a non-leaf node
    n /= 2;

    // Recursively construct child nodes
    root->topLeft = solve(r, c, n, grid);
    root->topRight = solve(r, c + n, n, grid);
    root->bottomLeft = solve(r + n, c, n, grid);
    root->bottomRight = solve(r + n, c + n, n, grid);

    return root;
}

// Function to construct the Quad Tree from the grid
Node *construct(vector<vector<int>> &grid)
{
    return solve(0, 0, grid.size(), grid); // Start the construction from the entire grid
}

int main()
{
    // Example grid
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}};

    // Construct the Quad Tree
    Node *root = construct(grid);

    // Example to access values of the constructed Quad Tree
    cout << "Root Value: " << root->val << endl;
    cout << "Top Left Value: " << root->topLeft->val << endl;
    cout << "Top Right Value: " << root->topRight->val << endl;
    cout << "Bottom Left Value: " << root->bottomLeft->val << endl;
    cout << "Bottom Right Value: " << root->bottomRight->val << endl;

    return 0;
}
