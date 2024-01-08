#include <iostream>
#include <vector>
using namespace std;


bool canJump(vector<int> &nums)
{
    int maxReach = 0;
    for (int idx = 0; idx < nums.size(); idx++)
    {
        if (maxReach < idx)
            return false;
        maxReach = max(maxReach, idx + nums[idx]);
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 2, 1, 1, 4};
    cout << canJump(nums);
    return 0;
}