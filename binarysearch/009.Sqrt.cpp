#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a non-negative integer x, compute and return the square root of x.
// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Intuition:
// We can use binary search to find the square root of x. 
// We iterate through the possible square root values 
// and narrow down the search space based on the comparison of the square of the mid value with x.

// DSA Strategy:
// Binary Search

// Approach:
// 1. If x is 0 or 1, return x as the square root.
// 2. Set the start to 1 and the end to half of x, as the square root of x will not exceed half of x.
// 3. Perform binary search within the range [start, end].
//    a. Calculate the mid value.
//    b. If the square of mid equals x, return mid.
//    c. If the square of mid is less than x, update the start to mid + 1.
//    d. If the square of mid is greater than x, update the end to mid - 1.
// 4. Return the end value, which represents the integer part of the square root.

// Time Complexity: O(log N), where N is the value of x.
// Space Complexity: O(1).

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x; // If x is 0 or 1, return x as the square root
    }

    int start = 1, end = x / 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Calculate mid to avoid overflow

        if (mid == x / mid)
        {
            return mid; // If square of mid equals x, return mid
        }
        else if (mid < x / mid)
        {
            start = mid + 1; // If square of mid is less than x, update start
        }
        else
        {
            end = mid - 1; // If square of mid is greater than x, update end
        }
    }

    return end; // Return end as the integer part of the square root
}

int main()
{
    // Example input
    int x = 8;

    // Compute and print the square root of x
    cout << "Square root of " << x << ": " << mySqrt(x) << endl;
}
