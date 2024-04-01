#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Statement:
// Given an undirected graph with weighted edges, the task is to find the minimum spanning tree (MST) using Kruskal's algorithm.

// Intuition:
// Kruskal's algorithm grows the minimum spanning tree by adding the shortest edge that doesn't create a cycle.
// It sorts the edges by weight and gradually adds them to the MST, ensuring that no cycles are formed.

// DSA Strategy/Pattern:
// Graph Algorithms, Minimum Spanning Tree, Kruskal's Algorithm

// Approach:
// Kruskal's Algorithm:
// 1. Sort all the edges in non-decreasing order of their weight.
// 2. Initialize an empty set to store the MST.
// 3. Initialize a disjoint set data structure to keep track of the connected components.
// 4. Iterate through all the sorted edges:
//    a. For each edge, if including it in the MST doesn't form a cycle, add it to the MST and merge the sets of its endpoints.
// 5. Return the MST.

// Time Complexity: O(E log E), where E is the number of edges
// Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges

// Data structure to represent a graph edge
struct Edge
{
    int src, dest, weight;
};

// Data structure to represent a disjoint set
class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    // Constructor to initialize DisjointSet with n elements
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        // Initialize each element as a separate set with itself as the parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the root of the set to which element x belongs (with path compression)
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression: Make the parent of x the root of its set
        return parent[x];
    }

    // Merge sets containing elements x and y
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        // Attach smaller rank tree under root of higher rank tree
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Comparator function to sort edges by their weight
bool compareEdges(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning tree (MST) using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge> &edges, int numVertices)
{
    // Sort edges in non-decreasing order of weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> MST; // Stores the edges of the MST
    DisjointSet ds(numVertices);

    for (const Edge &edge : edges)
    {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        // If including this edge does not cause a cycle, add it to the MST
        if (srcRoot != destRoot)
        {
            MST.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
        }
    }

    return MST;
}

int main()
{
    // Example usage
    int numVertices = 6;
    // src, dest, wt
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 0, 4},
        {2, 0, 4},
        {2, 1, 2},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 2, 3},
        {3, 4, 3},
        {4, 2, 4},
        {4, 3, 3},
        {5, 2, 2},
        {5, 4, 3}};

    // Find the minimum spanning tree (MST)
    vector<Edge> MST = kruskalMST(edges, numVertices);

    // Print the edges of the MST
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (const Edge &edge : MST)
    {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
