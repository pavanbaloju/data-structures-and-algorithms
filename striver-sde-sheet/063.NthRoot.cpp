#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given two integers 'n' and 'm', find the Nth root of 'm'. 
// The Nth root of a number 'm' is a number 'x' such that x^N = m.

// Intuition:
// We can use binary search to find the Nth root of 'm'. 
// The idea is to iterate over possible values of the root 'mid' 
// and check if mid^N is equal to 'm'. If it is, we have found 
// the Nth root. If mid^N is greater than 'm', we search in the 
// left half of the range, otherwise, we search in the right half.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Define a function 'pow' to calculate the power of a number 'mid' raised to 'n' modulo 'm'.
//    - Iterate 'n' times and multiply 'mid' with itself.
//    - If the result exceeds 'm', return 2.
//    - If the result is less than 'm', return 0.
//    - If the result is equal to 'm', return 1.
// 2. Define a function 'NthRoot' to find the Nth root of 'm'.
//    - Initialize 'low' as 1 and 'high' as 'm'.
//    - Perform binary search to find the Nth root:
//      - Calculate 'mid' as the average of 'low' and 'high'.
//      - Calculate the power of 'mid' raised to 'n' using the 'pow' function.
//      - If the result is 1, return 'mid' as the Nth root.
//      - If the result is 0, adjust 'low' to mid + 1.
//      - If the result is 2, adjust 'high' to mid - 1.
//    - If no Nth root is found, return -1.
// 3. In the main function:
//    - Initialize 'n' and 'm'.
//    - Call the 'NthRoot' function to find the Nth root of 'm'.
//    - Print the result.

// Time Complexity: O(log(m) * log(n))
//   - Binary search is performed on the range [1, m], which takes O(log(m)) time.
//   - In each binary search iteration, 'pow' function is called, which takes O(log(n)) time.
// Space Complexity: O(1)

// Function to calculate the power of 'mid' raised to the power of 'n' modulo 'm'
int pow(int mid, int n, int m)
{
    long long ans = 1; // Initialize ans as 1 to store the result of the power operation
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid; // Calculate the power of 'mid' by multiplying 'mid' 'n' times
        if (ans > m)
            return 2; // If the result exceeds 'm', return 2 indicating it's greater than 'm'
    }
    if (ans < m)
        return 0; // If the result is less than 'm', return 0 indicating it's less than 'm'

    return 1; // If the result is equal to 'm', return 1 indicating it's equal to 'm'
}

// Function to find the Nth root of 'm'
int NthRoot(int n, int m)
{
    int low = 1, high = m; // Initialize the range of possible roots
    while (low <= high)
    {
       int mid = low + (high - low) / 2; // Calculate mid to avoid overflow
        int midN = pow(mid, n, m); // Calculate the power of 'mid' raised to the power of 'n'
        if (midN == 1)
            return mid; // If the calculated value is equal to 'm', return 'mid' as the Nth root
        else if (midN == 0)
            low = mid + 1; // If the calculated value is less than 'm', adjust the lower bound
        else
            high = mid - 1; // If the calculated value is greater than 'm', adjust the upper bound
    }
    return -1; // If no Nth root is found, return -1
}

// Main function to demonstrate the NthRoot function
int main()
{
    int n = 3, m = 27; // Input values for n and m
    int ans = NthRoot(n, m); // Call the function to find the Nth root of m
    cout << "The answer is: " << ans << "\n"; // Print the result
    return 0;
}
