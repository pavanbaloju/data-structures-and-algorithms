#include <iostream>
#include <vector>
using namespace std;
// Greedy problem

int minJumps(vector<int> &nums)
{
    int jumps = 0;
    int left = 0, right = 0;
    while (right < nums.size() - 1)
    {
        int farthest = 0;
        for (int i = left; i <= right; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        left = right + 1;
        right = farthest;
        jumps++;
    }

    return jumps;
}

int main()
{
    vector<int> nums = {3, 2, 1, 1, 4};
    cout << minJumps(nums);
    return 0;
}