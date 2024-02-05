#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum number of consecutive ones in a binary array.
// Interview Revision Notes:
// This problem can be solved using a linear scan approach.
// We traverse the array and keep track of the maximum consecutive ones encountered so far.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1), only constant extra space is used.
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxConsecutiveOnes = 0; // Keep track of the maximum consecutive ones encountered.
    int currentMaxConsecutiveOnes = 0; // Keep track of the current consecutive ones.

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            // If a zero is encountered, update the maxConsecutiveOnes if needed and reset the current count.
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
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}