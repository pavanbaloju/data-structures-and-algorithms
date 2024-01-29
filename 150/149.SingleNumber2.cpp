#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int countOdd = 0;
        int countEven = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (1 << i & nums[j])
                countOdd++;
            else
                countEven++;
        }

        if (countOdd % 3)
            ans |= (1 << i);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 2, 1, 3, 3, 3};
    cout << singleNumber(nums) << endl;
}