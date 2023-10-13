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

    vector<vector<pair<int, int>>> primsMST()
    {
        vector<int> parent(V, -1);
        vector<int> weights(V, INT_MAX);
        vector<bool> mst(V, false);

        weights[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < V; i++)
        {
            int min = INT_MAX;
            int minIdx;

            // find vertex which is not in MST and with minimun weight
            for (int j = 0; j < V; j++)
            {
                if (mst[j] == false && weights[j] < min)
                {
                    min = weights[j];
                    minIdx = j;
                }
            }

            // add vertex to mst
            mst[minIdx] = true;

            // update weights and parent of vbours which are not in MST
            for (auto it : E[minIdx])
            {
                int v = it.first;
                int w = it.second;
                if (mst[v] == false && w < weights[v])
                {
                    parent[v] = minIdx;
                    weights[v] = w;
                }
            }
        }

        vector<vector<pair<int, int>>> ans(V);
        for (int i = 1; i < V; i++)
        {
            ans[parent[i]].push_back({i, weights[i]});
        }

        return ans;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 0, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 1, 3);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 0, 6);
    g.addEdge(3, 1, 8);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 1, 5);
    g.addEdge(4, 2, 7);
    g.addEdge(4, 3, 9);
    g.printGraphEdges();

    vector<vector<pair<int, int>>> ans = g.primsMST();

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