#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and fill the stack with topological ordering
void dfsTopo(int node, vector<bool> &visited, vector<int> adj[], stack<int> &st)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfsTopo(neighbor, visited, adj, st);
        }
    }
    st.push(node); // Push the current node onto the stack after visiting all neighbors
}

// Function to find the shortest paths from a source vertex in a DAG
vector<int> shortestPathDAG(int V, vector<int> adj[], int source)
{
    vector<int> dist(V, INT_MAX);   // Initialize distances with infinity
    stack<int> st;                  // Stack for topological ordering
    vector<bool> visited(V, false); // Array to track visited vertices

    // Step 1: Perform DFS and fill the stack with topological ordering
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            dfsTopo(i, visited, adj, st);
        }
    }

    dist[source] = 0; // Distance from source to itself is 0

    // Step 2: Traverse vertices in topological order and relax the edges
    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (dist[u] != INT_MAX)
        {
            for (int v : adj[u])
            {
                if (dist[u] + 1 < dist[v])
                {
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }

    return dist;
}

int main()
{
    int V = 6;          // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Add directed edges to the DAG
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);

    int source = 0; // Source vertex for computing shortest paths

    // Compute shortest paths from the source vertex in the DAG
    vector<int> dist = shortestPathDAG(V, adj, source);

    // Print shortest path distances from the source vertex
    cout << "Shortest path distances from vertex " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Distance to vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
