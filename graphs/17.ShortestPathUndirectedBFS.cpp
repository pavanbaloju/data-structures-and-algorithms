#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;                 // Number of vertices
    vector<vector<int>> E; // Adjacency list representation of the graph

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        E = vector<vector<int>>(V, vector<int>());
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool directed)
    {
        E[u].push_back(v); // Add edge from u to v

        if (!directed)
            E[v].push_back(u); // If the graph is undirected, add edge from v to u as well
    }

    // Function to print the edges of the graph
    void printGraphEdges()
    {
        cout << "Printing edges\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ----> ";
            for (int j = 0; j < E[i].size(); j++)
            {
                cout << E[i][j] << " "; // Print all adjacent vertices of vertex i
            }
            cout << endl;
        }
    }

    // Function to find the shortest path from src to dest using BFS
    vector<int> shortestPath(int src, int dest)
    {
        vector<bool> visited(V, false); // To keep track of visited vertices
        queue<int> q;                   // Queue for BFS
        vector<int> parent(V, -1);      // Array to store the parent of each vertex in the path

        q.push(src);         // Start BFS from the source vertex
        visited[src] = true; // Mark the source vertex as visited
        parent[src] = -1;    // Source vertex has no parent

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            // Visit all the adjacent vertices of the current vertex
            for (int neigh : E[v])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true; // Mark the vertex as visited
                    parent[neigh] = v;     // Set the parent of the vertex
                }
            }
        }

        // To reconstruct the path from src to dest
        vector<int> ans;
        int cur = dest;
        ans.push_back(cur); // Start from the destination

        // Trace back the path from destination to source using the parent array
        while (cur != src)
        {
            cur = parent[cur];
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end()); // Reverse the path to get it in the correct order
        return ans;
    }
};

int main()
{
    Graph g(8); // Create a graph with 8 vertices

    // Add edges to the graph
    g.addEdge(0, 1, false);
    g.addEdge(0, 3, false);
    g.addEdge(1, 2, false);
    g.addEdge(3, 4, false);
    g.addEdge(3, 7, false);
    g.addEdge(4, 5, false);
    g.addEdge(4, 6, false);
    g.addEdge(4, 7, false);
    g.addEdge(5, 6, false);
    g.addEdge(6, 7, false);

    g.printGraphEdges(); // Print all edges of the graph

    // Find the shortest path from vertex 0 to vertex 7
    vector<int> ans = g.shortestPath(0, 7);

    // Print the shortest path
    cout << "Shortest path from 0 to 7: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
