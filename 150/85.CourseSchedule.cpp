#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkCycle(int u, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &inPath)
{
    visited[u] = true;
    inPath[u] = true;

    for (auto nbr : G[u])
    {
        if (!visited[nbr])
        {
            if (checkCycle(nbr, G, visited, inPath))
                return true;
        }
        else if (inPath[nbr])
        {
            return true;
        }
    }
    inPath[u] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<bool> visited(numCourses, false);
    vector<bool> inPath(numCourses, false);

    vector<vector<int>> G = vector<vector<int>>(numCourses, vector<int>());
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        G[u].push_back(v);
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (checkCycle(i, G, visited, inPath))
                return false;
        }
    }
    return true;
}

bool canFinishTopoBFS(int V, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(V, 0);
    vector<vector<int>> E = vector<vector<int>>(V, vector<int>());
    for (vector<int> pre : prerequisites)
    {
        int v = pre[0], u = pre[1];
        E[u].push_back(v);
        ++indegree[v];
    }
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        count++;

        for (int neighbour : E[v])
        {
            if (--indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return count == V;
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {2, 1}};
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}};

    cout << canFinish(numCourses, prerequisites) << endl;
    cout << canFinishTopoBFS(numCourses, prerequisites) << endl;
    return 0;
}