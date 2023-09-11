#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// using hashset
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> hashset;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hashset.count(nums[i]))
            return true;
        hashset.insert(nums[i]);
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums);
}