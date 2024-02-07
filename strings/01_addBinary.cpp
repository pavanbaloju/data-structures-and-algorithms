#include <iostream>
using namespace std;

// Problem Statement:
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contain only characters 1 or 0.

// Function to add two binary strings.
// Intuition:
// - Start from the rightmost bit and move towards the left.
// - Keep track of the carry while adding corresponding bits.
// - Reverse the result string to get the final sum.
// Approach:
// - Initialize variables i and j to the rightmost positions of the input strings a and b.
// - Initialize carry to 0 and result string to empty.
// - Iterate through the strings a and b, add corresponding bits along with the carry.
// - Update carry for the next iteration.
// - If there is a carry after processing all bits, append it to the result.
// - Reverse the result string to obtain the correct order.
// Time complexity: O(max(N, M)), where N and M are the lengths of the input strings a and b.
//   - The function iterates through the longer string.
// Space complexity: O(max(N, M)), where N and M are the lengths of the input strings a and b.
//   - Additional space is used for the result string.
string addBinary(string a, string b)
{
    string result;
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;

    // Iterate through the strings a and b from right to left.
    while (i >= 0 || j >= 0)
    {
        int sum = carry;

        // Add the corresponding bits from strings a and b along with the carry.
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }

        // Update the carry for the next iteration.
        carry = sum / 2;

        // Append the sum of the current bit to the result string.
        result += (sum % 2) + '0';
    }

    // If there is a carry after processing all bits, append it to the result.
    if (carry)
    {
        result += carry + '0';
    }

    // Reverse the result string to obtain the correct order.
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    // Example usage
    cout << addBinary("1010", "1011") << endl; // Output: "10101"
    return 0;
}
