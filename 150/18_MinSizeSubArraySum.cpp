#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int sum = 0;
    int len = INT_MAX;
    int i = 0, j = 0;

    while (i < nums.size() && j < nums.size())
    {
        if (sum + nums[j] < target)
        {
            sum += nums[j++];
        }
        else
        {
            len = min(len, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }
    return len == INT_MAX ? 0 : len;
}

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
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}