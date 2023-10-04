#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

enum color
{
    WHITE,
    GRAY,
    BLACK
};
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

    bool checkCycle(int v, vector<color> colored)
    {
        colored[v] = GRAY;

        for (int neighbour : E[v])
        {
            if (colored[neighbour] == WHITE)
            {
                if (checkCycle(neighbour, colored))
                    return true;
            }
            else if (colored[neighbour] == GRAY)
                return true;
        }
        colored[v] = BLACK;
        return false;
    }

    bool hasCycle()
    {
        vector<color> colored(V, WHITE);
        for (int i = 0; i < V; i++)
        {
            if (colored[i] == WHITE)
            {
                if (checkCycle(i, colored))
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
    Graph g(4);
    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 0, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 3, true);

    cout << g.hasCycle();
    return 0;
}