#include <iostream>  // Include the input/output stream library
#include <vector>    // Include the vector library
#include <map>       // Include the map library
#include <queue>     // Include the queue library
using namespace std; // Use the standard namespace

// Problem Statement:
// Given a set of equations represented as pairs of strings and their corresponding values, and a set of queries,
// evaluate the division of the queries using the provided equations and values. If the division is not possible,
// return -1.0.

// Intuition:
// Construct a graph where each variable is a node and the edge weight represents the division value between two variables.
// Use BFS to traverse the graph from the source node to the destination node, accumulating the division values.

// DSA Strategy/Pattern:
// Graph Traversal (Breadth-First Search)

// Approach:
// 1. Construct a graph using a map where the keys are variables and the values are vectors of pairs,
//    each containing a neighbor variable and the corresponding division value.
// 2. For each query, perform BFS from the numerator to the denominator to find the division result.
//    - Enqueue the numerator with an initial weight of 1.
//    - While the queue is not empty, dequeue a node and explore its neighbors:
//      * If a neighbor is not visited, mark it as visited and enqueue it with the accumulated weight 
//        which is the product of the current weight and the division value.
//      * If the destination is reached, return the accumulated weight.
//      * Mark visited nodes to avoid revisiting.
// 3. If either the numerator or denominator is not present in the graph, add -1 to the result vector.
// 4. Return the result vector containing the division results for all queries.

// Time Complexity: O(N * (N + Q)), where N is the number of equations, and Q is the number of queries.
//                  Building the graph takes O(N) time, and each BFS traversal takes O(N) time.
// Space Complexity: O(N), where N is the number of equations, for storing the graph.

// Function to perform BFS to find the result of division from source to destination
double bfs(string src, string dest, map<string, bool> &visited, map<string, vector<pair<string, double>>> &g)
{
    queue<pair<string, double>> q;
    q.push({src, 1});    // Start BFS from source with a weight of 1
    visited[src] = true; // Mark the source as visited
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        string u = p.first;  // Current node
        double w = p.second; // Current weight
        if (u == dest)
        {
            return w; // If destination is reached, return the accumulated weight
        }
        // Explore neighbors
        for (auto nbr : g[u])
        {
            if (!visited[nbr.first]) // If neighbor is not visited
            {
                visited[nbr.first] = true;           // Mark it as visited
                q.push({nbr.first, w * nbr.second}); // Update accumulated weight and push to the queue
            }
        }
    }
    return -1; // If destination is not reachable, return -1
}

// Function to evaluate division based on provided equations and values
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    map<string, vector<pair<string, double>>> g; // Graph representation
    // Build the graph
    for (int i = 0; i < equations.size(); i++)
    {
        string u = equations[i][0]; // Numerator
        string v = equations[i][1]; // Denominator
        double w = values[i];       // Division value
        g[u].push_back({v, w});     // Add edge from numerator to denominator
        g[v].push_back({u, 1 / w}); // Add edge from denominator to numerator with inverse value
    }

    vector<double> ans; // Store results
    for (auto q : queries)
    {
        string nume = q[0], deno = q[1];              // Numerator and denominator of the query
        if (g.count(nume) == 0 || g.count(deno) == 0) // If numerator or denominator not in graph
        {
            ans.push_back(-1); // No path exists, add -1 to the result
        }
        else
        {
            map<string, bool> visited;                  // Mark visited nodes during BFS
            ans.push_back(bfs(nume, deno, visited, g)); // Perform BFS to find the result
        }
    }
    return ans; // Return the results
}

int main()
{
    // Test case
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}}; // Equations
    vector<double> values = {2.0, 3.0};                          // Corresponding values
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};                 // Queries
    vector<double> ans = calcEquation(equations, values, queries); // Calculate results
    for (auto d : ans)
        cout << d << " "; // Print results
}
