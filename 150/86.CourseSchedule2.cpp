#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void toposort(int u, vector<vector<int>> &G, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true;
    for (auto nbr : G[u])
    {
        if (!visited[nbr])
        {
            toposort(nbr, G, visited, ans);
        }
    }
    ans.push_back(u);
}

bool checkCycle(int u, vector<vector<int>> &G, vector<bool> &visited, vector<bool> &inPath, vector<int> &ans)
{
    visited[u] = true;
    inPath[u] = true;

    for (auto nbr : G[u])
    {
        if (!visited[nbr])
        {
            if (checkCycle(nbr, G, visited, inPath, ans))
                return true;
        }
        else if (inPath[nbr])
        {
            return true;
        }
    }
    ans.push_back(u);
    inPath[u] = false;
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<bool> visited(numCourses, false);
    vector<bool> inPath(numCourses, false);
    vector<int> ans;

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
            if (checkCycle(i, G, visited, inPath, ans))
                return {};
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> findOrderTopoBFS(int V, vector<vector<int>> &prerequisites)
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

    vector<int> ans;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        ans.push_back(v);

        for (int neighbour : E[v])
        {
            if (--indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans.size() == V ? ans : vector<int>();
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {2, 1}};
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}};

    vector<int> order = findOrderTopoBFS(numCourses, prerequisites);
    for (auto course : order)
        cout << course << " ";
    cout << endl;

    order = findOrder(numCourses, prerequisites);
    for (auto course : order)
        cout << course << " ";
    return 0;
}