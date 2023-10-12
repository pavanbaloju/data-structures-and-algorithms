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

    void topologicalSort(int v, vector<bool> &visited, stack<int> &st)
    {
        visited[v] = true;
        for (pair<int, int> p : E[v])
        {
            if (!visited[p.first])
            {
                topologicalSort(p.first, visited, st);
            }
        }
        st.push(v);
    }

    vector<int> shortestDistances(int src)
    {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSort(i, visited, st);
            }
        }

        //calculating shortest path distances
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        while (!st.empty())
        {
            int v = st.top();
            st.pop();

            if (dist[v] != INT_MAX)
            {
                for (pair<int, int> p : E[v])
                {
                    dist[p.first] = min(dist[p.first], dist[v] + p.second);
                }
            }
        }

        return dist;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printGraphEdges();

    vector<int> dist = g.shortestDistances(1);
    for (int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}