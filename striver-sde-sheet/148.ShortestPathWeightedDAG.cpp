#include <iostream>
#include <vector>
#include <stack>
#include <climits> // For INT_MAX

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int dest;   // Destination vertex of the edge
    int weight; // Weight of the edge (for weighted graphs)
};

// Perform topological sorting of vertices in the DAG
void topologicalSort(int v, const vector<vector<Edge>> &adjList, vector<bool> &visited, stack<int> &stk)
{
    visited[v] = true; // Mark the current vertex as visited
    // Visit all adjacent vertices of the current vertex
    for (const Edge &edge : adjList[v])
    {
        // If an adjacent vertex is not visited, perform topological sorting recursively
        if (!visited[edge.dest])
        {
            topologicalSort(edge.dest, adjList, visited, stk);
        }
    }
    // Push the current vertex onto the stack after all its adjacent vertices are visited
    stk.push(v);
}

// Find the shortest path from the given source vertex in the DAG
vector<int> shortestPathDAG(int source, int numVertices, const vector<vector<Edge>> &adjList)
{
    vector<bool> visited(numVertices, false); // Initialize visited array to mark visited vertices
    stack<int> stk; // Stack to store vertices in topological order

    // Perform topological sorting of vertices
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, adjList, visited, stk);
        }
    }

    vector<int> dist(numVertices, INT_MAX); // Initialize distance array with maximum values
    dist[source] = 0; // Distance from source to itself is 0

    // Traverse vertices in topological order and relax edges
    while (!stk.empty())
    {
        int u = stk.top(); // Get the top vertex from the stack
        stk.pop(); // Remove the top vertex from the stack

        // If the distance to the current vertex is not maximum
        if (dist[u] != INT_MAX)
        {
            // Iterate over all adjacent vertices of the current vertex
            for (const Edge &edge : adjList[u])
            {
                // Relax the edge if a shorter path is found
                if (dist[u] + edge.weight < dist[edge.dest])
                {
                    dist[edge.dest] = dist[u] + edge.weight;
                }
            }
        }
    }

    return dist; // Return the array of shortest distances from the source vertex
}

int main()
{
    int numVertices = 6; // Number of vertices in the graph
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
    vector<int> dist = shortestPathDAG(source, numVertices, adjList);

    // Print shortest distances from the source vertex to all other vertices
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Shortest distance from vertex " << source << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}
