#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Function to check if it's possible to distribute balls with a given minimum force
bool canDistribute(vector<int> &position, int m, int force)
{
    int n = position.size();   // Number of baskets
    int cntBalls = 1;          // Number of balls placed
    int lastPos = position[0]; // Position of the last placed ball

    // Iterate through the baskets
    for (int i = 1; i < n; i++)
    {
        // If the distance between the current basket and the last placed ball is greater than or equal to the given force
        if (position[i] - lastPos >= force)
        {
            cntBalls++;            // Place the next ball
            lastPos = position[i]; // Update the position of the last placed ball
        }
    }

    // If we can distribute all balls with the given force, return true
    return cntBalls >= m;
}

// Function to find the maximum possible minimum magnetic force
int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end()); // Sort the positions of the baskets

    int low = 1;                              // Minimum possible force
    int high = position.back() - position[0]; // Maximum possible force

    // Perform binary search to find the maximum possible minimum magnetic force
    while (low < high)
    {
        int mid = low + (high - low + 1) / 2; // Calculate the mid value. Adding 1 to ensure the mid element is included in the next search range
        if (canDistribute(position, m, mid))
        {
            low = mid; // If we can distribute balls with the given force, search in the right half
        }
        else
        {
            high = mid - 1; // Otherwise, search in the left half
        }
    }

    // Return the maximum possible minimum magnetic force
    return low;
}

int main()
{
    vector<int> position = {1, 2, 3, 4, 7};                                                     // Positions of the baskets
    int m = 3;                                                                                  // Number of balls
    cout << "Maximum possible minimum magnetic force: " << maxDistance(position, m) << endl; // Output the result
    return 0;
}
