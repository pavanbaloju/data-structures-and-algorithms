#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Add problem statement
// Problem Statement:
// Given the positions of several baskets along a straight line, determine the maximum possible minimum magnetic force required to pull all balls together.
// Balls can only be placed in baskets, and each basket can hold only one ball.
// The magnetic force between two balls with positions x and y is equal to |x - y|.

// 2. Add Intuition
// Intuition:
// The problem can be solved using binary search. We need to find the maximum possible minimum magnetic force required to pull all balls together.

// 3. Add the DSA strategy/ pattern used to solve the problem in one line
// DSA Strategy/Pattern:
// Binary Search

// 4. Add approach : clearly explain the algorithm step by step
// Approach:
// Step 1: Sort the positions of the baskets.
// Step 2: Perform binary search to find the maximum possible minimum magnetic force.
// Step 3: Define a function 'canDistribute' to check if it's possible to distribute balls with a given minimum force.
// Step 4: In the 'canDistribute' function, iterate through the baskets and check if the distance between consecutive baskets is greater than or equal to the given force.
// Step 5: If it's possible to distribute all balls with the given force, return true; otherwise, return false.
// Step 6: Adjust the search range based on the result of the 'canDistribute' function.

// 5. Add time and space complexity
// Time Complexity: O(n log n + n log d), where n is the number of baskets and d is the maximum possible force.
// Space Complexity: O(1), no extra space is used apart from variables.

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

int main() {
    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;
    
    // 8. Format the output better in main method by printing the output
    cout << "The maximum minimum magnetic force is: " << maxDistance(position, m) << endl;
    
    return 0;
}
