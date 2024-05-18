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
        return {};

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

// tree is not a perfect binary tree
Node *connect2(Node *root)
{
    Node *head = root;

    // while there are nodes with children
    while (head != NULL)
    {
        // extra dummy node to left of next level
        Node *dummy = new Node(0);
        Node *curr = dummy;

        // while there are nodes in current level
        while (head != NULL)
        {
            // if left child exists, dummy next = left and move curr to next in level
            if (head->left != NULL)
            {
                curr->next = head->left;
                curr = curr->next;
            }
            // if right exists, connect left next = right and move curr to next in level
            if (head->right != NULL)
            {
                curr->next = head->right;
                curr = curr->next;
            }

            // move head to next node in level
            // if there is no node to right the inner loop exits
            head = head->next;
        }
        // move head to start of next level
        head = dummy->next;
    }
    return root;
}
