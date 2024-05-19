#include <iostream>
#include <vector>

using namespace std;

// Data structure to represent a disjoint set
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank; // Used for Union by Rank
    vector<int> size; // Used for Union by Size

public:
    // Constructor to initialize the disjoint set
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        // Initialize each element as a separate set with itself as the parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the root of the set to which element x belongs (with path compression)
    int findParent(int x)
    {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]); // Path compression: Make the parent of x the root of its set
        return parent[x];
    }

    // Merge sets containing elements x and y using Union by Rank
    void unionByRank(int x, int y)
    {
        int rootX = findParent(x);
        int rootY = findParent(y);

        if (rootX != rootY)
        {
            // Attach smaller rank tree under root of higher rank tree (Union by Rank)
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

    // Merge sets containing elements x and y using Union by Size
    void unionBySize(int x, int y)
    {
        int rootX = findParent(x);
        int rootY = findParent(y);

        if (rootX != rootY)
        {
            // Attach smaller size tree under root of larger size tree (Union by Size)
            if (size[rootX] < size[rootY])
            {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
            else
            {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

int main()
{
    // Create a disjoint set with 5 elements
    DisjointSet ds(5);

    // Perform union operations using Union by Rank
    ds.unionByRank(0, 2);
    ds.unionByRank(4, 2);
    ds.unionByRank(3, 1);

    // Print the parent array after union operations using Union by Rank
    cout << "Parent array using Union by Rank:\n";
    for (int i = 0; i < 5; ++i)
        cout << i << " -> " << ds.findParent(i) << endl;

    // Create another disjoint set with 5 elements
    DisjointSet ds2(5);

    // Perform union operations using Union by Size
    ds2.unionBySize(0, 2);
    ds2.unionBySize(4, 2);
    ds2.unionBySize(3, 1);

    // Print the parent array after union operations using Union by Size
    cout << "\nParent array using Union by Size:\n";
    for (int i = 0; i < 5; ++i)
        cout << i << " -> " << ds2.findParent(i) << endl;

    return 0;
}
