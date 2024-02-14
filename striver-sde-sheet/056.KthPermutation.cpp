#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given two integers n and k, return the kth permutation sequence of the integers from 1 to n.

// Intuition:
// Use backtracking to generate all permutations of the integers from 1 to n and then sort them.
// Finally, return the kth permutation from the sorted list.

// DSA Strategy:
// Backtracking, Sorting

// Approach:
// 1. Implement a helper function 'permutationHelper' to recursively generate all permutations of the given string.
//    a. If the current index 'index' reaches the size of the string, add the current permutation to the result vector 'res' and return.
//    b. Iterate from the current index to the end of the string.
//       i. Swap the characters at indices 'i' and 'index'.
//       ii. Recursively call 'permutationHelper' with the next index 'index + 1'.
//       iii. Backtrack by swapping the characters back to their original positions.
// 2. Implement the main function 'getPermutation' to generate all permutations of integers from 1 to n.
//    a. Initialize an empty string 's' to store the integers from 1 to n as characters.
//    b. Initialize an empty vector 'res' to store all permutations.
//    c. Generate all permutations using 'permutationHelper'.
//    d. Sort the permutations in lexicographical order.
//    e. Return the kth permutation from the sorted list.
// 3. In the main function, provide the values of 'n' and 'k', and print the kth permutation sequence.

// Time Complexity: O(N!), where N is the given integer 'n'.
//                  This is because there are N! permutations of the integers from 1 to N, and generating each permutation takes O(N) time.
// Space Complexity: O(N!), considering the space required to store all permutations.

// Helper function to recursively generate all permutations
void permutationHelper(string &s, int index, vector<string> &res)
{
    // Base case: If the current index reaches the size of the string, add the current permutation to the result
    if (index == s.size())
    {
        res.push_back(s);
        return;
    }

    // Iterate from the current index to the end of the string
    for (int i = index; i < s.size(); i++)
    {
        // Swap the characters at indices 'i' and 'index'
        swap(s[i], s[index]);
        // Recursively call the function with the next index
        permutationHelper(s, index + 1, res);
        // Backtrack: Swap the characters back to their original positions
        swap(s[i], s[index]);
    }
}

// Main function to generate the kth permutation sequence
string getPermutation(int n, int k)
{
    string s;           // String to store the integers from 1 to n
    vector<string> res; // Vector to store all permutations
    // Populate the string with integers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        s.push_back(i + '0');
    }
    // Generate all permutations using backtracking
    permutationHelper(s, 0, res);
    // Sort the permutations in lexicographical order
    sort(res.begin(), res.end());
    // Return the kth permutation from the sorted list
    return res[k - 1];
}

// Function to generate the kth permutation sequence for a given set of numbers
// Time Complexity: O(n^2), where n is the input integer 'n'
// Space Complexity: O(n), where n is the input integer 'n'
string getPermutationMath(int n, int k)
{
    int fact = 1;        // Initialize the factorial value
    vector<int> numbers; // Vector to store numbers from 1 to n

    // Calculate factorial and populate the numbers vector
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    string ans = ""; // Initialize the result string
    k = k - 1;       // Decrement k by 1 to adjust for 0-based indexing
    while (true)
    {
        ans += to_string(numbers[k / fact]); // Append the next character to the result string

        // Remove the used number from the numbers vector
        numbers.erase(numbers.begin() + k / fact);

        // Break the loop if all numbers are used
        if (numbers.size() == 0)
            break;

        // Update k and fact for the next iteration
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans; // Return the generated permutation sequence
}

// Main function
int main()
{
    int n = 3, k = 3; // Given values of 'n' and 'k'
    // Generate and print the kth permutation sequence
    cout << "The Kth permutation sequence is " << getPermutation(n, k) << endl;
    cout << "The Kth permutation sequence is (using Math)" << getPermutationMath(n, k) << endl;
    return 0;
}
