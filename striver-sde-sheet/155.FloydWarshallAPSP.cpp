#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Problem Statement:
// Given a weighted directed graph, find the shortest paths between all pairs of vertices using the Floyd-Warshall algorithm. The graph may contain negative-weight edges, but should not contain any negative-weight cycles.

// Intuition:
// The Floyd-Warshall algorithm finds the shortest paths between all pairs of vertices by considering all intermediate vertices in a weighted directed graph. It works efficiently even for graphs with negative-weight edges but no negative-weight cycles.

// DSA Strategy/Pattern:
// Graph Algorithms, Floyd-Warshall Algorithm

// Approach:
// Floyd-Warshall Algorithm:
// 1. Initialize a distance matrix `dist` of size VxV (where V is the number of vertices) to store the shortest distances between all pairs of vertices.
// 2. Initialize `dist[i][j]` to the weight of the edge from vertex i to vertex j, or INT_MAX if there is no edge.
// 3. Iterate through all vertices k from 0 to V-1:
//    a. For each pair of vertices i and j, if vertex k is on the shortest path from i to j, update `dist[i][j]` to the minimum of `dist[i][j]` and the sum of `dist[i][k]` and `dist[k][j]`.
// 4. Return the distance matrix `dist` containing shortest distances between all pairs of vertices.

// Time Complexity: O(V^3), where V is the number of vertices
// Space Complexity: O(V^2), where V is the number of vertices


// Function to compute all-pairs shortest paths using the Floyd-Warshall algorithm
vector<vector<int>> floydWarshall(vector<vector<int>> &graph)
{
    int V = graph.size(); // Number of vertices in the graph

    // Initialize the distance matrix
    vector<vector<int>> dist(V, vector<int>(V, -1));

    // Set unreachable vertices to INT_MAX and initialize other distances
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            dist[i][j] = graph[i][j] != -1 ? graph[i][j] : INT_MAX;
        }
    }

    // Update the distance matrix by considering all intermediate vertices
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist; // Return the distance matrix containing shortest distances between all pairs of vertices
}

// Function to print the distance matrix containing shortest distances between all pairs of vertices
void printDistances(vector<vector<int>> &dist)
{
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < dist.size(); ++i)
    {
        for (int j = 0; j < dist[i].size(); ++j)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF\t"; // Print 'INF' for unreachable vertices
            }
            else
            {
                cout << dist[i][j] << "\t"; // Print the shortest distance
            }
        }
        cout << "\n";
    }
}

// Main function
int main()
{
    // Graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 5, -1, 10},
        {-1, 0, 3, -1},
        {-1, -1, 0, 1},
        {-1, -1, -1, 0}};

    // Run the Floyd-Warshall algorithm to compute the shortest distances
    vector<vector<int>> dist = floydWarshall(graph);

    // Print the distance matrix
    printDistances(dist);

    return 0;
}
