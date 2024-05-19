#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Enum to represent the color of each vertex during DFS traversal for cycle detection
enum color
{
    WHITE, // Vertex has not been visited yet
    GRAY,  // Vertex is in the current path (being visited)
    BLACK  // Vertex and its descendants have been fully processed
};

class Graph
{
private:
    int V;                 // Number of vertices in the graph
    vector<vector<int>> E; // Adjacency list to represent edges

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        E = vector<vector<int>>(V, vector<int>()); // Initialize adjacency list for each vertex
    }

    // Function to add an edge between vertices u and v
    // If directed is true, add edge from u to v only
    // If directed is false, add edges both ways (u to v and v to u)
    void addEdge(int u, int v, bool directed)
    {
        E[u].push_back(v); // Add edge from u to v

        if (!directed)
            E[v].push_back(u); // If undirected, add edge from v to u
    }

    // Function to print the edges of the graph
    void printGraphEdges()
    {
        cout << "printing edges\n";
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

    // Recursive function to check for cycles in the graph using DFS
    bool checkCycle(int v, vector<color> &colored)
    {
        colored[v] = GRAY; // Mark the current vertex as being visited

        // Iterate through all adjacent vertices
        for (int neighbour : E[v])
        {
            if (colored[neighbour] == WHITE)
            {
                // If an adjacent vertex is unvisited, recursively visit it
                if (checkCycle(neighbour, colored))
                    return true; // If a cycle is detected, return true
            }
            else if (colored[neighbour] == GRAY)
                return true; // If an adjacent vertex is already being visited, a cycle is detected
        }
        colored[v] = BLACK; // Mark the current vertex as fully processed
        return false;       // No cycle detected in this path
    }

    // Function to detect if there is a cycle in the graph
    bool hasCycle()
    {
        vector<color> colored(V, WHITE); // Initialize all vertices as unvisited
        // Check each vertex for cycles
        for (int i = 0; i < V; i++)
        {
            if (colored[i] == WHITE)
            {
                if (checkCycle(i, colored))
                {
                    return true; // If a cycle is detected, return true
                }
            }
        }
        return false; // No cycle detected in the graph
    }
};

int main()
{
    // Create a graph with 4 vertices
    Graph g(4);

    // Add directed edges to the graph
    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 0, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 3, true);

    // Print the graph's edges
    g.printGraphEdges();

    // Check if the graph contains a cycle
    cout << g.hasCycle();
    return 0;
}
