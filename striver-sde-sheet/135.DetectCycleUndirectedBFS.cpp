#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleBFS(int numNodes, vector<vector<int>> &edges) // Function definition for detecting cycle using BFS
{
    vector<vector<int>> adjList(numNodes); // Create an adjacency list to represent the graph
    for (auto &edge : edges)               // Iterate through each edge in the edges vector
    {
        adjList[edge[0]].push_back(edge[1]); // Add the second vertex to the adjacency list of the first vertex
        adjList[edge[1]].push_back(edge[0]); // Add the first vertex to the adjacency list of the second vertex
    }

    vector<bool> visited(numNodes, false); // Create a visited array to keep track of visited vertices
    for (int u = 0; u < numNodes; ++u)     // Iterate through each vertex in the graph
    {
        if (!visited[u]) // If the vertex is not visited
        {
            queue<pair<int, int>> q; // Create a queue to perform BFS
            q.push({u, -1});         // Push the current vertex and its parent into the queue
            visited[u] = true;       // Mark the current vertex as visited
            while (!q.empty())       // While the queue is not empty
            {
                auto p = q.front();                      // Get the front element of the queue
                int currVertex = p.first;                // Get the current vertex
                int parent = p.second;                   // Get the parent of the current vertex
                q.pop();                                 // Pop the front element from the queue
                for (int neighbor : adjList[currVertex]) // Iterate through each neighbor of the current vertex
                {
                    if (!visited[neighbor]) // If the neighbor is not visited
                    {
                        visited[neighbor] = true;       // Mark the neighbor as visited
                        q.push({neighbor, currVertex}); // Push the neighbor and its parent into the queue
                    }
                    else if (neighbor != parent) // If the neighbor is visited and not the parent of the current vertex
                    {
                        return true; // Return true, indicating the presence of a cycle
                    }
                }
            }
        }
    }
    return false; // Return false, indicating the absence of a cycle
}

void printEdges(vector<vector<int>> &edges) // Function definition for printing edges
{
    cout << "printing edges\n";            // Print a message indicating the start of edge printing
    for (int i = 0; i < edges.size(); i++) // Iterate through each edge in the edges vector
    {
        cout << edges[i][0] << " ----> " << edges[i][1] << endl; // Print the edge in the format "vertex1 ----> vertex2"
    }
}

int main() // Main function
{
    int numNodes = 6;                                                                                    // Number of nodes in the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};                        // Edges of the graph
    printEdges(edges);                                                                                   // Print the edges of the graph
    cout << (hasCycleBFS(numNodes, edges) ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl; // Check if the graph has a cycle using BFS and print the result

    edges = {{0, 1}};                                                                                    // Edges of the graph
    printEdges(edges);                                                                                   // Print the edges of the graph
    cout << (hasCycleBFS(numNodes, edges) ? "Graph has a cycle" : "Graph doesn't have a cycle") << endl; // Check if the graph has a cycle using BFS and print the result

    return 0; // Return 0 to indicate successful execution of the program
}
