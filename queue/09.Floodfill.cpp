#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
Given an m x n integer grid image representing a picture, where image[i][j] represents the pixel value of the image, 
implement a function to perform a flood fill. Starting from the pixel (sr, sc), the function changes the color of the 
cell and all adjacent cells with the same starting color to the new color.

Intuition:
Use Breadth-First Search (BFS) to explore all connected cells with the same starting color and change them to the target color.

DSA Strategy/Pattern:
Breadth-First Search (BFS)

Approach:
1. Check if the starting cell already has the target color; if yes, return the image as is.
2. Use a queue to perform BFS, starting with the given cell.
3. For each cell, change its color and add its adjacent cells to the queue if they have the same starting color.
4. Continue until all reachable cells are visited and updated.

Time Complexity:
O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
O(m * n) for storing the queue and the visited cells.

Function to add adjacent cells to the queue if they are within bounds
*/

void addAdjacent(vector<vector<int>> &image, int sr, int sc, int color, int startColor, queue<pair<int, int>> &q)
{
    // Check if the cell is out of bounds
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
        return;
    
    // Add the cell to the queue if it has the start color
    if (image[sr][sc] == startColor)
        q.push({sr, sc});
}

// Function to perform flood fill on the image
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // If the starting cell is already the target color, return the image as is
    if (image[sr][sc] == color)
        return image;

    // Queue to perform BFS
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int startColor = image[sr][sc];

    // Perform BFS
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        sr = p.first;
        sc = p.second;

        // Check if the current cell needs to be colored
        if (image[sr][sc] == startColor)
        {
            image[sr][sc] = color; // Change the color of the cell

            // Add adjacent cells to the queue
            addAdjacent(image, sr - 1, sc, color, startColor, q); // Up
            addAdjacent(image, sr + 1, sc, color, startColor, q); // Down
            addAdjacent(image, sr, sc - 1, color, startColor, q); // Left
            addAdjacent(image, sr, sc + 1, color, startColor, q); // Right
        }
    }

    return image;
}

int main()
{
    // Example input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    // Call the floodFill function with the starting point and target color
    vector<vector<int>> res = floodFill(image, 1, 1, 2);

    // Print the resulting image
    cout << "Updated image after flood fill:" << endl;
    for (vector<int> v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
