#include <iostream>
using namespace std;

// Problem Statement:
// Given a 32-bit unsigned integer, reverse its bits.

// Intuition:
// We can reverse the bits of the given unsigned integer by iterating over each bit,
// extracting the least significant bit (LSB) of the input, and adding it to the reversed integer.
// This process is repeated for all 32 bits of the input.

// Approach:
// 1. Initialize a variable to store the reversed bits.
// 2. Iterate 32 times, each time:
//    - Left shift the reversed bits to make space for the next bit.
//    - Add the least significant bit of the input to the reversed bits.
//    - Right shift the input to move to the next bit.
// 3. Return the reversed 32-bit unsigned integer.

// Time Complexity: O(1) - Constant time complexity as the number of iterations is fixed (32).
// Space Complexity: O(1) - Constant space complexity.

uint32_t reverseBits(uint32_t n)
{
    uint32_t reverse = 0; // Initialize the variable to store the reversed bits
    for (int i = 0; i < 32; i++)
    {
        reverse <<= 1;    // Left shift the reversed bits to make space for the next bit
        reverse += n % 2; // Add the least significant bit of 'n' to the reversed bits
        n >>= 1;          // Right shift 'n' to move to the next bit
    }
    return reverse; // Return the reversed 32-bit unsigned integer
}

int main()
{
    cout << reverseBits(43261596) << endl; // Test the function with an example input
    return 0;
}
