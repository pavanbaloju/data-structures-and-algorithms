#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given an undirected graph, return true if and only if it is bipartite.
// A graph is bipartite if we can split its set of nodes into two independent subsets such that every edge in the graph has one node in each subset.

// Intuition:
// We can solve this problem by coloring the vertices of the graph using two colors (0 and 1).
// We start BFS traversal from each uncolored vertex and assign colors to its adjacent vertices alternatively.
// If at any point we find that two adjacent vertices have the same color, then the graph is not bipartite.

// DSA Strategy:
// BFS

// Approach:
// 1. Create a function bfsCheckBipartite to perform BFS traversal and check bipartiteness.
//    a. Initialize a queue for BFS traversal and a vector to store vertex colors.
//    b. Start BFS traversal from the given vertex and color it with color 0.
//    c. Color its neighbors with the opposite color (1 - color[curr]).
//    d. If any neighbor has the same color as the current vertex, return false (not bipartite).
// 2. Create a function isBipartite to check if the entire graph is bipartite.
//    a. Initialize a vector to store vertex colors (initialized as uncolored).
//    b. Iterate through each uncolored vertex and perform BFS to check bipartiteness.
//    c. If any connected component is not bipartite, return false. Otherwise, return true.
// 3. In the main function, call isBipartite with the given graph and print the result.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), where V is the number of vertices in the graph.

// Function to perform BFS traversal and check bipartiteness
bool bfsCheckBipartite(int start, vector<int> &color, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(start);
    color[start] = 0; // Color the start vertex with 0

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
        {
            if (color[neighbor] == -1) // If neighbor is uncolored
            {
                color[neighbor] = 1 - color[curr]; // Assign opposite color to neighbor
                q.push(neighbor);  // Push neighbor to queue
            }
            else if (color[neighbor] == color[curr]) // If neighbor has same color as current vertex
            {
                return false; // Not bipartite
            }
        }
    }

    return true; // Graph is bipartite
}

// Function to check if a graph is bipartite
bool isBipartite(const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1); // -1 represents uncolored

    for (int i = 0; i < n; i++) // Check for all connected components
    {
        if (color[i] == -1 && !bfsCheckBipartite(i, color, graph)) // If graph is not bipartite
        {
            return false; // Graph is not bipartite
        }
    }

    return true; // Graph is bipartite
}

int main()
{
    // Example usage
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    bool isGraphBipartite = isBipartite(graph);
    cout << "Graph is bipartite: " << (isGraphBipartite ? "Yes" : "No") << endl;

    return 0;
}
