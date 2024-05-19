#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library
#include <climits>  // Include the limits library for INT_MAX

using namespace std; // Use the standard namespace

// Problem Statement:
// Given a weighted directed graph represented as an adjacency list and a source vertex,
// find the shortest distances from the source vertex to all other vertices using BFS.

// Intuition:
// Using BFS (Breadth-First Search) to find shortest paths in a graph is applicable when
// the graph has non-negative edge weights. BFS traverses the graph level by level,
// ensuring that the shortest paths are explored first.

// DSA Strategy/Pattern:
// Graph Traversal (BFS) + Shortest Path Algorithm (Relaxation)

// Approach:
// 1. Initialize all distances to infinity except for the source vertex, which is set to 0.
// 2. Create a queue to store vertices to be processed. Enqueue the source vertex with distance 0.
// 3. While the queue is not empty:
//    - Dequeue a vertex u from the queue.
//    - Traverse all adjacent vertices of u.
//    - If the distance to v through u is smaller than the current distance to v, update the distance to v.
//    - Enqueue v into the queue if its distance is updated.
// 4. After the loop, the distances array contains the shortest distances from the source vertex to all other vertices.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
//                  Each vertex and edge are visited at most once.
// Space Complexity: O(V), where V is the number of vertices, for storing the distances and the queue.

// Structure to represent an edge in the graph
struct Edge
{
    int dest;   // Destination vertex of the edge
    int weight; // Weight of the edge
};

// Function to find the shortest path from a source vertex to all other vertices in the graph
vector<int> shortestPath(int source, int numVertices, const vector<vector<Edge>> &adjList)
{
    vector<int> dist(numVertices, INT_MAX); // Initialize distances with maximum value
    dist[source] = 0;                       // Distance from source to itself is 0

    queue<pair<int, int>> q; // Min heap to store vertices based on distance
    q.push({0, source});     // Push the source vertex with distance 0

    // Process vertices until the priority queue becomes empty
    while (!q.empty())
    {
        int u = q.front().second; // Get the vertex with minimum distance
        q.pop();                  // Remove the vertex from the priority queue

        // Traverse all adjacent vertices of the current vertex
        for (const Edge &edge : adjList[u])
        {
            int v = edge.dest;        // Destination vertex of the edge
            int weight = edge.weight; // Weight of the edge

            // Relax the edge if a shorter path is found
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Update the distance to the destination vertex
                q.push({dist[v], v});       // Push the destination vertex with updated distance to the priority queue
            }
        }
    }

    return dist; // Return the array of shortest distances from the source vertex
}

int main()
{
    int numVertices = 6;                       // Number of vertices in the graph
    vector<vector<Edge>> adjList(numVertices); // Adjacency list representation of the graph

    // Populate the adjacency list with directed edges and weights
    adjList[0].push_back({1, 5});
    adjList[0].push_back({2, 3});
    adjList[1].push_back({3, 6});
    adjList[1].push_back({2, 2});
    adjList[2].push_back({4, 4});
    adjList[2].push_back({5, 2});
    adjList[2].push_back({4, 2});
    adjList[3].push_back({4, 6});
    adjList[3].push_back({5, 7});
    adjList[4].push_back({5, 1});

    int source = 0; // Source vertex for computing shortest paths

    // Find shortest paths from the source vertex
    vector<int> dist = shortestPath(source, numVertices, adjList);

    // Print shortest distances from the source vertex to all other vertices
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Shortest distance from vertex " << source << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}
