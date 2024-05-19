#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Recursive function to perform topological sort
void toposort(int u, vector<vector<int>> &G, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true; // Mark the current node as visited
    for (auto nbr : G[u])
    {
        if (!visited[nbr])
        {
            toposort(nbr, G, visited, ans); // Recursively visit all adjacent nodes
        }
    }
    ans.push_back(u); // Add the current node to the topological sort
}

// Function to detect a cycle in the graph
bool checkCycle(int u, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &inPath, vector<int> &ans)
{
    visited[u] = true; // Mark the current node as visited
    inPath[u] = true;  // Mark the current node as part of the current path

    for (auto nbr : G[u])
    {
        if (!visited[nbr])
        {
            if (checkCycle(nbr, G, visited, inPath, ans))
                return true; // Cycle detected
        }
        else if (inPath[nbr])
        {
            return true; // Cycle detected
        }
    }
    ans.push_back(u);  // Add the current node to the topological sort
    inPath[u] = false; // Unmark the current node as part of the current path
    return false;      // No cycle detected
}

// Function to find the order of courses to be taken using DFS
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<bool> visited(numCourses, false);
    vector<bool> inPath(numCourses, false);
    vector<int> ans;

    // Create the adjacency list for the graph
    vector<vector<int>> G = vector<vector<int>>(numCourses, vector<int>());
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        G[u].push_back(v);
    }

    // Check for cycles and perform topological sort
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (checkCycle(i, G, visited, inPath, ans))
                return {}; // If a cycle is detected, return an empty list
        }
    }
    reverse(ans.begin(), ans.end()); // Reverse the topological sort to get the correct order
    return ans;
}

// Function to find the order of courses to be taken using Kahn's Algorithm (BFS)
vector<int> findOrderTopoBFS(int V, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(V, 0);
    vector<vector<int>> E = vector<vector<int>>(V, vector<int>());

    // Create the adjacency list and compute in-degrees
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        E[u].push_back(v);
        ++indegree[v];
    }
    queue<int> q;

    // Push all nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        ans.push_back(v);

        // Decrease the in-degree of all adjacent nodes and push nodes with in-degree 0 into the queue
        for (int neighbour : E[v])
        {
            if (--indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    // If the size of the result is equal to the number of vertices, return the result; otherwise, return an empty list
    return ans.size() == V ? ans : vector<int>();
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {2, 1}};
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}};

    // Test the BFS-based topological sort
    vector<int> order = findOrderTopoBFS(numCourses, prerequisites);
    for (auto course : order)
        cout << course << " ";
    cout << endl;

    // Test the DFS-based topological sort
    order = findOrder(numCourses, prerequisites);
    for (auto course : order)
        cout << course << " ";
    return 0;
}
