#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <set>      // Include the set library
#include <climits>  // Include the limits library for INT_MAX

using namespace std; // Use the standard namespace

typedef pair<int, int> pii; // Typedef for pairs of integers

// Problem Statement:
// Given a weighted directed graph represented as an adjacency list and a source vertex,
// find the shortest distances from the source vertex to all other vertices using Dijkstra's algorithm.

// Intuition:
// Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a single source vertex
// to all other vertices in a weighted graph. It maintains a set of vertices whose shortest distance
// from the source is known and repeatedly selects the vertex with the minimum distance from the set.

// DSA Strategy/Pattern:
// Shortest Path Algorithm (Dijkstra's Algorithm) + Greedy Algorithm

// Type of Shortest Path Problem:
// Single-Source Shortest Path (SSSP)

// Why use set and how it improves the time complexity
// Set is used in Dijkstra's algorithm to store vertices sorted by their distances from the source.
// It allows the algorithm to select the vertex with the smallest tentative distance efficiently.
// By using a set, the time complexity of Dijkstra's algorithm is improved to O((V + E) * log(V)).

// Approach:
// 1. Initialize an array to store distances from the source vertex to all other vertices.
//    Initialize a set to store vertices sorted by their distances from the source.
// 2. Set the distance to the source vertex as 0 and insert it into the set.
// 3. Iterate until all vertices are processed:
//    - Extract the vertex with the minimum distance from the set.
//    - Relax all outgoing edges from the extracted vertex, updating distances and the set accordingly.
// 4. After the iteration, the distances array contains the shortest distances from the source vertex.

// Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
//                  Each vertex and edge are visited at most once during the algorithm, and set operations
//                  take logarithmic time.
// Space Complexity: O(V), where V is the number of vertices, for storing distances and the set.

// Function to find the shortest paths from a single source vertex using Dijkstra's algorithm
vector<int> dijkstra(int source, const vector<vector<pii>> &graph)
{
    int n = graph.size();         // Number of vertices in the graph
    vector<int> dist(n, INT_MAX); // Initialize distances with maximum value
    set<pii> set;                 // Set to store vertices sorted by their distances from the source

    dist[source] = 0;        // Distance from source to itself is 0
    set.insert({0, source}); // Insert the source vertex into the set with distance 0

    // Iterate until all vertices are processed
    while (!set.empty())
    {
        int u = set.begin()->second; // Extract the vertex with the minimum distance from the set
        set.erase(set.begin());      // Remove the extracted vertex from the set

        // Iterate over all adjacent vertices of the current vertex
        for (auto &edge : graph[u])
        {
            int v = edge.first;       // Destination vertex of the edge
            int weight = edge.second; // Weight of the edge

            // Relax the edge if a shorter path to the adjacent vertex is found
            if (dist[u] + weight < dist[v])
            {
                set.erase({dist[v], v});    // Remove the old distance-vertex pair from the set
                dist[v] = dist[u] + weight; // Update the distance to the adjacent vertex
                set.insert({dist[v], v});   // Insert the updated distance-vertex pair into the set
            }
        }
    }

    return dist; // Return the array of shortest distances from the source vertex
}

int main()
{
    int n = 5;                    // Number of vertices in the graph
    vector<vector<pii>> graph(n); // Adjacency list representation of the graph

    // Populate the adjacency list with directed edges and weights
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 8});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({3, 3});
    graph[3].push_back({4, 6});

    int source = 0; // Source vertex for computing shortest paths

    // Find shortest paths from the source vertex using Dijkstra's algorithm
    vector<int> dist = dijkstra(source, graph);

    // Print shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    return 0;
}
