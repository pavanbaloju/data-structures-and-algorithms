#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void clone(Node *node, vector<Node *> &cloned)
{
    cloned[node->val] = new Node(node->val);
    for (Node *neighbor : node->neighbors)
    {
        if (cloned[neighbor->val] == NULL)
        {
            clone(neighbor, cloned);
        }
        cloned[node->val]->neighbors.push_back(cloned[neighbor->val]);
    }
}
Node *cloneGraph(Node *node)
{
    if (!node)
    {
        return node;
    }
    if (node->neighbors.size() == 0)
    {
        return new Node(node->val);
    }
    vector<Node *> cloned = vector<Node *>(101, nullptr);
    clone(node, cloned);
    return cloned[1];
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    Node *clone = cloneGraph(node1);
    cout<<clone->val<<" "<<clone->neighbors[0]->val<<" "<<clone->neighbors[1]->val;
    return 0;
}