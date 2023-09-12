#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> map;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;
        nums.push_back(val);
        map[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;
        int last = nums.back();
        map[last] = map[val];
        nums[map[val]] = last;
        nums.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

int main()
{
    RandomizedSet randomizedSet;
    randomizedSet.insert(1);   // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet.remove(2);   // Returns false as 2 does not exist in the set.
    randomizedSet.insert(2);   // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet.remove(1);   // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.insert(2);   // 2 was already in the set, so return false.
    randomizedSet.getRandom();
    return 0;
}