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

    vector<int> topologicalSort()
    {
        queue<int> q;
        vector<int> indegree(V, 0);

        for (vector<int> vec : E)
        {
            for (int v : vec)
            {
                ++indegree[v];
            }
        }

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
                --indegree[neighbour];
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return ans;
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
    vector<int> ans = g.topologicalSort();

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}