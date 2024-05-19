#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <stack>    // Include the stack library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given a directed graph, find the number of strongly connected components (SCCs) using Kosaraju's algorithm.

// Intuition:
// Kosaraju's algorithm consists of two main steps:
// 1. Perform Depth-First Search (DFS) on the original graph and fill a stack with the finishing times of each vertex.
// 2. Transpose the original graph (reverse all edges) and perform DFS again on the transposed graph to identify SCCs.

// DSA Strategy:
// Kosaraju's algorithm is based on Depth-First Search (DFS) and uses the concept of finishing times to identify SCCs.

// Approach:
// 1. Perform DFS on the original graph and fill a stack with finishing times using dfsOriginalGraph.
// 2. Transpose the original graph to get the transposed graph.
// 3. Perform DFS on the transposed graph to identify SCCs and count them using dfsTransposedGraph.
// 4. Return the count of SCCs.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

// Function to perform DFS on the original graph and fill the stack with finishing times
void dfsOriginalGraph(int node, vector<int> &visited, vector<int> adj[], stack<int> &st)
{
    visited[node] = 1; // Mark the current node as visited
    for (auto neighbor : adj[node]) // Traverse neighbors of the current node
    {
        if (!visited[neighbor]) // If neighbor is not visited, recursively call DFS
        {
            dfsOriginalGraph(neighbor, visited, adj, st);
        }
    }
    st.push(node); // Push the current node onto the stack after visiting all its neighbors
}

// Function to perform DFS on the transposed graph
void dfsTransposedGraph(int node, vector<int> &visited, vector<int> transpose[])
{
    cout << node << " "; // Print the current node
    visited[node] = 1; // Mark the current node as visited
    for (auto neighbor : transpose[node]) // Traverse neighbors of the current node in the transposed graph
    {
        if (!visited[neighbor]) // If neighbor is not visited, recursively call DFS
        {
            dfsTransposedGraph(neighbor, visited, transpose);
        }
    }
}

// Function to find the number of strongly connected components using Kosaraju's algorithm
int kosaraju(int V, vector<int> adj[])
{
    vector<int> visited(V, 0); // Create a vector to track visited nodes
    stack<int> st; // Create a stack to store nodes in order of finishing times

    // Step 1: Perform DFS on the original graph and fill the stack with finishing times
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // If node is not visited, call DFS on it
        {
            dfsOriginalGraph(i, visited, adj, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> transpose[V]; // Create a transpose graph
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0; // Reset visited array
        for (auto neighbor : adj[i]) // Traverse neighbors of each node in the original graph
        {
            transpose[neighbor].push_back(i); // Add reverse edges to the transpose graph
        }
    }

    // Step 3: Perform reverse DFS on the transposed graph to find strongly connected components
    int count = 0; // Initialize count of SCCs
    while (!st.empty()) // Iterate over nodes in stack (in order of finishing times)
    {
        int node = st.top(); // Get top node from stack
        st.pop(); // Pop the top node from stack
        if (!visited[node]) // If node is not visited, it belongs to a new SCC
        {
            cout << "Strongly Connected Component: ";
            dfsTransposedGraph(node, visited, transpose); // Call DFS on transposed graph to print SCC
            cout << endl;
            count++; // Increment count of SCCs
        }
    }

    return count; // Return the total count of strongly connected components
}

int main()
{
    int n = 5; // Number of nodes
    vector<int> adj[n]; // Adjacency list representation of the graph

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    // Find and print the number of strongly connected components
    cout << "Number of Strongly Connected Components: " << kosaraju(n, adj) << endl;

    return 0;
}
