#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph
{
private:
    int V;                 // Number of vertices in the graph
    vector<vector<int>> E; // Adjacency list representation of the graph

public:
    Graph(int noOfVertices)
    {
        V = noOfVertices;                          // Initialize the number of vertices
        E = vector<vector<int>>(V, vector<int>()); // Initialize adjacency list with V empty vectors
    }

    // Function to add an edge between vertices u and v
    // If directed is true, adds an edge from u to v only
    // If directed is false, adds edges from both u to v and v to u
    void addEdge(int u, int v, bool directed)
    {
        E[u].push_back(v); // Add v to the adjacency list of u

        if (!directed)
            E[v].push_back(u); // If undirected, add u to the adjacency list of v
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
                cout << E[i][j] << " "; // Print the vertices connected to vertex i
            }
            cout << endl;
        }
    }

    // Breadth First Search (BFS) traversal of the graph starting from given vertex
    vector<int> bfs(int startingVertex)
    {
        vector<int> res;               // Result vector to store BFS traversal
        queue<int> q;                  // Queue for BFS traversal
        unordered_set<int> visited(V); // Set to keep track of visited vertices

        q.push(startingVertex);         // Enqueue the starting vertex
        visited.insert(startingVertex); // Mark the starting vertex as visited

        while (!q.empty())
        {
            int v = q.front(); // Get the front vertex from the queue
            q.pop();           // Dequeue the front vertex
            res.push_back(v);  // Push the dequeued vertex to the result

            // Iterate through all adjacent vertices of the dequeued vertex
            for (int i = 0; i < E[v].size(); i++)
            {
                if (!visited.count(E[v][i]))
                {
                    q.push(E[v][i]);         // Enqueue unvisited adjacent vertices
                    visited.insert(E[v][i]); // Mark them as visited
                }
            }
        }

        return res; // Return the BFS traversal result
    }

    // Depth First Search (DFS) traversal of the graph starting from given vertex
    vector<int> dfs(int startingVertex)
    {
        vector<int> res;               // Result vector to store DFS traversal
        stack<int> st;                 // Stack for DFS traversal
        unordered_set<int> visited(V); // Set to keep track of visited vertices

        st.push(startingVertex);        // Push the starting vertex to the stack
        visited.insert(startingVertex); // Mark the starting vertex as visited

        while (!st.empty())
        {
            int v = st.top(); // Get the top vertex from the stack
            st.pop();         // Pop the top vertex
            res.push_back(v); // Push the popped vertex to the result

            // Iterate through all adjacent vertices of the popped vertex
            for (int i = 0; i < E[v].size(); i++)
            {
                if (!visited.count(E[v][i]))
                {
                    st.push(E[v][i]);        // Push unvisited adjacent vertices to the stack
                    visited.insert(E[v][i]); // Mark them as visited
                }
            }
        }

        return res; // Return the DFS traversal result
    }
};

int main()
{
    Graph g = Graph(4);    // Create a graph with 4 vertices
    g.addEdge(0, 1, true); // Add directed edges to the graph
    g.addEdge(0, 2, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 0, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 3, true);

    g.printGraphEdges(); // Print the edges of the graph

    vector<int> bfs = g.bfs(2); // Perform BFS traversal starting from vertex 2
    cout << "bfs" << endl;
    for (int v : bfs)
        cout << v << " "; // Print BFS traversal result
    cout << endl;

    vector<int> dfs = g.dfs(2); // Perform DFS traversal starting from vertex 2
    cout << "dfs" << endl;
    for (int v : dfs)
        cout << v << " "; // Print DFS traversal result
    cout << endl;
    return 0;
}
