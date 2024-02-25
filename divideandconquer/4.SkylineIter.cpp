#include <iostream>
#include <set>
#include <vector>

using namespace std;
// Problem Statement:
// Given a collection of buildings represented by their left and right x coordinates along with their heights,
// construct a skyline, which is the outline formed by these buildings when viewed from a distance.
// The skyline is defined as a series of horizontal lines only, no vertical lines.

// Intuition:
// We can solve this problem using a multiset to keep track of the heights of buildings at various points along the x-axis.
// By iterating through the buildings and storing the left and right edges along with their heights as negative and positive values,
// respectively, we can sort the points and process them in ascending order. As we process each point, we update the current
// maximum height and add the point to the result whenever the maximum height changes.

// DSA Strategy:
// We use a multiset to efficiently maintain the heights of the buildings at various points along the x-axis.
// Sorting the points allows us to process them in ascending order, ensuring correct handling of overlapping buildings.

// Approach:
// 1. Initialize an empty multiset to store the heights of buildings.
// 2. Iterate through the buildings and add the left and right edges along with their heights as negative and positive values, respectively, to a vector of pairs.
// 3. Sort the vector of pairs based on the x-coordinate of the points.
// 4. Iterate through the sorted points:
//    a. If the height at the current point is negative, insert it into the multiset.
//    b. If the height at the current point is positive, erase its corresponding negative value from the multiset.
//    c. Update the current maximum height by taking the maximum value from the multiset.
//    d. If the maximum height changes, add the current point to the result.
// 5. Return the result.

// Time Complexity:
// The time complexity of this approach is O(n log n), where n is the number of buildings. The complexity arises from sorting the points.

// Space Complexity:
// The space complexity is O(n), where n is the number of buildings, as we store the points in a vector.

// Function to print the result
void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

// Function to get the skyline
vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    // Initialize result vector
    vector<vector<int>> ans;

    // Initialize multiset to store heights of buildings
    multiset<int> pointSet{0};

    // Vector of pairs to store left and right edges along with heights
    vector<pair<int, int>> points;

    // Iterate through buildings and add points to the vector
    for (auto coords : buildings)
    {
        points.push_back({coords[0], -coords[2]});
        points.push_back({coords[1], coords[2]});
    }

    // Sort the points based on x-coordinate
    sort(points.begin(), points.end());

    // Initialize variables to track current maximum height
    int currentMaxHeight = 0;

    // Iterate through sorted points
    for (int i = 0; i < points.size(); i++)
    {
        // Get current point and height
        int currentPoint = points[i].first;
        int heightAtCurrentPoint = points[i].second;

        // If height is negative, insert into multiset
        if (heightAtCurrentPoint < 0)
        {
            pointSet.insert(-heightAtCurrentPoint);
        }
        // If height is positive, erase from multiset
        else
        {
            pointSet.erase(pointSet.find(heightAtCurrentPoint));
        }

        // Update current maximum height
        auto maxHeight = *pointSet.rbegin();
        if (currentMaxHeight != maxHeight)
        {
            currentMaxHeight = maxHeight;
            ans.push_back({currentPoint, currentMaxHeight});
        }
    }
    return ans;
}

// Main function
int main()
{
    // Example input
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};

    // Get skyline and print the result
    vector<vector<int>> ans = getSkyline(buildings);
    print(ans);

    return 0;
}
