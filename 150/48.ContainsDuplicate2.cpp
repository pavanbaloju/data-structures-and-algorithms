#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = map.find(nums[i]);
        if (it != map.end())
        {
            if (abs(map[nums[i]] - i) <= k)
            {
                return true;
            }
            
        }
        map[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << containsNearbyDuplicate(nums, 3);
}