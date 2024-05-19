#include <iostream>  // Include the input/output stream library
#include <vector>    // Include the vector library
using namespace std; // Use the standard namespace

// Function to check if a cycle exists in the graph using Depth First Search (DFS)
bool hasCycleDFS(int u, int parent, vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[u] = true;       // Mark the current node as visited
    for (int v : adjList[u]) // Iterate through the adjacent nodes of the current node
    {
        if (!visited[v]) // If the adjacent node is not visited, recursively call the function
        {
            if (hasCycleDFS(v, u, adjList, visited)) // If a cycle is found in the recursive call, return true
                return true;
        }
        else if (v != parent) // If the adjacent node is visited and not the parent, a cycle is detected
        {
            return true;
        }
    }
    return false; // No cycle found
}

// Function to check if a cycle exists in the graph
bool hasCycle(int numNodes, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(numNodes); // Create an adjacency list to represent the graph
    for (auto &edge : edges)               // Iterate through the edges of the graph
    {
        adjList[edge[0]].push_back(edge[1]); // Add the edge to the adjacency list
        adjList[edge[1]].push_back(edge[0]); // Add the reverse edge to the adjacency list
    }

    vector<bool> visited(numNodes, false); // Initialize visited array
    for (int u = 0; u < numNodes; ++u)     // Iterate through all the nodes of the graph
    {
        if (!visited[u] && hasCycleDFS(u, -1, adjList, visited)) // If the node is not visited and has a cycle, return true
        {
            return true;
        }
    }
    return false; // No cycle found
}

// Function to print the edges of the graph
void printEdges(vector<vector<int>> &edges)
{
    cout << "printing edges\n";            // Print a message indicating that the edges are being printed
    for (int i = 0; i < edges.size(); i++) // Iterate through the edges
    {
        cout << edges[i][0] << " ----> " << edges[i][1] << endl; // Print the edge
    }
}

int main()
{
    int numNodes = 6;                                                                                 // Number of nodes in the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};                     // Edges of the graph
    printEdges(edges);                                                                                // Print the edges of the graph
    cout << (hasCycle(numNodes, edges) ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl; // Check if the graph has a cycle and print the result

    edges = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};                                                         // Edges of the graph
    printEdges(edges);                                                                                // Print the edges of the graph
    cout << (hasCycle(numNodes, edges) ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl; // Check if the graph has a cycle and print the result

    return 0; // Exit the program
}
