#include <iostream>
#include <vector>
using namespace std;

#define V 4

// Problem Statement:
// Given an undirected graph and a number m, determine if the graph can be colored with at most m colors
// such that no two adjacent vertices have the same color.

// Intuition:
// This problem can be solved using backtracking. We try to color each vertex with a color, and recursively
// solve the problem for the remaining vertices. If a valid coloring is found, we return true; otherwise, we backtrack.

// DSA Strategy:
// Backtracking

// Approach:
// 1. Define a function 'isSafe' to check if assigning a color to a vertex is safe, i.e., if the color is not
//    already assigned to any adjacent vertices.
// 2. Define a recursive function 'graphColoringUtil' to assign colors to vertices.
//    a. Base case: If all vertices are colored, return true.
//    b. For each color from 1 to m, try assigning the color to the current vertex if it is safe.
//    c. Recursively call 'graphColoringUtil' for the next vertex.
//    d. If a valid coloring is found, return true.
//    e. If no valid coloring is found, backtrack by unassigning the color from the current vertex.
// 3. Define a function 'graphColoring' to initialize colors and call 'graphColoringUtil'.
//    a. Initialize an array 'color' to store colors assigned to vertices.
//    b. Call 'graphColoringUtil' with the initial vertex and return false if no valid coloring is found.
// 4. Define a function 'printSolution' to print the assigned colors for each vertex.
// 5. In the main function:
//    a. Create an adjacency matrix representing the graph.
//    b. Specify the maximum number of colors (m).
//    c. Call 'graphColoring' to check if the graph can be colored using at most m colors.

// Time Complexity: O(m^V), where V is the number of vertices and m is the maximum number of colors.
//                  In the worst case, we explore all possible color combinations.
// Space Complexity: O(V), additional space is used for the color array.

// Function to check if assigning a color to a vertex is safe.
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;

    return true;
}

// Recursive function to assign colors to vertices.
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V) // Base case: All vertices are colored.
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c; // Assign color c to vertex v.

            // Recursive call for the next vertex.
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // Backtrack: Unassign color from vertex v.
        }
    }

    return false; // No valid coloring found for the current configuration.
}

// Function to initialize colors and call the recursive coloring function.
bool graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0; // Initialize all colors as unassigned.

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist\n";
        return false;
    }
    printSolution(color);
    return true;
}

// Function to print the assigned colors for each vertex.
void printSolution(int color[])
{
    cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i];
    cout << "\n";
}

// Main function to demonstrate graph coloring.
int main()
{
    // Create adjacency matrix representing the graph.
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    // Specify the maximum number of colors.
    int m = 3;

    // Call the graph coloring function.
    graphColoring(graph, m);

    return 0;
}
