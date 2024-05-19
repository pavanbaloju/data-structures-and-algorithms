#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

// Class representing a graph using adjacency list
class Graph
{
private:
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }

    // Function to add an edge between two vertices
    void addEdge(int u, int v)
    {
        // Add v to the adjacency list of u
        adjList[u].push_back(v);
        // For an undirected graph, also add u to the adjacency list of v
        // adjList[v].push_back(u);  // Uncomment this line for undirected graph
    }

    // Recursive DFS traversal starting from a given vertex
    void DFSRecursiveUtil(int v, vector<bool> &visited)
    {
        // Mark the current vertex as visited
        visited[v] = true;
        cout << v << " "; // Print the vertex

        // Recursively visit all the adjacent vertices that are not visited yet
        for (int u : adjList[v])
        {
            if (!visited[u])
            {
                DFSRecursiveUtil(u, visited);
            }
        }
    }

    // Function to perform DFS traversal recursively
    void DFSRecursive(int startVertex)
    {
        // Create a vector to keep track of visited vertices
        vector<bool> visited(V, false);

        // Start DFS traversal from the given startVertex
        DFSRecursiveUtil(startVertex, visited);
    }

    // Depth First Search (DFS) traversal of the graph starting from given vertex
    vector<int> DFSIterative(int startingVertex)
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
            cout << v << " ";

            // Iterate through all adjacent vertices of the popped vertex
            for (int i = 0; i < adjList[v].size(); i++)
            {
                if (!visited.count(adjList[v][i]))
                {
                    st.push(adjList[v][i]);        // Push unvisited adjacent vertices to the stack
                    visited.insert(adjList[v][i]); // Mark them as visited
                }
            }
        }

        return res; // Return the DFS traversal result
    }

    // Recursive BFS traversal starting from a given vertex
    void BFSRecursiveUtil(queue<int> &q, vector<bool> &visited)
    {
        if (q.empty())
        {
            return;
        }

        // Get the front vertex from the queue
        int v = q.front();
        q.pop();
        cout << v << " "; // Print the vertex

        // Recursively visit all the adjacent vertices that are not visited yet
        for (int u : adjList[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }

        // Recursively call BFS for the next level
        BFSRecursiveUtil(q, visited);
    }

    // Function to perform BFS traversal recursively
    void BFSRecursive(int startVertex)
    {
        // Create a queue for BFS traversal and a vector to keep track of visited vertices
        queue<int> q;
        vector<bool> visited(V, false);

        // Mark the startVertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        // Start BFS traversal recursively
        BFSRecursiveUtil(q, visited);
    }

    // Function to perform BFS traversal iteratively
    void BFSIterative(int startVertex)
    {
        // Create a queue for BFS traversal and a set to keep track of visited vertices
        queue<int> q;
        unordered_set<int> visited;

        // Enqueue the startVertex
        q.push(startVertex);
        visited.insert(startVertex);

        while (!q.empty())
        {
            // Get the front vertex from the queue
            int v = q.front();
            q.pop();
            cout << v << " "; // Print the vertex

            // Enqueue all unvisited adjacent vertices
            for (int u : adjList[v])
            {
                if (visited.find(u) == visited.end())
                {
                    q.push(u);
                    visited.insert(u);
                }
            }
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "DFS Recursive traversal starting from vertex 0: ";
    g.DFSRecursive(0);
    cout << endl;

    cout << "DFS Iterative traversal starting from vertex 0: ";
    g.DFSIterative(0);
    cout << endl;

    cout << "BFS Recursive traversal starting from vertex 0: ";
    g.BFSRecursive(0);
    cout << endl;

    cout << "BFS Iterative traversal starting from vertex 0: ";
    g.BFSIterative(0);
    cout << endl;

    return 0;
}
