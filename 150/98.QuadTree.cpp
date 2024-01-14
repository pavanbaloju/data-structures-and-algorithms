#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
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

bool allSame(int r, int c, int n, vector<vector<int>> &grid)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[r][c] != grid[r + i][c + j])
                return false;

    return true;
}

Node *solve(int r, int c, int n, vector<vector<int>> &grid)
{
    if (allSame(r, c, n, grid))
        return new Node(grid[r][c], true);

    Node *root = new Node();
    n /= 2;

    root->topLeft = solve(r, c, n, grid);
    root->topRight = solve(r, c + n, n, grid);
    root->bottomLeft = solve(r + n, c, n, grid);
    root->bottomRight = solve(r + n, c + n, n, grid);

    return root;
}
Node *construct(vector<vector<int>> &grid)
{
    return solve(0, 0, grid.size(), grid);
}

int main()
{
    vector<vector<int>> grid =
        {{1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0},
         {1, 1, 1, 1, 0, 0, 0, 0}};

    Node *root = construct(grid);
    cout << root->val << endl;
    cout << root->topLeft->val << endl;
    cout << root->topRight->val << endl;
    cout << root->bottomLeft->val << endl;
    cout << root->bottomRight->val << endl;
}