#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library
#include <climits>  // Include the limits library for INT_MAX

using namespace std; // Use the standard namespace

// Problem Statement:
// Given a weighted graph represented as an adjacency list and a source node,
// find the shortest distances from the source node to all other nodes using Dijkstra's algorithm.

// Intuition:
// Dijkstra's algorithm finds the shortest paths from a single source node to all other nodes in a weighted graph.
// It greedily selects the node with the smallest tentative distance and relaxes the distances of its neighbors.

// DSA Strategy/Pattern:
// Greedy Algorithm (Dijkstra's Algorithm)

// Type of Shortest Path Problem:
// Single-Source Shortest Path (SSSP)

// When this algorithm works and when it fails
// Dijkstra's algorithm works for graphs with non-negative edge weights and no negative cycles.
// It fails when the graph contains negative edge weights or negative cycles.

// Why priority queue is used in Dijkstra's algorithm and how it imporves the time complexity
// Priority queue is used in Dijkstra's algorithm to store nodes with the minimum distance.
// It allows the algorithm to select the node with the smallest tentative distance efficiently.
// By using a priority queue, the time complexity of Dijkstra's algorithm is improved to O((V + E) * log(V)),

// Approach:
// 1. Initialize all distances to infinity except for the source node, which is set to 0.
// 2. Create a priority queue to store nodes with the minimum distance. Push the source node with distance 0.
// 3. While the priority queue is not empty:
//    - Pop the node with the smallest tentative distance.
//    - For each adjacent node, if the distance through the current node is smaller than its current distance,
//      update the distance and push the node into the priority queue.
// 4. After the loop, the distances array contains the shortest distances from the source node to all other nodes.

// Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges in the graph.
//                  Each vertex and edge are visited at most once, and the priority queue operations take O(log(V)) time.
// Space Complexity: O(V), where V is the number of vertices, for storing the distances and the priority queue.

// Function to implement Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Initialize distances to infinity

    // Priority queue to store nodes with minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance of source node from itself is 0
    dist[source] = 0;

    // Push the source node into the priority queue
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Traverse all the adjacent nodes of u
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // If the distance to v through u is smaller than the current distance to v,
            // update the distance and push v into the priority queue
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    // Create a graph with 5 nodes and 8 edges
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    // Add edges to the graph
    graph[0].push_back(make_pair(1, 4));
    graph[0].push_back(make_pair(2, 8));
    graph[1].push_back(make_pair(2, 1));
    graph[1].push_back(make_pair(3, 2));
    graph[2].push_back(make_pair(3, 3));
    graph[3].push_back(make_pair(4, 6));

    // Call Dijkstra's algorithm to find the shortest distances from the source node
    int source = 0;
    vector<int> dist = dijkstra(graph, source);

    // Print the shortest distances from the source node
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
