#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum size of a contiguous subarray whose sum is greater than or equal to the target.
// Approach:
// We use a two-pointer sliding window approach.
// 1. Initialize two pointers, start and end, both pointing to the beginning of the array.
// 2. Move the end pointer to the right until the sum of the subarray[start:end] is less than the target.
// 3. Update the minimum length if the current subarray length is smaller.
// 4. Move the start pointer to the right until the sum becomes less than the target again.
// 5. Repeat steps 2-4 until the end of the array is reached.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1).
int minSubArrayLen(int target, vector<int> &nums)
{
    int minLen = INT_MAX;
    for (int start = 0, end = 0, sum = 0; end < nums.size(); end++)
    {
        sum += nums[end];
        while (sum >= target)
        {
            minLen = min(minLen, end - start + 1);
            sum -= nums[start++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    // Test cases
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;

    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, nums2) << endl;

    return 0;
}
