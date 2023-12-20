#include <iostream>
#include <vector>
using namespace std;
//Greedy problem
bool canJump2(vector<int> &nums)
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
bool canJump(vector<int> nums)
{
    int goal = nums.size() - 1;
    for (int i = goal - 1; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
        {
            goal = i;
        }
    }
    return goal == 0;
}

int main()
{
    vector<int> nums = {3, 2, 1, 1, 4};
    cout << canJump(nums);
    return 0;
}