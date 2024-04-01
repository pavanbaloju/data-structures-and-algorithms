#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
// Problem Statement:
// Given an undirected graph with weighted edges, the task is to find the minimum spanning tree (MST) using Prim's algorithm.

// Intuition:
// Prim's algorithm starts with an arbitrary vertex and grows the minimum spanning tree by adding the shortest edge 
// that connects a vertex in the MST to a vertex outside the MST until all vertices are included in the tree.
// The algorithm uses a priority queue to store the vertices and their weights, and it selects the vertex with the minimum weight at each step.


// DSA Strategy/Pattern:
// Graph Algorithms, Minimum Spanning Tree, Prim's Algorithm

// Approach:
// Prim's Algorithm:
// 1. Create a priority queue to store nodes (vertex, weight) where the weight represents the minimum weight of the edge that connects the vertex to the minimum spanning tree (MST).
// 2. Initialize two vectors: minWeight and parent. minWeight stores the minimum weight of each vertex in the MST, and parent stores the parent of each vertex in the MST.
// 3. Start with an arbitrary vertex as the starting point and set its minWeight to 0. Push this vertex into the priority queue.
// 4. While the priority queue is not empty:
//    a. Pop the vertex with the minimum weight from the priority queue.
//    b. If the vertex is already visited, skip it.
//    c. Mark the vertex as visited.
//    d. Traverse all adjacent vertices of the current vertex:
//       i. If the neighbor is not visited and the weight of the edge is smaller than its current minWeight, update the minWeight and parent of the neighbor, and push it into the priority queue.
// 5. Print the minimum spanning tree edges and their total weight.

// Time Complexity: O(E log V), where E is the number of edges and V is the number of vertices
// Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges

// Structure to represent a node in the graph
struct Node
{
    int vertex;
    int weight;

    Node(int vertex, int weight) : vertex(vertex), weight(weight) {}

    bool operator>(const Node &other) const
    {
        return weight > other.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Node>> &graph, int startVertex)
{
    int numVertices = graph.size();

    // Create a vector to store the minimum weight of each vertex
    vector<int> minWeight(numVertices, INT_MAX);

    // Create a vector to store the parent of each vertex in the MST
    vector<int> parent(numVertices, -1);

    // Create a vector to keep track of visited vertices
    vector<bool> visited(numVertices, false);

    // Create a priority queue to store the nodes
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Start with the given start vertex
    minWeight[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty())
    {
        // Get the vertex with the minimum weight
        int currentVertex = pq.top().vertex;
        pq.pop();

        // if the vertex is already visited, skip it
        if (visited[currentVertex])
        {
            continue;
        }

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Traverse all the adjacent vertices of the current vertex
        for (const auto &neighbor : graph[currentVertex])
        {
            int neighborVertex = neighbor.vertex;
            int neighborWeight = neighbor.weight;

            // If the neighbor is not visited and the weight is smaller than the current minimum weight
            if (!visited[neighborVertex] && neighborWeight < minWeight[neighborVertex])
            {
                // Update the minimum weight and parent of the neighbor
                minWeight[neighborVertex] = neighborWeight;
                parent[neighborVertex] = currentVertex;

                // Push the neighbor into the priority queue
                pq.push({neighborVertex, neighborWeight});
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    // Print the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < numVertices; i++)
    {
        totalWeight += minWeight[i];
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main()
{
    // Create a graph with 5 vertices
    int numVertices = 5;
    vector<vector<Node>> graph(numVertices);

    // Add edges to the graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    // Find the minimum spanning tree using Prim's algorithm
    primMST(graph, 0);

    return 0;
}
