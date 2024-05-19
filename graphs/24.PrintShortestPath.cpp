#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library
#include <climits>  // Include the limits library for INT_MAX

using namespace std; // Use the standard namespace

// Structure to represent a node in the graph
struct Node
{
    int id;     // Node ID
    int weight; // Weight of the edge to this node
};

// Problem Statement:
// Given a weighted directed graph represented as an adjacency list and a source and destination node,
// find the shortest path from the source node to the destination node using Dijkstra's algorithm.

// Intuition:
// Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a single source vertex
// to all other vertices in a weighted graph. It maintains a set of vertices whose shortest distance
// from the source is known and repeatedly selects the vertex with the minimum distance from the set.

// DSA Strategy/Pattern:
// Shortest Path Algorithm (Dijkstra's Algorithm) + Greedy Algorithm

// Approach:
// 1. Initialize an array to store distances from the source vertex to all other vertices.
//    Initialize a parent array to reconstruct the shortest path.
//    Initialize a visited array to mark visited nodes.
//    Initialize a priority queue to store nodes with minimum distance.
// 2. Set the distance to the source node as 0 and push it onto the priority queue.
// 3. Perform Dijkstra's algorithm:
//    - Extract the node with the minimum distance from the priority queue.
//    - Relax all outgoing edges from the extracted node, updating distances and the priority queue.
// 4. Reconstruct the shortest path from destination to source using the parent array.
// 5. Return the shortest path.

// Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
//                  Each vertex and edge are visited at most once during the algorithm, and priority queue
//                  operations take logarithmic time.
// Space Complexity: O(V), where V is the number of vertices, for storing distances, parent array, and visited array.

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra(vector<vector<Node>> &graph, int source, int destination)
{
    int n = graph.size();           // Number of nodes in the graph
    vector<int> dist(n, INT_MAX);   // Initialize distances with maximum value
    vector<int> parent(n, -1);      // Initialize parent array
    vector<bool> visited(n, false); // Initialize visited array

    dist[source] = 0; // Distance from source to itself is 0

    // Priority queue to store nodes with minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Push the source node with distance 0 onto the priority queue

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        int u = pq.top().second; // Get the node with minimum distance from the priority queue
        pq.pop();                // Remove the node from the priority queue

        visited[u] = true; // Mark the node as visited

        // Traverse all neighbors of the current node
        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.id;          // Neighbor ID
            int weight = neighbor.weight; // Weight of the edge to the neighbor

            // Relax the edge if a shorter path is found
            if (!visited[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight; // Update the distance to the neighbor
                parent[v] = u;              // Update the parent of the neighbor
                pq.push({dist[v], v});      // Push the neighbor with updated distance onto the priority queue
            }
        }
    }

    // Reconstruct the shortest path from destination to source
    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);   // Add the current node to the path
        current = parent[current]; // Move to the parent node
    }

    reverse(path.begin(), path.end()); // Reverse the path to get source to destination order

    return path; // Return the shortest path from source to destination
}

int main()
{
    // Example usage
    int n = 6;                     // Number of nodes in the graph
    vector<vector<Node>> graph(n); // Adjacency list representation of the graph

    // Add edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 2});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, 5});

    int source = 0;      // Source node
    int destination = 5; // Destination node

    // Find the shortest path from source to destination
    vector<int> shortestPath = dijkstra(graph, source, destination);

    // Print the shortest path
    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int node : shortestPath)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
