#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Method: Maximum Consecutive Ones
// Approach:
// - Iterate through the array.
// - Keep track of the maximum consecutive ones encountered so far and the current consecutive ones.
// - When encountering a zero, update the maximum consecutive ones if needed and reset the current count.
// - When encountering a one, increment the count of consecutive ones.
// - After iterating through the array, update the maximum consecutive ones with the final count of consecutive ones encountered.
// Time Complexity: O(n), where n is the length of the input array.
// Space Complexity: O(1), as only constant extra space is used.

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxConsecutiveOnes = 0;            // Keep track of the maximum consecutive ones encountered.
    int currentMaxConsecutiveOnes = 0;     // Keep track of the current consecutive ones.

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            // If a zero is encountered, update maxConsecutiveOnes if needed and reset the current count.
            maxConsecutiveOnes = max(maxConsecutiveOnes, currentMaxConsecutiveOnes);
            currentMaxConsecutiveOnes = 0;
        }
        else
        {
            // If a one is encountered, increment the count of consecutive ones.
            currentMaxConsecutiveOnes++;
        }
    }

    // After loop, update maxConsecutiveOnes with the final count of consecutive ones encountered at the end of the array.
    return max(maxConsecutiveOnes, currentMaxConsecutiveOnes);
}

int main()
{
    // Input binary array
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0};

    // Call the findMaxConsecutiveOnes function to find the maximum number of consecutive ones
    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums);

    // Output the maximum number of consecutive ones
    cout << "Maximum number of consecutive ones: " << maxConsecutiveOnes << endl;

    return 0;
}
