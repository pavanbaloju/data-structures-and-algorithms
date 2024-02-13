#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a value V and a list of coins with different denominations,
// find the minimum number of coins needed to make the change for V.
// The coins are available in unlimited quantities.

// Intuition:
// Greedily select the largest denomination coins until the remaining value becomes zero.

// DSA Strategy:
// Sorting, Greedy

// Approach:
// 1. Sort the coins in descending order of denomination.
// 2. Initialize an empty vector 'ans' to store the selected coins.
// 3. Iterate through the sorted coins.
//    a. While the remaining value 'V' is greater than or equal to the current coin denomination,
//       subtract the denomination from 'V' and add the coin to 'ans'.
// 4. Return 'ans' containing the selected coins.

// Time Complexity: O(N log N), where N is the number of coins.
// Space Complexity: O(N).

vector<int> coinChange(int V, vector<int> coins)
{
    sort(coins.begin(), coins.end(), greater<int>()); // Sort coins in descending order.

    vector<int> ans; // Initialize an empty vector to store selected coins.

    for (int i = 0; i < coins.size(); i++)
    {
        while (V >= coins[i]) // Greedily select the largest denomination coins.
        {
            V -= coins[i]; // Subtract the denomination from the remaining value.
            ans.push_back(coins[i]); // Add the coin to 'ans'.
        }
    }
    return ans; // Return the vector containing selected coins.
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans = coinChange(788, coins); // Example usage: Find minimum coins for value 88.
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " "; // Print the selected coins.
    return 0;
}
