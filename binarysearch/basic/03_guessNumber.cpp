#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
// You call a pre-defined API int guess(int num), which returns 3 possible results:
// -1 if the picked number is lower than your guess
//  1 if the picked number is higher than your guess
//  0 if the picked number is equal to your guess

// Intuition:
// Since we have to guess the number in the fewest attempts, binary search can be used to minimize the search space in each attempt.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize 'start' as 1 and 'end' as 'n'.
// 2. While 'start' is less than or equal to 'end', calculate 'mid' as the average of 'start' and 'end'.
// 3. Call the 'guess' function with 'mid' as the argument.
// 4. If the result is 0, return 'mid' (indicating that the number is found).
// 5. If the result is 1, update 'start' to 'mid + 1' (search in the higher half).
// 6. If the result is -1, update 'end' to 'mid - 1' (search in the lower half).

// Time Complexity: O(log n), where 'n' is the range of numbers (1 to n).
// Space Complexity: O(1).

// Function to guess the number
int guess(int n)
{
    if (n == 57)
        return 0; // Secret number
    if (n > 57)
        return -1; // Guess is too high
    return 1; // Guess is too low
}

// Function to guess the number using binary search
int guessNumber(int n)
{
    int start = 1, end = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int res = guess(mid); // Call guess function
        if (res == 0)
        {
            return mid; // Number found
        }
        else if (res == 1)
        {
            start = mid + 1; // Search in higher half
        }
        else
        {
            end = mid - 1; // Search in lower half
        }
    }
    return -1; // Number not found
}

// Main function
int main()
{
    cout << guessNumber(100); // Test guessNumber function
    return 0;
}
