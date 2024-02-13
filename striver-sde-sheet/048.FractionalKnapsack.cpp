#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a list of items where each item has a value (profit) and a weight, 
// and a knapsack with a maximum weight capacity, determine the maximum profit 
// that can be obtained by selecting fractional weights of items.

// Intuition:
// Sort the items based on their value-to-weight ratio in descending order.
// Iterate through the sorted items and greedily select items until the knapsack's capacity is exhausted.
// If an item cannot be fully included due to the remaining capacity, 
// include a fraction of it proportional to its weight.

// DSA Strategy:
// Sorting, Greedy

// Approach:
// 1. Sort the items based on their value-to-weight ratio in descending order.
// 2. Initialize a variable 'profit' to store the total profit obtained.
// 3. Iterate through the sorted items.
//    a. If the weight of the current item is less than or equal to the remaining capacity of the knapsack,
//       include the entire item in the knapsack, update the remaining capacity, and add its profit to 'profit'.
//    b. If the weight of the current item exceeds the remaining capacity of the knapsack,
//       include a fraction of the item proportional to the remaining capacity,
//       update the remaining capacity to 0, and add the fraction of its profit to 'profit'.
// 4. Return 'profit'.

// Time Complexity: O(N log N), where N is the number of items.
// Space Complexity: O(1).

bool sorter(vector<int> v1, vector<int> v2)
{
    return (v1[0] / v1[1]) > (v2[0] / v2[1]); // Sort based on value-to-weight ratio in descending order.
}

int profit(vector<vector<int>> items, int W)
{
    int profit = 0;
    sort(items.begin(), items.end(), sorter); // Sort the items based on value-to-weight ratio.

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i][1] <= W) // If the weight of the item can be fully included.
        {
            W -= items[i][1]; // Update the remaining capacity.
            profit += items[i][0]; // Add the profit of the entire item.
        }
        else // If the weight of the item exceeds the remaining capacity.
        {
            profit += items[i][0] * ((double)W / (double)items[i][1]); // Add a fraction of the profit.
            break;
        }
    }
    return profit; // Return the total profit.
}

int main()
{
    vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << profit(items, 50) << endl;
    return 0;
}
