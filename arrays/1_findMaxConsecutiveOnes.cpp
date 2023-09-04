#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxConsecutiveOnes = 0;
    int currentMaxConsecutiveOnes = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            maxConsecutiveOnes = maxConsecutiveOnes > currentMaxConsecutiveOnes ? maxConsecutiveOnes : currentMaxConsecutiveOnes;
            currentMaxConsecutiveOnes = 0;
        }
        else
        {
            currentMaxConsecutiveOnes++;
        }
    }

    return maxConsecutiveOnes > currentMaxConsecutiveOnes ? maxConsecutiveOnes : currentMaxConsecutiveOnes;
    ;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 0};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}