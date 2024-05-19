#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
using namespace std;

// Function to find the maximum subarray sum using Kadane's algorithm
int kadane(const vector<int> &nums)
{
    int max_current = nums[0], max_global = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        max_current = max(nums[i], max_current + nums[i]);
        max_global = max(max_global, max_current);
    }
    return max_global;
}

int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Find the maximum subarray sum using Kadane's algorithm
    int max_kadane = kadane(nums);

    // Step 2: Find the total sum of the array
    int total_sum = accumulate(nums.begin(), nums.end(), 0);

    // Step 3: Use deque to find the maximum subarray sum for circular arrays
    vector<int> prefix_sum(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i)
    {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i % n];
    }

    // Deque to maintain the indices of the useful elements in the prefix_sum array
    deque<int> dq;
    int max_circular = INT_MIN;

    for (int i = 0; i <= 2 * n; ++i)
    {
        // Maintain elements in the deque to ensure it's within window of size n
        if (!dq.empty() && dq.front() < i - n)
        {
            dq.pop_front();
        }

        // If the deque is not empty, calculate the potential maximum sum
        if (!dq.empty())
        {
            max_circular = max(max_circular, prefix_sum[i] - prefix_sum[dq.front()]);
        }

        // Maintain a monotonically increasing deque
        while (!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // Step 4: Handle the special case where all elements are negative
    if (total_sum == max_kadane)
    {
        return max_kadane;
    }

    // Step 5: The result is the maximum of the linear maximum subarray sum and the circular maximum subarray sum
    return max(max_kadane, max_circular);
}

int main()
{
    vector<int> nums = {5, -3, 5};
    cout << "Maximum sum of circular subarray: " << maxSubarraySumCircular(nums) << endl;
    return 0;
}
