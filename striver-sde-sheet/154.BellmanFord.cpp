#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement:
// Given a weighted directed graph, find the shortest paths from a source vertex to all other vertices using the Bellman-Ford algorithm. The graph may contain negative-weight edges, but should not contain any negative-weight cycles.

// Intuition:
// Bellman-Ford algorithm works by iteratively relaxing edges in the graph. It repeatedly updates the shortest distances until convergence or until detecting the presence of negative-weight cycles. If there are no negative-weight cycles, after |V| - 1 iterations, where |V| is the number of vertices, the shortest paths are found.

// DSA Strategy/Pattern:
// Graph Algorithms, Bellman-Ford Algorithm

// Approach:
// Bellman-Ford Algorithm:
// 1. Initialize an array `distance` to store the shortest distances from the source vertex. Initialize all distances to INT_MAX, except the source vertex distance set to 0.
// 2. Iterate |V| - 1 times, where |V| is the number of vertices:
//    a. Iterate through all edges and relax each edge: if the distance to the source vertex plus the edge weight is shorter than the current distance to the destination vertex, update the distance.
// 3. Check for negative-weight cycles: Iterate through all edges again, and if relaxing any edge results in a shorter distance, it indicates the presence of a negative-weight cycle.
// 4. Return the array `distance` containing shortest distances from the source vertex to all other vertices.

// Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V), where V is the number of vertices


// Structure to represent an edge in the graph
struct Edge
{
    int source, destination, weight; // Source, destination, and weight of the edge
};

// Function to compute shortest paths using the Bellman-Ford algorithm
vector<int> bellmanFord(vector<Edge> &edges, int numVertices, int source)
{
    // Vector to store shortest distances
    vector<int> distance(numVertices, INT_MAX);
    // Distance from source vertex to itself is 0
    distance[source] = 0;

    // Relax edges repeatedly to find shortest paths
    for (int i = 1; i <= numVertices - 1; ++i)
    {
        // Iterate through all edges
        for (const auto &edge : edges)
        {
            int u = edge.source;      // Source vertex of the edge
            int v = edge.destination; // Destination vertex of the edge
            int w = edge.weight;      // Weight of the edge

            // If distance to u is not INT_MAX and distance to v through u is shorter, update distance to v
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto &edge : edges)
    {
        int u = edge.source;      // Source vertex of the edge
        int v = edge.destination; // Destination vertex of the edge
        int w = edge.weight;      // Weight of the edge

        // If distance to u is not INT_MAX and distance to v through u is shorter, a negative-weight cycle exists
        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Graph contains negative-weight cycle\n";
            return {-1}; // Return -1 to indicate failure
        }
    }

    return distance; // Return vector containing shortest distances from the source vertex
}

// Function to print distances from the source vertex to all other vertices
void printDistances(vector<int> &distance)
{
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < distance.size(); ++i)
    {
        cout << i << "\t" << distance[i] << "\n";
    }
}

// Main function
int main()
{
    // Example graph representation
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    int numVertices = 5; // Number of vertices in the graph
    int source = 0;      // Source vertex for computing shortest paths

    // Compute shortest paths from the source vertex
    vector<int> distance = bellmanFord(edges, numVertices, source);

    // Print distances from the source vertex to all other vertices
    printDistances(distance);

    return 0;
}
