#include <iostream>
#include <vector>
using namespace std;

int maxProductSubset(vector<int> nums)
{
    int N = nums.size();
    if (N == 1)
        return nums[0];

    int neg = 0, pos = 0, zer = 0;
    int maxNeg = INT_MIN;
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

        product *= n;
    }

    if (zer == N)
        return 0;

    if (neg % 2)
    {
        if (neg == 1 && zer > 0 && zer + neg == N)
        {
            return 0;
        }
        return product / maxNeg;
    }

    return product;
}

int main()
{
    vector<int> nums = {-1, -1, -2, 4, 3, 0};
    cout << maxProductSubset(nums) << endl;
    return 0;
}
