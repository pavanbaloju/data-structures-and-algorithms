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
// We will use Breadth First Search (BFS) to detect cycles in the graph.
// Another approach is to use Kahn's algorithm with topological sorting to detect cycles.

// Approach:
// 1. Calculate the in-degree of each vertex in the graph.
// 2. Enqueue vertices with in-degree 0.
// 3. Perform BFS traversal, reducing the in-degree of adjacent vertices.
// 4. If the count of visited vertices is not equal to the number of vertices, there is a cycle in the graph.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), where V is the number of vertices.

// Function to detect a cycle in a directed graph using Breadth First Search (BFS)
bool detectCycleBFS(vector<vector<int>> &graph, int n)
{
    vector<int> inDegree(n, 0); // Create a vector to store the in-degree of each vertex
    queue<int> q;               // Create a queue to perform BFS

    // Calculate in-degree of each vertex
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int v = graph[i][j]; // Get the adjacent vertex
            inDegree[v]++;       // Increment the in-degree of the adjacent vertex
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i); // Enqueue the vertex with in-degree 0
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int u = q.front(); // Get the front vertex from the queue
        q.pop();           // Remove the front vertex from the queue
        count++;           // Increment the count of visited vertices

        // Reduce in-degree of adjacent vertices
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i]; // Get the adjacent vertex
            inDegree[v]--;       // Decrement the in-degree of the adjacent vertex

            // If in-degree becomes 0, enqueue the vertex
            if (inDegree[v] == 0)
            {
                q.push(v); // Enqueue the vertex with in-degree 0
            }
        }
    }

    // If count is not equal to the number of vertices, there is a cycle
    return count != n;
}

int main()
{
    int n = 6; // Number of vertices in the graph
    vector<vector<int>> graph(n); // Create a vector of vectors to represent the graph

    // Add edges to the graph
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);
    graph[5].push_back(3);

    // Check if the graph contains a cycle using BFS
    cout << (detectCycleBFS(graph, n) ? "Cycle detected" : "No cycle detected") << endl;

    return 0; // Return 0 to indicate successful execution
}
