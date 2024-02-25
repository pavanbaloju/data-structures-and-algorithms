#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Intuition:
// This problem is a classic example of the Fibonacci sequence, where each number is the sum of the two preceding ones.
// If we consider each step as a Fibonacci number, the total number of ways to reach the nth step is the (n+1)th Fibonacci number.

// DSA Strategy:
// We can solve this problem using the Fibonacci sequence approach:
// - Initialize two variables (prev and prev2) to store the number of ways to reach the current and previous steps.
// - Iterate from 2 to n, calculating the number of ways to reach each step using the Fibonacci formula: curr = prev + prev2.
// - Update prev2 and prev with the current values for the next iteration.
// - The final value of prev represents the total number of ways to reach the top.

// Approach:
// - Initialize prev and prev2 to 1, as there is one way to reach the first two steps.
// - Iterate from 2 to n, updating prev and prev2 based on the Fibonacci formula.
// - Return the value of prev, which represents the total number of ways to reach the top.

// Time Complexity: O(n)
// Space Complexity: O(1)

int climbStairs(int n)
{
    int prev = 1, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n = 5;
    cout << "Number of distinct ways to climb " << n << " stairs: " << climbStairs(n) << endl;

    return 0;
}
