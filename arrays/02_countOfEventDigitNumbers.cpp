#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of even digit numbers in an array.
// Interview Revision Notes:
// This problem can be solved by iterating through the array and checking the number of digits in each element.
// We use the log10 function to count the number of digits.
// Time Complexity: O(n * log(m)), where n is the size of the input array and m is the maximum number in the array.
// Space Complexity: O(1), only constant extra space is used.
int countOfEventDigitNumbers(vector<int> &nums)
{
    int count = 0; // Initialize count of even digit numbers.

    for (int i = 0; i < nums.size(); i++)
    {
        // Check if the number of digits is even.
        if (((int)log10(nums[i]) + 1) % 2 == 0)
        {
            count++; // Increment count if the number has an even number of digits.
        }
    }

    return count; // Return the count of even digit numbers.
}

int main()
{
    vector<int> nums = {20, 25, 301, 4120, 6785, 57624};
    cout << countOfEventDigitNumbers(nums);
    return 0;
}