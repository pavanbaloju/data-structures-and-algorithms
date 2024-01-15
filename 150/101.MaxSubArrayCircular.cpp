#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    int totalSum = 0, currMaxSum = 0, currMinSum = 0, globalMaxSum = INT_MIN, globalMinSum = INT_MAX;
    for (auto num : nums)
    {
        totalSum += num;
        currMaxSum += num;
        currMinSum += num;

        globalMaxSum = max(globalMaxSum, currMaxSum);
        currMaxSum = max(0, currMaxSum);

        globalMinSum = min(currMinSum, globalMinSum);
        currMinSum = min(0, currMinSum);
    }
    return (globalMaxSum < 0) ? globalMaxSum : max(globalMaxSum, totalSum - globalMinSum);
}

int main()
{
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums = {5, -3, 5};
    cout << maxSubarraySumCircular(nums) << endl;
    return 0;
}