#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> E;

public:
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        E = vector<vector<int>>(V, vector<int>());
    }

    void addEdge(int u, int v, bool directed)
    {
        E[u].push_back(v);

        if (!directed)
            E[v].push_back(u);
    }

    void printGraphEdges()
    {
        cout << "printing edges\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ----> ";
            for (int j = 0; j < E[i].size(); j++)
            {
                cout << E[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> shortestPath(int src, int dest)
    {
        vector<bool> visited(V);
        queue<int> q;
        vector<int> parent(V, -1);

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int neigh : E[v])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true;
                    parent[neigh] = v;
                }
            }
        }

        vector<int> ans;
        int cur = dest;
        ans.push_back(cur);
        while (cur != src)
        {
            cur = parent[cur];
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Graph g(8);
    g.addEdge(0, 1, false);
    g.addEdge(0, 3, false);
    g.addEdge(1, 2, false);
    g.addEdge(3, 4, false);
    g.addEdge(3, 7, false);
    g.addEdge(4, 5, false);
    g.addEdge(4, 6, false);
    g.addEdge(4, 7, false);
    g.addEdge(5, 6, false);
    g.addEdge(6, 7, false);

    g.printGraphEdges();
    vector<int> ans = g.shortestPath(0, 7);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}