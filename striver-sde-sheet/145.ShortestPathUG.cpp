#include <iostream>  // Include the input/output stream library
#include <vector>    // Include the vector library
#include <queue>     // Include the queue library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given a graph represented as an adjacency list and a source node, find the shortest path distances
// from the source node to all other nodes in the graph using BFS.

// Type of Shortest Path Problem:
// Single-Source Shortest Path (SSSP)

// Intuition:
// BFS is an efficient algorithm to compute shortest path distances in unweighted graphs.
// It traverses the graph level by level, ensuring that the shortest path to each node is discovered first.

// DSA Strategy/Pattern:
// Graph Traversal (Breadth-First Search)

// Approach:
// 1. Initialize a vector dist to store shortest path distances, initialized with -1 for unreachable nodes.
// 2. Enqueue the source node into a queue q and set its distance to 0.
// 3. While the queue is not empty, dequeue a node, and for each of its neighbors not visited yet,
//    update their distance to the current distance plus one and enqueue them.
// 4. Repeat step 3 until the queue is empty.
// 5. Return the vector dist containing the shortest path distances from the source node.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), where V is the number of vertices in the graph.

// Function to find the shortest path distances to all nodes from a source node in a graph
vector<int> shortestPath(const vector<vector<int>> &graph, int source)
{
    int n = graph.size();    // Number of nodes in the graph
    vector<int> dist(n, -1); // Initialize distances to -1 (indicating unreachable)
    queue<int> q;            // Queue for BFS traversal

    dist[source] = 0; // Distance from source to itself is 0
    q.push(source);   // Enqueue the source node

    // Perform BFS traversal to compute shortest path distances
    while (!q.empty())
    {
        int curr = q.front(); // Get the front node from the queue
        q.pop();              // Dequeue the front node

        // Traverse neighbors of the current node
        for (int neighbor : graph[curr])
        {
            if (dist[neighbor] == -1) // If neighbor is not visited yet
            {
                dist[neighbor] = dist[curr] + 1; // Update distance to neighbor
                q.push(neighbor);                // Enqueue the neighbor for further exploration
            }
        }
    }

    return dist; // Return the shortest path distances from the source node
}

int main()
{
    // Example usage
    vector<vector<int>> graph = {{1, 2}, {2}, {3}, {0}}; // Adjacency list representation of the graph
    int source = 0;                                      // Source node for computing shortest paths
    vector<int> dist = shortestPath(graph, source);      // Compute shortest path distances

    // Print shortest path distances from the source node to all other nodes
    for (int i = 0; i < dist.size(); i++)
    {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}
