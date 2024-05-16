#include <iostream>
#include <bitset> // For printing the binary representation

using namespace std;

// Problem Statement: 
// Given an unsigned integer, return the number of '1' bits it has (also known as the Hamming weight).

// Intuition: 
// We need to count the number of '1' bits in the binary representation of a given number.

// DSA Strategy/Pattern: 
// We use bit manipulation to efficiently count the number of '1' bits.

// Class to solve the problem of finding the Hamming weight
class Solution
{
public:
    // Approach: Using Bit Manipulation
    /*
     1. Initialize a counter to 0.
     2. Iterate through each bit of the number.
     3. Use the bitwise AND operation with 1 to check if the least significant bit (LSB) is 1.
     4. Increment the counter if the LSB is 1.
     5. Right shift the number by 1 to check the next bit.
     6. Repeat until all bits are processed.
     7. Return the counter.

     Time Complexity: O(log n), where n is the number of bits in the integer. Each iteration processes one bit.
     Space Complexity: O(1), only a few variables are used regardless of the input size.
    */
    int hammingWeight(uint32_t n)
    {
        int count = 0; // Initialize count of '1' bits to 0
        while (n != 0)
        {                     // Loop until all bits are processed
            count += (n & 1); // Add the least significant bit (LSB) to count if it is 1
            n >>= 1;          // Right shift n to process the next bit
        }
        return count; // Return the total count of '1' bits
    }
};

// Main function to test the solution
int main()
{
    Solution sol;    // Create an instance of the Solution class
    uint32_t n = 29; // Example number (binary representation: 11101)

    // Calculate the number of '1' bits in the binary representation of n
    int result = sol.hammingWeight(n);

    // Print the binary representation of n and the result
    cout << "Number of 1 bits in " << n << " (" << bitset<32>(n) << "): " << result << endl;

    return 0;
}
