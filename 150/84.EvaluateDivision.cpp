#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

double bfs(string src, string dest, map<string, bool> &visited, map<string, vector<pair<string, double>>> &g)
{
    queue<pair<string, double>> q;
    q.push({src, 1});
    visited[src] = true;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        string u = p.first;
        double w = p.second;
        if (u == dest)
        {
            return w;
        }
        for (auto nbr : g[u])
        {
            if (!visited[nbr.first])
            {
                visited[nbr.first] = true;
                q.push({nbr.first, w * nbr.second});
            }
        }
    }
    return -1;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    map<string, vector<pair<string, double>>> g = map<string, vector<pair<string, double>>>();
    for (int i = 0; i < equations.size(); i++)
    {
        string u = equations[i][0];
        string v = equations[i][1];
        double w = values[i];
        g[u].push_back({v, w});
        g[v].push_back({u, 1 / w});
    }

    vector<double> ans;
    for (auto q : queries)
    {
        string nume = q[0], deno = q[1];
        if (g.count(nume) == 0 || g.count(deno) == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            map<string, bool> visited;
            ans.push_back(bfs(nume, deno, visited, g));
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};
    vector<double> ans = calcEquation(equations, values, queries);
    for (auto d : ans)
        cout << d << " ";
}