#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node *connect(Node *root)
{
    if (!root)
        return nullptr;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<Node *> level;
        int k = q.size();
        while (k--)
        {
            Node *node = q.front();
            q.pop();
            level.push_back(node);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        for (int i = 0; i < level.size() - 1; i++)
        {
            level[i]->next = level[i + 1];
        }
    }
    return root;
}

// works for perfect binary tree (node with both children except leaf nodes)
Node *connect2(Node *root)
{
    if (!root)
        return nullptr;

    Node *curr = root, *nxt = root->left;

    // while there is a node with children
    while (curr && nxt)
    {
        // assign left child next with right child
        curr->left->next = curr->right;

        // if a node exists next to current parent node in the same level
        if (curr->next)
        {
            curr->right->next = curr->next->left;
        }
        // move to next node in the same level
        curr = curr->next;

        // if next node in the same level is null i.e at the end
        // move current to next level and nxt to starting of next next level
        if (!curr)
        {
            curr = nxt;
            nxt = curr->left;
        }
    }

    return root;
}