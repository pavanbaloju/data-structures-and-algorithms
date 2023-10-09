#include <iostream>
#include <vector>
#include <stack>
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

    void topologicalSort(int v, vector<bool> &visited, stack<int> &st)
    {
        visited[v] = true;

        for (int n : E[v])
        {
            if (!visited[n])
            {
                topologicalSort(n, visited, st);
            }
        }
        st.push(v);
    }

    vector<int> topoSort()
    {
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSort(i, visited, st);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2, true);
    g.addEdge(5, 0, true);
    g.addEdge(4, 0, true);
    g.addEdge(4, 1, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 1, true);

    g.printGraphEdges();
    vector<int> ans = g.topoSort();

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}