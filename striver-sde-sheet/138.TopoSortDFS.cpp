#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <stack>    // Include the stack library

using namespace std; // Use the standard namespace

// Problem Statement:
// Perform topological sorting on a directed acyclic graph (DAG).

// Intuition:
// Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG)
// such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

// DSA Strategy:
// We can use Depth First Search (DFS) to perform topological sorting.
// The idea is to recursively explore all unvisited neighbors of each vertex and push the vertices onto a stack.
// After DFS traversal, pop the vertices from the stack to get the topologically sorted order.

// Approach:
// 1. Perform Depth First Search (DFS) traversal starting from each unvisited node.
// 2. During DFS, mark each visited node and recursively explore all unvisited neighbors.
// 3. After visiting all neighbors of a node, push the node onto a stack.
// 4. After DFS traversal, pop nodes from the stack to get the topologically sorted order.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), where V is the number of vertices.

// Function to perform Depth First Search (DFS) traversal
// It explores all unvisited neighbors of a node and pushes the node onto the stack
void dfs(int node, vector<int> &visited, vector<vector<int>> &adjList, stack<int> &stk)
{
    visited[node] = 1; // Mark the current node as visited

    // Explore all unvisited neighbors of the current node
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor]) // If the neighbor is not visited
        {
            dfs(neighbor, visited, adjList, stk); // Recursively explore the neighbor
        }
    }

    stk.push(node); // Push the current node onto the stack after all neighbors are visited
}

// Function to perform topological sort using Depth First Search (DFS)
vector<int> topologicalSort(int numNodes, vector<vector<int>> &adjList)
{
    stack<int> stk;                   // Initialize a stack to store the topologically sorted nodes
    vector<int> visited(numNodes, 0); // Initialize a visited array to keep track of visited nodes during DFS

    // Perform DFS from each unvisited node in the graph
    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i]) // If the node is not visited
        {
            dfs(i, visited, adjList, stk); // Perform DFS traversal
        }
    }

    vector<int> result; // Initialize a vector to store the topologically sorted order

    // Pop nodes from the stack to get the topologically sorted order
    while (!stk.empty())
    {
        result.push_back(stk.top()); // Push the top node of the stack to the result vector
        stk.pop();                   // Pop the top node from the stack
    }

    return result; // Return the topologically sorted order
}

// Function to print the adjacency list representation of the graph
void printGraph(vector<vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print the contents of a vector
void printVector(vector<int> &result)
{
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numNodes = 6; // Number of nodes in the graph

    // Initialize the adjacency list representation of the graph
    vector<vector<int>> adjList(numNodes);
    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    // Print the adjacency list representation of the graph
    cout << "Graph (Adjacency List):" << endl;
    printGraph(adjList);

    // Perform topological sort and print the result
    cout << "Topological Sort Order:" << endl;
    vector<int> result = topologicalSort(numNodes, adjList);
    printVector(result);

    return 0; // Return 0 to indicate successful execution
}
