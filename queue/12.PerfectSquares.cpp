#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

// BFS approach to find the minimum number of perfect squares that sum up to n
int numSquares(int n)
{
    vector<int> squares; // List to hold all perfect squares less than or equal to n
    for (int i = 1; i <= floor(sqrt(n)); i++)
    {
        squares.push_back(i * i); // Populate the list with perfect squares
    }
    queue<pair<int, int>> q; // Queue to hold pairs of (remaining sum, number of steps)
    q.push({n, 0});          // Start with the initial number n and 0 steps

    while (!q.empty())
    {
        pair<int, int> p = q.front(); // Get the front element of the queue
        q.pop();
        for (int sq : squares) // Iterate over all perfect squares
        {
            if (p.first - sq == 0) // If the remaining sum equals 0, we found the solution
            {
                return p.second + 1; // Return the number of steps + 1
            }
            q.push({p.first - sq, p.second + 1}); // Push the new pair to the queue
        }
    }
    return -1; // Return -1 if no solution is found (this should never happen)
}

// DP approach to find the minimum number of perfect squares that sum up to n
int numSquares2(int n)
{
    vector<int> dp(n + 1, INT_MAX); // DP array to hold the minimum number of perfect squares for each number
    dp[0] = 0;                      // Base case: 0 requires 0 squares

    for (int i = 1; i <= sqrt(n); i++) // Iterate over all possible perfect squares
    {
        int sq = i * i;               // Current perfect square
        for (int j = sq; j <= n; j++) // Update the DP array for numbers >= current perfect square
        {
            dp[j] = min(dp[j - sq] + 1, dp[j]); // Update the DP value with the minimum steps
        }
    }
    return dp[n]; // Return the result for n
}

int main()
{
    // Testing the DP approach
    cout << "Minimum number of perfect squares summing up to 12: " << numSquares2(12) << endl;
    return 0;
}
