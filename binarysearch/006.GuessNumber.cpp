#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// - We are playing the Guess Game. The game is as follows:
//   - I pick a number from 1 to n. You have to guess which number I picked.
//   - Every time you guess wrong, I'll tell you whether the number is higher or lower.
//   - You call a pre-defined API int guess(int num), which returns 3 possible results:
//     - -1: The number I picked is lower than your guess (i.e., pick < num).
//     - 1: The number I picked is higher than your guess (i.e., pick > num).
//     - 0: The number I picked is equal to your guess (i.e., pick == num).

// Approach: Binary Search
// - Problem Statement: Guess the number within a range using binary search.
// - Intuition: Use binary search to guess the number efficiently by narrowing down the search space based on the feedback.
// - DSA Strategy: Binary Search
// - Approach:
//   - Start with the entire range of possible numbers.
//   - Use binary search to guess a number in the middle of the range.
//   - Based on the feedback from the guess function, either narrow down the search space to the lower or upper half of the range.
//   - Repeat this process until the number is guessed correctly.
// - Time Complexity: O(log n), where n is the range of possible numbers.
// - Space Complexity: O(1)

// Function to guess the number
int guess(int n)
{
    if (n == 57)
        return 0; // Secret number
    if (n > 57)
        return -1; // Guess is too high
    return 1;      // Guess is too low
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
