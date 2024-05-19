#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a network of 'n' computers and a list of connections between them, the task is to determine the minimum number of additional connections needed to make all computers connected.

// Intuition:
// We can model this problem as a disjoint set problem, where each computer represents a node and each connection represents an edge.
// The goal is to connect all computers in the network by adding the minimum number of additional connections. We can achieve this by finding the number of connected components in the network and then calculating the additional connections needed to connect these components.

// DSA Strategy/Pattern:
// Disjoint Set Union (DSU), Connected Components

// Approach:
// Disjoint Set Union (DSU) Approach:
// 1. Initialize a DisjointSet data structure with 'n' elements, where each computer is initially its own component.
// 2. Iterate through each connection:
//    a. For each connection, if the two computers are not already in the same set, union their sets and decrement the number of connected components.
// 3. After processing all connections, calculate the number of additional connections needed to connect all components.
//    - The number of additional connections needed is equal to the number of connected components minus 1.
//    - If the number of av\ailable connections is less than the required additional connections, return -1, as it is not possible to connect all computers.
// 4. Return the minimum number of additional connections needed.

// Time Complexity: O(N + E), where N is the number of computers and E is the number of connections
// Space Complexity: O(N), where N is the number of computers

class DisjointSet
{
private:
    vector<int> parent; // Vector to store the parent of each element
    vector<int> rank;   // Vector to store the rank of each element (used for rank optimization)

public:
    // Constructor to initialize the DisjointSet with 'n' elements
    DisjointSet(int n)
    {
        parent.resize(n); // Resize parent vector to hold 'n' elements
        rank.resize(n);   // Resize rank vector to hold 'n' elements

        // Initialize each element as its own parent and set its rank to 0
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find operation to find the representative (root) of the set containing 'x'
    int find(int x)
    {
        // If 'x' is not the parent of itself, recursively find the representative
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression: Update parent to root
        }
        return parent[x]; // Return the representative (root) of the set
    }

    // Union operation to merge the sets containing 'x' and 'y'
    void unionSets(int x, int y)
    {
        int rootX = find(x); // Find the representative of set containing 'x'
        int rootY = find(y); // Find the representative of set containing 'y'

        // If 'x' and 'y' belong to the same set, no union is needed
        if (rootX == rootY)
            return;

        // Union by rank: Attach smaller tree to larger tree to maintain balance
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY; // Set 'rootY' as parent of 'rootX'
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX; // Set 'rootX' as parent of 'rootY'
        }
        else
        {
            parent[rootY] = rootX; // Set 'rootX' as parent of 'rootY'
            rank[rootX]++;         // Increment rank of 'rootX' since its subtree depth increased
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{

    // If the number of additional connections needed to connect all components is greater than the available connections, return -1
    if (connections.size() < n - 1)
        return -1;
        
    int components = n; // Initialize the number of connected components to 'n' (each computer is initially its own component)

    // Initialize a DisjointSet with 'n' elements, representing each computer as a separate set
    DisjointSet ds(n);

    // Iterate through each connection and union the sets of connected computers
    for (const auto &conn : connections)
    {
        int computer1 = conn[0];
        int computer2 = conn[1];

        // If the two computers are in different sets, union them and decrement the number of connected components
        if (ds.find(computer1) != ds.find(computer2))
        {
            ds.unionSets(computer1, computer2);
            components--;
        }
    }

    // Return the minimum number of additional connections needed to connect all disjoint sets
    return components - 1;
}

int main()
{
    // Example usage
    int n = 6;                                                                  // Number of computers
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}}; // Connections between computers

    // Calculate the minimum number of operations needed to make all computers connected
    int minOperations = makeConnected(n, connections);

    // Print the result
    cout << "Minimum number of operations to make all computers connected: " << minOperations << endl;

    return 0;
}
