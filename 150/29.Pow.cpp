#include <iostream>
using namespace std;

// Problem Statement:
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// Constraints: 
// -100.0 < x < 100.0
// -2^31 <= n <= 2^31-1
// -10^4 <= x^n <= 10^4

// Function to calculate x raised to the power n using a brute force approach.
// Intuition:
// We recursively multiply x by itself n times.
// Time complexity: O(n), where n is the exponent.
// Space complexity: O(n), due to the recursive function calls.
double myPowBrute(double x, int n)
{
    // Base cases
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    // If n is negative, invert x and make n positive
    if (n < 0)
    {
        return myPowBrute(1 / x, -n);
    }
    // Recursively calculate x^n
    return x * myPowBrute(x, n - 1);
}

// Function to calculate x raised to the power n using an optimized approach.
// Intuition:
// We use the divide and conquer strategy, where we divide the problem into smaller subproblems.
// If n is even, we recursively calculate (x * x)^(n/2). If n is odd, we recursively calculate x^(n-1) to make n even in next step.
// Time complexity: O(log n), where n is the exponent.
// Space complexity: O(log n), due to the recursive function calls.
double myPow(double x, int n)
{
    // Base cases
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    // If n is negative, invert x and make n positive
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    // Divide and conquer approach
    return n % 2 ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
}

int main()
{
    // Test cases
    cout << "Result for myPowBrute(5, 3): " << myPowBrute(5, 3) << endl;
    cout << "Result for myPowBrute(5, -2): " << myPowBrute(5, -2) << endl;
    cout << "Result for myPow(0.001, 2147483647): " << myPow(0.001, 2147483647) << endl;
    return 0;
}
