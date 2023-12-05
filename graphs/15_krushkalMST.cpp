#include <iostream>
#include <vector>
using namespace std;

bool cmp(const vector<int> &u, const vector<int> &v)
{
    return u[2] < v[2];
}

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
        cout << "printing graph edges\n";
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

    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return findParent(parent, parent[node]);
    }

    void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = parent[u];
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<vector<pair<int, int>>> kruskalMST()
    {
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        // edges list {w, u, v}
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < E[i].size(); j++)
            {
                edges.push_back({i, E[i][j].first, E[i][j].second});
            }
        }
        // sort by weights
        sort(edges.begin(), edges.end(), cmp);

        vector<vector<pair<int, int>>> ans(V);
        for (int i = 0; i < V; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (findParent(parent, u) != findParent(parent, v))
            {
                ans[u].push_back({v, w});
                makeUnion(u, v, parent, rank);
            }
        }
        return ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.printGraphEdges();

    vector<vector<pair<int, int>>> ans = g.kruskalMST();

    cout << "\nprinting MST edges\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << " ----> ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << "[" << ans[i][j].first << ", " << ans[i][j].second << "],";
        }
        cout << endl;
    }

    return 0;
}