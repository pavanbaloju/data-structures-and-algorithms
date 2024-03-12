#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Recursive function to clone the graph
Node *cloneGraphUtil(Node *node, std::unordered_map<Node *, Node *> &cloned)
{
    // If the node is null, return null
    if (node == nullptr)
    {
        return nullptr;
    }

    // If the node is already cloned, return its clone
    if (cloned.find(node) != cloned.end())
    {
        return cloned[node];
    }

    // Create a clone of the current node
    Node *cloneNode = new Node(node->val);
    cloned[node] = cloneNode; // Add mapping between original and cloned node

    // Clone each neighbor recursively
    for (Node *neighbor : node->neighbors)
    {
        cloneNode->neighbors.push_back(cloneGraphUtil(neighbor, cloned));
    }

    return cloneNode;
}

// Function to clone the graph
Node *cloneGraph(Node *node)
{
    // Create an unordered map to store mapping between original and cloned nodes
    unordered_map<Node *, Node *> cloned;

    // Clone the graph starting from the given node
    return cloneGraphUtil(node, cloned);
}

int main()
{
    // Example usage
    // Create a graph
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node1);
    node3->neighbors.push_back(node2);

    // Clone the graph
    Node *clonedNode = cloneGraph(node1);
    cout << "Cloned graph: " << clonedNode->val << endl;
    
    return 0;
}
