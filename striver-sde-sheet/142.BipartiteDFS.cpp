#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given an undirected graph, return true if and only if it is bipartite.
// A graph is bipartite if we can split its set of nodes into two independent subsets such that every edge in the graph has one node in each subset.

// Intuition:
// We can solve this problem using Depth-First Search (DFS) traversal. We assign colors to vertices such that no two adjacent vertices have the same color.
// We start DFS traversal from each uncolored vertex, assigning colors to its neighbors with the opposite color of the current vertex.
// If at any point we encounter a neighbor with the same color as the current vertex, the graph is not bipartite.

// DSA Strategy:
// DFS

// Approach:
// 1. Create a function isBipartiteUtil to recursively check if the graph is bipartite starting from a given vertex.
// 2. Inside isBipartiteUtil, traverse all neighbors of the current vertex.
//    a. If a neighbor is uncolored, color it with the opposite color of the current vertex and recursively check its neighbors.
//    b. If a neighbor is already colored and has the same color as the current vertex, return false (not bipartite).
// 3. Create a function isBipartite to check if the entire graph is bipartite by checking all connected components using DFS.
// 4. Initialize a vector to store vertex colors (initialized as uncolored).
// 5. Iterate through each uncolored vertex and start DFS traversal to check bipartiteness.
// 6. If any connected component is not bipartite, return false. Otherwise, return true.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), where V is the number of vertices in the graph.

// Function to recursively check if the graph is bipartite starting from vertex 'v'
bool isBipartiteUtil(vector<vector<int>> &graph, int v, vector<int> &color)
{
    // Traverse all neighbors of vertex 'v'
    for (int u : graph[v])
    {
        // If neighbor 'u' is uncolored
        if (color[u] == -1)
        {
            // Color neighbor 'u' with the opposite color of vertex 'v'
            color[u] = 1 - color[v];

            // Recursively check if the subtree rooted at 'u' is bipartite
            if (!isBipartiteUtil(graph, u, color))
                return false;
        }
        // If neighbor 'u' is already colored and has the same color as vertex 'v'
        else if (color[u] == color[v])
        {
            // The graph is not bipartite
            return false;
        }
    }
    // If all neighbors are checked and the graph remains bipartite
    return true;
}

// Function to check if a given graph is bipartite
bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size(); // Number of vertices in the graph
    vector<int> color(V, -1); // Initialize all vertices as uncolored

    // Traverse each vertex in the graph
    for (int i = 0; i < V; i++)
    {
        // If the vertex is uncolored, start the bipartite check from this vertex
        if (color[i] == -1)
        {
            color[i] = 0; // Color the vertex with '0' initially

            // If the bipartite check starting from this vertex fails, return false
            if (!isBipartiteUtil(graph, i, color))
                return false;
        }
    }
    // If all connected components are bipartite, return true
    return true;
}

int main()
{
    // Example usage
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool isGraphBipartite = isBipartite(graph);
    cout << "Graph is bipartite: " << (isGraphBipartite ? "Yes" : "No") << endl;

    return 0;
}
