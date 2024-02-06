#include <iostream>
#include <vector>
using namespace std;

// Function to add one to the given array representing a non-negative integer.
// Intuition:
// We start by adding 1 to the last digit of the array. We maintain a carry variable
// to handle cases where the sum exceeds 9. We iterate through the array from right
// to left, adding the carry to each digit. If the sum is less than or equal to 9,
// we update the digit and return the array. If the sum is 10, we set the digit to 0
// and continue to the next digit. If we reach the beginning of the array and still
// have a carry, we insert the carry at the beginning of the array.
// Approach:
// - Start with a carry of 1.
// - Iterate through the array from right to left.
// - Add the carry to each digit and update the carry.
// - If the carry becomes 0, return the modified array.
// - If the carry is still 1 after iterating through all digits, insert 1 at the beginning of the array.
// Time complexity: O(n), where n is the number of digits in the array.
// Space complexity: O(1) (amortized), as we modify the input array in-place.
vector<int> plusOne(vector<int> &digits)
{
    int carry = 1, n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        if (carry == 0)
        {
            return digits;
        }
    }
    // If carry is still 1 after iterating through all digits, insert 1 at the beginning.
    digits.insert(digits.begin(), carry);
    return digits;
}

int main()
{
    // Test the plusOne function with an example array.
    vector<int> digits = {2, 9, 9};
    vector<int> res = plusOne(digits);

    // Output the result.
    for (int d : res)
    {
        cout << d;
    }
    return 0;
}
