#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library

using namespace std; // Use the standard namespace

// Problem Statement:
// Given a directed graph, determine if it contains a cycle.

// Intuition:
// We can use graph traversal algorithms to detect cycles in a directed graph.
// If a cycle is found during traversal, then the graph contains a cycle.

// DSA Strategy:
// We will use Depth First Search (DFS) to detect cycles in the graph.
// Another approach is to use Kahn's algorithm with topological sorting to detect cycles.

// Approach:
// 1. Perform Depth First Search (DFS) traversal on the graph.
// 2. During traversal, maintain a visited array to keep track of visited nodes and a recursion stack to detect back edges.
// 3. If a node is visited and present in the recursion stack, then there is a cycle in the graph.
// 4. If DFS traversal completes without detecting a cycle, then the graph doesn't have a cycle.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), where V is the number of vertices.

// Function to check if a cycle is present in the directed graph using Depth First Search (DFS)
bool isCyclePresentDFS(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack)
{
    visited[node] = true;       // Mark the current node as visited
    recStack[node] = true;      // Mark the current node in the recursion stack

    for (int neighbor : graph[node]) // Iterate through each neighbor of the current node
    {
        if (!visited[neighbor]) // If the neighbor is not visited, recursively call the function
        {
            if (isCyclePresentDFS(neighbor, graph, visited, recStack))
                return true; // If a cycle is found, return true
        }
        else if (recStack[neighbor]) // If the neighbor is visited and present in the recursion stack, a cycle is detected
        {
            return true; // Return true to indicate the presence of a cycle
        }
    }

    recStack[node] = false; // Remove the current node from the recursion stack
    return false;           // Return false to indicate no cycle is found
}

// Function to check if a cycle exists in the directed graph using Depth First Search (DFS)
bool hasCycleDFS(int numNodes, vector<vector<int>> &graph)
{
    vector<bool> visited(numNodes, false); // Initialize a visited array to keep track of visited nodes
    vector<bool> recStack(numNodes, false); // Initialize a recursion stack to detect back edges

    for (int i = 0; i < numNodes; ++i) // Iterate through each node in the graph
    {
        if (!visited[i]) // If the node is not visited, call DFS traversal
        {
            if (isCyclePresentDFS(i, graph, visited, recStack)) // If a cycle is detected, return true
                return true;
        }
    }

    return false; // Return false if no cycle is found
}

// Function to print the edges of the graph
void printGraphEdges(vector<vector<int>> &graph)
{
    cout << "Printing edges:\n";            // Print a message indicating that the edges are being printed
    for (int i = 0; i < graph.size(); i++) // Iterate over each node
    {
        cout << i << " ----> ";                   // Print the current node
        for (int j = 0; j < graph[i].size(); j++) // Iterate over each adjacent node of the current node
        {
            cout << graph[i][j] << " "; // Print the adjacent node
        }
        cout << endl; // Print a new line
    }
}

int main()
{
    int numNodes = 5;                    // Number of nodes in the graph
    vector<vector<int>> graph(numNodes); // Create a vector of vectors to represent the graph

    // Add edges to the graph
    graph[0].push_back(1);  // Add an edge from node 0 to node 1
    graph[1].push_back(2);  // Add an edge from node 1 to node 2
    graph[2].push_back(3);  // Add an edge from node 2 to node 3
    graph[3].push_back(4);  // Add an edge from node 3 to node 4
    graph[4].push_back(1);  // Add an edge from node 4 to node 1

    // Approach 1: Using Depth First Search (DFS)
    cout << "Using DFS:\n";
    printGraphEdges(graph); // Print the edges of the graph
    cout << (hasCycleDFS(numNodes, graph) ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl; // Check if there is a cycle in the graph and print the result

    return 0; // Return 0 to indicate successful execution
}
