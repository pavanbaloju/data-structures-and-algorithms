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
    int E[100][100];

public:
    Graph(int noOfVertices)
    {
        V = noOfVertices;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                E[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, bool directed)
    {
        E[u][v] = 1;

        if (!directed)
            E[v][u] = 1;
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

    vector<int> bfs(int startingVertex)
    {
        vector<int> res;
        queue<int> q;
        unordered_set<int> visited(V);

        q.push(startingVertex);
        visited.insert(startingVertex);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            res.push_back(v);

            for (int i = 0; i < V; i++)
            {
                if (E[v][i] == 1 && !visited.count(i))
                {
                    q.push(i);
                    visited.insert(i);
                }
            }
        }

        return res;
    }

    vector<int> dfs(int startingVertex)
    {
        vector<int> res;
        stack<int> st;
        unordered_set<int> visited(V);

        st.push(startingVertex);
        visited.insert(startingVertex);

        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            res.push_back(v);

            for (int i = 0; i < V; i++)
            {
                if (E[v][i] == 1 && !visited.count(i))
                {
                    st.push(i);
                    visited.insert(i);
                }
            }
        }

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

    vector<int> bfs = g.bfs(2);
    cout << "bfs" << endl;
    for (int v : bfs)
        cout << v << " ";
    cout << endl;

    vector<int> dfs = g.dfs(2);
    cout << "dfs" << endl;
    for (int v : dfs)
        cout << v << " ";
    cout << endl;
    return 0;
}