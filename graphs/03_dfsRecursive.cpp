#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
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

    void dfs(int v, unordered_set<int> &visited, vector<int> &res)
    {
        visited.insert(v);
        res.push_back(v);

        for (int i = 0; i < E[v].size(); i++)
        {
            if (!visited.count(E[v][i]))
            {
                dfs(E[v][i], visited, res);
            }
        }
    }

    vector<int> dfsHelper(int startingVertex)
    {
        vector<int> res;
        unordered_set<int> visited(V);
        dfs(startingVertex, visited, res);
        return res;
    }
};

int main()
{
    Graph g = Graph(4);
    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 0, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 3, true);

    g.printGraphEdges();

    vector<int> dfs = g.dfsHelper(2);
    cout << "dfs" << endl;
    for (int v : dfs)
        cout << v << " ";
    cout << endl;
    return 0;
}