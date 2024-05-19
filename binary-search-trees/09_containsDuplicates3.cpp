#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    multiset<int> kSizeSet;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = kSizeSet.lower_bound((long)nums[i] - valueDiff);
        cout << *it << " ";
        if (it != kSizeSet.end() && abs(*it - nums[i]) <= valueDiff)
        {
            return true;
        }
        kSizeSet.insert(nums[i]);
        if (i >= indexDiff)
            kSizeSet.erase(kSizeSet.find(nums[i - indexDiff]));
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << containsNearbyAlmostDuplicate(nums, 3, 0);
    return 0;
}