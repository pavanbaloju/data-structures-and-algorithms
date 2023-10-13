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
    vector<vector<int>> E = vector<vector<int>>(100, vector<int>(100));

public:
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == j)
                {
                    E[i][j] = 0;
                }
                else
                {
                    E[i][j] = INT_MAX;
                }
            }
        }
    }

    void addEdge(int u, int v, int weight)
    {
        E[u][v] = weight;
    }

    void printGraphEdges()
    {
        cout << "printing edges\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ----> ";
            for (int j = 0; j < V; j++)
            {
                if (E[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    vector<vector<int>> floydWarshall()
    {
        // assuming if i==j, E[i][j] = 0 else, E[i][j] = INT_MAX;
        for (int via = 0; via < V; via++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (E[i][via] != INT_MAX &&
                        E[via][j] != INT_MAX &&
                        E[i][via] + E[via][j] < E[i][j])
                    {
                        E[i][j] = E[i][via] + E[via][j];
                    }
                }
            }
        }
        return E;
    }
};

int main()
{
    Graph g = Graph(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);

    g.printGraphEdges();
    vector<vector<int>> ans = g.floydWarshall();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ans[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}