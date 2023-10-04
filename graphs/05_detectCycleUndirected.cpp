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

    bool checkCycle(int v, vector<bool> &visited, int parent)
    {
        visited[v] = true;

        for (int neighbour : E[v])
        {
            if (!visited[neighbour])
            {
                if (checkCycle(neighbour, visited, v))
                    return true;
            }
            else if (neighbour != parent)
                return true;
        }
        return false;
    }

    bool hasCycle()
    {
        vector<bool> visited(V), inDfsPath(V);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (checkCycle(i, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0, false);
    g1.addEdge(0, 2, false);
    g1.addEdge(2, 1, false);
    g1.addEdge(0, 3, false);
    g1.addEdge(3, 4, false);
    cout << g1.hasCycle() << endl;

    Graph g2(3);
    g2.addEdge(0, 1, false);
    g2.addEdge(1, 2, false);
    cout << g2.hasCycle() << endl;

    return 0;
}