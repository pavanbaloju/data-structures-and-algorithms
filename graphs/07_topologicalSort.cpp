#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class representing a directed or undirected graph and providing graph operations.
class Graph
{
private:
    int V; // Number of vertices in the graph.
    vector<vector<int>> E; // Adjacency list representation of the graph.

public:
    // Constructor to initialize the graph with a given number of vertices.
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        E = vector<vector<int>>(V, vector<int>());
    }

    // Function to add an edge between vertices u and v in the graph.
    // If the graph is undirected, an edge between v and u is also added.
    void addEdge(int u, int v, bool directed)
    {
        E[u].push_back(v); // Add edge from u to v.

        if (!directed)
            E[v].push_back(u); // If undirected, add edge from v to u.
    }

    // Function to print the edges of the graph.
    void printGraphEdges()
    {
        cout << "printing edges\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ----> ";
            for (int j = 0; j < E[i].size(); j++)
            {
                cout << E[i][j] << " "; // Print all adjacent vertices of vertex i.
            }
            cout << endl;
        }
    }

    // Function to perform depth-first search for topological sorting starting from vertex v.
    void topologicalSort(int v, vector<bool> &visited, stack<int> &st)
    {
        visited[v] = true; // Mark vertex v as visited.

        // Traverse all adjacent vertices of vertex v.
        for (int n : E[v])
        {
            if (!visited[n]) // If adjacent vertex is not visited, recursively perform topological sort.
            {
                topologicalSort(n, visited, st);
            }
        }
        st.push(v); // Push vertex v onto stack after visiting all its adjacent vertices.
    }

    // Function to perform topological sort on the graph.
    vector<int> topoSort()
    {
        vector<bool> visited(V, false); // Array to mark visited vertices.
        stack<int> st; // Stack to store vertices in topologically sorted order.
        vector<int> ans; // Vector to store topologically sorted vertices.

        // Perform topological sort starting from each unvisited vertex.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSort(i, visited, st);
            }
        }

        // Pop vertices from stack and store them in the result vector.
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans; // Return the topologically sorted vertices.
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2, true);
    g.addEdge(5, 0, true);
    g.addEdge(4, 0, true);
    g.addEdge(4, 1, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 1, true);

    g.printGraphEdges();
    vector<int> ans = g.topoSort();

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}