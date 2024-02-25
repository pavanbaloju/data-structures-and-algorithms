#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given an integer n, find the nth Fibonacci number.

// Intuition:
// Fibonacci sequence follows the pattern: 0, 1, 1, 2, 3, 5, 8, 13, ...
// Each number is the sum of the two preceding ones.

// DSA Strategy:
// We can solve this problem using various dynamic programming approaches:
// 1. Recursive Approach
// 2. Memoization (Top-down) Approach
// 3. Tabulation (Bottom-up) Approach

// Approach1: Recursive Approach
// - This approach involves writing a recursive function to calculate the nth Fibonacci number.
// - We recursively call the function for (n-1) and (n-2) until n becomes 0 or 1.
// - Base cases: If n is less than or equal to 1, return n.
// - Time Complexity: O(2^n) Exponential
// - Space Complexity: O(n) due to function call stack

int fiboRecursive(int n)
{
    if (n <= 1)
        return n;

    return fiboRecursive(n - 1) + fiboRecursive(n - 2);
}

// Approach2: Memoization (Top-down) Approach
// - This approach uses memoization to avoid redundant calculations in the recursive approach.
// - We use a vector to store previously computed Fibonacci numbers.
// - Before computing the nth Fibonacci number, we check if it's already computed.
// - If yes, we return the stored value; otherwise, we compute it recursively and store it.
// - Time Complexity: O(n)
// - Space Complexity: O(n)

int fiboMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp));
}

// Approach3: Tabulation (Bottom-up) Approach
// - This approach iteratively computes Fibonacci numbers starting from 0 and 1.
// - We use a vector to store the Fibonacci numbers.
// - We start from the base cases (0 and 1) and iteratively compute the Fibonacci numbers up to n.
// - Finally, we return the nth Fibonacci number.
// - Time Complexity: O(n)
// - Space Complexity: O(n)

int fiboTable(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Function to print the Fibonacci numbers using different approaches
void printFibonacci(int n)
{
    cout << "Recursive Fibonacci: " << fiboRecursive(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Memoization Fibonacci: " << fiboMemo(n, dp) << endl;

    dp = vector<int>(n + 1, -1);
    cout << "Tabulation Fibonacci: " << fiboTable(n, dp) << endl;
}

int main()
{
    int n = 5;
    cout << "Fibonacci numbers for n = " << n << ":" << endl;
    printFibonacci(n);
    return 0;
}
