#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth First Traversal (BFS)
// Problem Statement: Perform Breadth First Search (BFS) traversal on a graph represented using an adjacency list.
// Intuition: BFS explores vertices in levels, visiting all neighbors of a vertex before moving to the next level.
// DSA strategy used: BFS, Queue
// Approach:
// 1. Create a boolean array 'visited' to keep track of visited vertices.
// 2. Create a queue to store vertices for BFS traversal.
// 3. Mark the start vertex as visited and enqueue it.
// 4. While the queue is not empty:
//    a. Dequeue a vertex from the queue and print it.
//    b. Enqueue all unvisited neighbors of the dequeued vertex and mark them as visited.
// 5. Repeat steps 4 until the queue is empty.
void bfs(vector<vector<int>> &adjList, int startVertex)
{
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false); // Initialize a boolean array to keep track of visited vertices
    queue<int> q; // Initialize a queue for BFS traversal

    visited[startVertex] = true; // Mark the start vertex as visited
    q.push(startVertex); // Enqueue the start vertex

    while (!q.empty())
    {
        int currVertex = q.front(); // Get the front vertex from the queue
        q.pop(); // Dequeue the front vertex
        cout << currVertex << " "; // Print the current vertex

        // Visit all adjacent vertices of the current vertex
        for (int neighbor : adjList[currVertex])
        {
            if (!visited[neighbor]) // If neighbor is not visited yet
            {
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor); // Enqueue the neighbor for further traversal
            }
        }
    }
}

// Function to perform Depth First Traversal (DFS) - Utility function
void dfsUtil(vector<vector<int>> &adjList, int currVertex, vector<bool> &visited)
{
    visited[currVertex] = true; // Mark the current vertex as visited
    cout << currVertex << " "; // Print the current vertex

    // Visit all adjacent vertices of the current vertex
    for (int neighbor : adjList[currVertex])
    {
        if (!visited[neighbor]) // If neighbor is not visited yet
        {
            dfsUtil(adjList, neighbor, visited); // Recursively visit unvisited neighbors
        }
    }
}

// Function to perform Depth First Traversal (DFS)
// Problem Statement: Perform Depth First Search (DFS) traversal on a graph represented using an adjacency list.
// Intuition: DFS explores vertices as far as possible along each branch before backtracking.
// DSA strategy used: DFS, Recursion
// Approach:
// 1. Create a boolean array 'visited' to keep track of visited vertices.
// 2. Call a utility function 'dfsUtil' for DFS traversal starting from the given start vertex.
void dfs(vector<vector<int>> &adjList, int startVertex)
{
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false); // Initialize a boolean array to keep track of visited vertices

    dfsUtil(adjList, startVertex, visited); // Start DFS traversal from the given start vertex
}

int main()
{
    int numVertices = 5;
    vector<vector<int>> adjList(numVertices);

    // Define the adjacency list for the graph
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[3].push_back(3);
    adjList[4].push_back(4);

    // Perform BFS traversal starting from vertex 2
    cout << "BFS Traversal: ";
    bfs(adjList, 2);
    cout << endl;

    // Perform DFS traversal starting from vertex 2
    cout << "DFS Traversal: ";
    dfs(adjList, 2);
    cout << endl;

    return 0;
}
