#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution 1: Using Hashing
// Intuition:
// We can use a hash map to store the frequency of each element in the array.
// Then, we iterate from 1 to n and check if any number has a frequency of 2 (indicating a repeat)
// and if any number is missing (has a frequency of 0).
// Approach:
// - Use a hash map to store the frequency of each element in the array.
// - Iterate from 1 to n and check for elements with frequency 2 and 0.
// - Return the repeating and missing numbers found.
// Time complexity: O(n) where n is the size of the array.
// Space complexity: O(n) for the hash map.
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    unordered_map<int, int> hash;

    // Calculate frequencies of each element
    for (int i = 0; i < n; i++)
        hash[a[i]]++;

    // Initialize variables to store repeating and missing numbers
    int repeating = -1, missing = -1;

    // Check for repeating and missing numbers
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;

        // If both numbers are found, break the loop
        if (repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}

// Solution 2: Using Mathematics (Optimal)
// Intuition:
// We can use the concept of summation and summation of squares to find the missing
// and repeating numbers more efficiently.
// Approach:
// - Calculate the sum of natural numbers up to n (Sn) and the sum of squares of natural numbers up to n (S2n).
// - Calculate the sum (S) and sum of squares (S2) of elements in the array.
// - Using Sn, S2n, S, and S2, calculate the repeating and missing numbers.
// - Return the repeating and missing numbers found.
// Time complexity: O(n) where n is the size of the array.
// Space complexity: O(1).
vector<int> findMissingRepeatingNumbersOptimal(vector<int> a)
{
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // S - Sn = X - Y:
    long long val1 = S - SN;

    // S2 - S2n = X^2 - Y^2:
    long long val2 = S2 - S2N;

    // Find X + Y = (X^2 - Y^2) / (X - Y):
    val2 = val2 / val1;

    // Find X and Y: X = ((X + Y) + (X - Y)) / 2 and Y = X - (X - Y)
    // Here, X - Y = val1 and X + Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};

    // Using Hashing approach
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "Using Hashing approach:\n";
    cout << "The repeating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";

    // Using Optimal approach
    ans = findMissingRepeatingNumbersOptimal(a);
    cout << "\nUsing Optimal approach:\n";
    cout << "The repeating and missing numbers are: {" << ans[0] << ", " << ans[1] << "}\n";

    return 0;
}
