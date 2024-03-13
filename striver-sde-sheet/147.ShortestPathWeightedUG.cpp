#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap to store vertices based on distance
    pq.push({0, source});                                                               // Push the source vertex with distance 0

    // Process vertices until the priority queue becomes empty
    while (!pq.empty())
    {
        int u = pq.top().second; // Get the vertex with minimum distance
        pq.pop();                // Remove the vertex from the priority queue

        // Traverse all adjacent vertices of the current vertex
        for (const Edge &edge : adjList[u])
        {
            int v = edge.dest;        // Destination vertex of the edge
            int weight = edge.weight; // Weight of the edge

            // Relax the edge if a shorter path is found
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Update the distance to the destination vertex
                pq.push({dist[v], v});      // Push the destination vertex with updated distance to the priority queue
            }
        }
    }

    return dist; // Return the array of shortest distances from the source vertex
}

int main()
{
    int numVertices = 6;                       // Number of vertices in the graph
    vector<vector<Edge>> adjList(numVertices); // Adjacency list representation of the graph

    // Populate the adjacency list with undirected edges and weights
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
