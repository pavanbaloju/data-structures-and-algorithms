#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// You have N gardens, labeled 1 to N. In each garden, you want to plant one of 4 types of flowers.
// Paths are provided as a list of pairs of integers (i, j), representing a path from garden i to garden j.
// Return any such a choice of flower types that allows no two adjacent gardens to have the same flower type.

// Intuition:
// This problem can be solved using backtracking. We assign flower types to gardens one by one recursively,
// ensuring that no two adjacent gardens have the same flower type.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a helper function 'isSafe' to check if it's safe to assign a flower type to a garden.
//    It checks if any adjacent garden already has the same flower type.
// 2. Define a backtracking function 'assignFlowerTypes' to recursively assign flower types to gardens.
//    a. Base case: If all gardens are assigned a flower type, return true.
//    b. Try assigning flower types to the current garden from 1 to 4.
//    c. If it's safe to assign a flower type, recursively call 'assignFlowerTypes' for the next garden.
//    d. If a valid assignment is found, return true.
//    e. If no valid assignment is found, backtrack by unassigning the flower type from the current garden.
// 3. Define the main function 'gardenNoAdj' to initialize the graph and call 'assignFlowerTypes'.
//    a. Create a graph representation using an adjacency list.
//    b. Initialize a vector to store the flower types for each garden.
//    c. Start backtracking from the first garden.
//    d. Convert the flower types to a 1-indexed array and return.

// Time Complexity: O(N^2), where N is the number of gardens. In the worst case, we might explore all paths.
// Space Complexity: O(N), additional space is used for the graph representation and flower types array.

// Helper function to check if it's safe to assign a flower type to a garden.
bool isSafe(int garden, int flowerType, vector<vector<int>> &graph, vector<int> &flowerTypes)
{
    for (int neighbor : graph[garden])
    {
        if (flowerTypes[neighbor] == flowerType)
        {
            return false;
        }
    }
    return true;
}

// Backtracking function to assign flower types to gardens.
bool assignFlowerTypes(int garden, vector<vector<int>> &graph, vector<int> &flowerTypes)
{
    int n = graph.size() - 1; // Number of gardens

    // Base case: If all gardens are assigned a flower type.
    if (garden == n + 1)
    {
        return true;
    }

    // Try assigning flower types to the current garden.
    for (int flowerType = 1; flowerType <= 4; ++flowerType)
    {
        if (isSafe(garden, flowerType, graph, flowerTypes))
        {
            flowerTypes[garden] = flowerType;
            // Recursively assign flower types to the next garden.
            if (assignFlowerTypes(garden + 1, graph, flowerTypes))
            {
                return true;
            }
            flowerTypes[garden] = 0; // Backtrack.
        }
    }

    return false; // No valid flower type found for the current garden.
}

// Main function to assign flower types to gardens.
vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<vector<int>> graph(n + 1); // Graph representation.

    // Build the graph.
    for (const auto &path : paths)
    {
        graph[path[0]].push_back(path[1]);
        graph[path[1]].push_back(path[0]);
    }

    vector<int> flowerTypes(n + 1, 0); // Flower types for each garden.

    // Start backtracking from the first garden.
    assignFlowerTypes(1, graph, flowerTypes);

    // Convert to 1-indexed array.
    return vector<int>(flowerTypes.begin() + 1, flowerTypes.end());
}

// Main function to demonstrate the gardenNoAdj function.
int main()
{
    // Example input.
    int noOfGardens = 3;
    vector<vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};

    // Call the gardenNoAdj function.
    vector<int> result = gardenNoAdj(noOfGardens, paths);

    // Print the flower types for each garden.
    for (int type : result)
    {
        cout << type << " ";
    }
    cout << endl;

    return 0;
}
