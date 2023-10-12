#include <iostream>
#include <vector>
#include <set>
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
        E[v].push_back({u, weight});
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

    vector<int> dijkstras(int src)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty())
        {
            pair<int, int> p = *(s.begin());
            s.erase(s.begin());

            for (pair<int, int> neigh : E[p.second])
            {
                if (p.first + neigh.second < dist[neigh.first])
                {
                    auto it = s.find({dist[neigh.first], neigh.first});
                    if (it != s.end())
                    {
                        s.erase(it);
                    }
                    dist[neigh.first] = p.first + neigh.second;
                    s.insert({dist[neigh.first], neigh.first});
                }
            }
        }
        return dist;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(3, 4, 7);

    g.printGraphEdges();

    vector<int> dist = g.dijkstras(0);
    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}