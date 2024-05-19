#include <iostream> // Include the input/output stream library
#include <vector>   // Include the vector library
#include <queue>    // Include the queue library

using namespace std; // Use the standard namespace

// Problem Statement:
// Perform topological sorting on a directed acyclic graph (DAG).

// Intuition:
// Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG)
// such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

// DSA Strategy:
// We can use Breadth-First Search (BFS) to perform topological sorting.
// The idea is to calculate the in-degree of each vertex and enqueue vertices with in-degree 0.
// Then, repeatedly dequeue vertices, reduce the in-degree of their adjacent vertices, and enqueue vertices with in-degree 0.

// Approach:
// 1. Calculate the in-degree of each vertex by traversing the graph.
// 2. Enqueue vertices with in-degree 0 into a queue.
// 3. While the queue is not empty, dequeue a vertex, push it into the result vector, and reduce the in-degree of its adjacent vertices.
// 4. Enqueue vertices with in-degree 0 after decrementing the in-degree of their adjacent vertices.
// 5. Repeat steps 3-4 until the queue is empty.

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V), where V is the number of vertices.

// Function to perform topological sort using Breadth-First Search (BFS)
vector<int> topologicalSortBFS(vector<vector<int>> &graph)
{
    int n = graph.size(); // Get the number of vertices
    vector<int> inDegree(n, 0); // Create a vector to store the in-degree of each vertex

    // Calculate in-degree of each vertex
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int v = graph[i][j]; // Get the adjacent vertex
            inDegree[v]++;       // Increment the in-degree of the adjacent vertex
        }
    }

    queue<int> q; // Create a queue to perform BFS
    
    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i); // Enqueue the vertex with in-degree 0
        }
    }

    vector<int> result; // Create a vector to store the topologically sorted order

    while (!q.empty())
    {
        int u = q.front(); // Get the front vertex from the queue
        q.pop();           // Remove the front vertex from the queue
        result.push_back(u); // Push the vertex onto the result vector

        // Reduce in-degree of adjacent vertices
        for (int v: graph[u])
        {
            inDegree[v]--;       // Decrement the in-degree of the adjacent vertex
            if (inDegree[v] == 0)
            {
                q.push(v); // Enqueue the vertex with in-degree 0
            }
        }
    }

    return result; // Return the topologically sorted order
}

// Function to print the contents of a vector
void printVector(vector<int> &result)
{
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6; // Number of vertices in the graph

    // Initialize the adjacency list representation of the graph
    vector<vector<int>> graph(n);
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);

    // Perform topological sort using BFS and print the result
    vector<int> result = topologicalSortBFS(graph);
    cout << "Topological Sort Order: ";
    printVector(result);
    return 0;
}
