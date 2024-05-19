#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function to check for cycles using DFS
bool checkCycle(int u, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &inPath)
{
    visited[u] = true; // Mark the current node as visited
    inPath[u] = true;  // Mark the current node as being in the current path

    // Explore all the neighbors of the current node
    for (auto nbr : G[u])
    {
        if (!visited[nbr]) // If the neighbor hasn't been visited yet
        {
            if (checkCycle(nbr, G, visited, inPath))
                return true; // If a cycle is detected in the neighbor's DFS, return true
        }
        else if (inPath[nbr]) // If the neighbor is already in the current path, a cycle is detected
        {
            return true;
        }
    }
    inPath[u] = false; // Unmark the current node from the current path
    return false;
}

// Function to determine if all courses can be finished using cycle detection in DFS
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<bool> visited(numCourses, false); // To keep track of visited nodes
    vector<bool> inPath(numCourses, false);  // To keep track of nodes in the current path

    // Build the graph
    vector<vector<int>> G = vector<vector<int>>(numCourses, vector<int>());
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        G[u].push_back(v);
    }

    // Check for cycles in all components of the graph
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (checkCycle(i, G, visited, inPath))
                return false; // If a cycle is detected, return false
        }
    }
    return true; // No cycles detected, return true
}

// Function to determine if all courses can be finished using topological sorting (Kahn's algorithm)
bool canFinishTopoBFS(int V, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(V, 0); // To keep track of in-degrees of nodes
    vector<vector<int>> E = vector<vector<int>>(V, vector<int>());

    // Build the graph and calculate in-degrees
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        E[u].push_back(v);
        ++indegree[v];
    }
    queue<int> q;

    // Add all nodes with 0 in-degree to the queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0; // To count the number of nodes processed
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        count++;

        // Decrease the in-degree of all neighbors and add to the queue if in-degree becomes 0
        for (int neighbour : E[v])
        {
            if (--indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return count == V; // If all nodes are processed, return true; otherwise, false
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {2, 1}};
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}}; // This will have a cycle

    cout << canFinish(numCourses, prerequisites) << endl;        // Output the result of cycle detection
    cout << canFinishTopoBFS(numCourses, prerequisites) << endl; // Output the result of topological sort
    return 0;
}
