#include <iostream>
#include <vector>
using namespace std;

int minProductSubset(vector<int> nums)
{
    int N = nums.size();
    if (N == 1)
        return nums[0];

    int neg = 0, pos = 0, zer = 0;
    int maxNeg = INT_MIN, minPos = INT_MAX;
    int product = 1;

    for (int i = 0; i < N; i++)
    {
        int n = nums[i];
        if (n == 0)
        {
            zer++;
            continue;
        }
        if (n < 0)
        {
            neg++;
            maxNeg = max(maxNeg, n);
        }
        if (n > 0)
        {
            pos++;
            minPos = min(minPos, n);
        }

        product *= n;
    }

    if (zer == N || (neg == 0 && zer > 0))
        return 0;

    if (neg == 0)
        return minPos;

    if (neg % 2 == 0 && neg != 0)
        return product / maxNeg;

    return product;
}

int main()
{
    vector<int> nums = {-1, -1, -2, 4, 3, 0};
    cout << minProductSubset(nums) << endl;
    return 0;
}
