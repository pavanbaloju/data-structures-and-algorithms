#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> E;

public:
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        E = vector<vector<pair<int, int>>>(V, vector<pair<int, int>>());
    }

    void addEdge(int u, int v, int weight)
    {
        E[u].push_back({v, weight});
    }

    void printGraphEdges()
    {
        cout << "printing edges\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ----> ";
            for (int j = 0; j < E[i].size(); j++)
            {
                cout << "[" << E[i][j].first << ", " << E[i][j].second << "],";
            }
            cout << endl;
        }
    }

    vector<int> bellmanFordShortestPaths(int src)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < V; i++)
        {
            // traverse all edges
            for (int j = 0; j < V; j++)
            {
                for (pair<int, int> v : E[j])
                {
                    if (dist[j] != INT_MAX && dist[j] + v.second < dist[v.first])
                    {
                        dist[v.first] = dist[j] + v.second;
                    }
                }
            }
        }

        // check for negative cycle
        bool hasCycle = false;
        for (int j = 0; j < V; j++)
        {
            for (pair<int, int> v : E[j])
            {
                if (dist[j] != INT_MAX && dist[j] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[j] + v.second;
                    hasCycle = true;
                    break;
                }
            }
        }

        if (hasCycle)
        {
            return {};
        }

        return dist;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
    g.printGraphEdges();

    vector<int> dist = g.bellmanFordShortestPaths(0);
    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;

    Graph g2(3);
    g2.addEdge(0, 1, -1);
    g2.addEdge(1, 2, -2);
    g2.addEdge(2, 0, -1);
    g2.printGraphEdges();

    vector<int> dist2 = g2.bellmanFordShortestPaths(0);
    cout << (dist2.size() == 0 ? "has cycle" : "no cycle") << endl;
    return 0;
}