#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLenTLE(int target, vector<int> &nums)
{
    int count = nums.size();
    long long sum = 0;
    int size = 0, minSize = INT_MAX;
    for (int i = 0, j = i; i < count && j < count;)
    {
        sum += nums[j];
        if (sum >= target)
        {
            minSize = (++size) < minSize ? size : minSize;
            size = 0;
            sum = 0;
            i++;
            j = i;
        }
        else
        {
            j++;
            size++;
        }
    }
    return minSize != INT_MAX ? minSize : 0;
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
    ;
    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, nums2) << endl;
    return 0;
}